#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
bool solve(int len, vector<int>data)
{
	while (!data.empty())
	{
		int tem = *data.end();
		data.pop_back();
		set<int>group = union_set(data);
		set<int>::const_iterator iter;
		for (iter = group.begin(); iter != group.end(); ++iter)
		{
			if (tem == len)break;
			if (tem + *iter == len)
			{
				while (true)
				{

				}
				break;
			}
		}
	}
	return true;
}
set<int> union_set(vector<int>data);
set<int> plus_n(vector<int>data, int n);
int main()
{
	int n = 0;
	while ((cin >> n) && n != 0)
	{
		int result = -1, r = 0, l = 0;
		vector <int> data;
		set <int> group;
		for (int i = 0; i < n; i++)
		{
			int tem;
			cin >> tem;
			data.push_back(tem);
			r += tem;
			//sdata.insert(tem);
		}
		sort(data.begin(), data.end());
		l = data[n - 1];
		for (int i = l; i <= r/2; i++)
		{
			if (r%i)continue;
			if (solve(i, data))
			{
				result = i; break;
			}
		}
		if (result == -1)result = r;
		cout << result << '\n';
	}

}
//返回n加法群
set<int> union_set(vector<int>data)
{
	set<int>result;
	for (int i = 1; i <= data.size(); i++)
	{
		set<int>tem=plus_n(data, i);
		set<int>::const_iterator iter;
		for (iter = tem.begin(); iter != tem.end(); ++iter)
		{
			result.insert(*iter);
		}
	}
	return result;
}
//返回整数n加法群
set<int> plus_n(vector<int>data,int n)
{
	set<int>result;
	if (n == 1)
	{
		for (int i = 0; i < data.size(); i++)
			result.insert(data[i]);
		return result;
	}
	else 
	{
		while (!data.empty())
		{
			int tem = data[0];
			data.erase(data.begin());
			set<int>ans = plus_n(data, n - 1);
			set<int>::const_iterator iter;
			for (iter = ans.begin(); iter != ans.end(); ++iter)
			{
				result.insert(tem + *iter);
			}
		}
	}
	return result;
}