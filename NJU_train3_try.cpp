//= =
//让数组保持递增
//这个是对的
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

int main()
{
	string snum;
	int n;
	while (cin >> snum >> n) 
	{
		vector<char> num;
		stringstream strm;
		strm.clear();
		strm << snum;
		char c;
		int i = 0;
		while (strm >> c)
		{
			num.push_back(c);
		}

		if (n >= num.size())
		{
			cout << "0" << endl;
			return 0;
		}

		int count = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < num.size() - 1; j++)
			{
				if (num[j] > num[j + 1])
				{
					num.erase(num.begin() + j);
					count++;
					break;
				}
			}
		}
		if (count < n)
		{
			for (int i = count; i < n; i++)
			{
				num.pop_back();
			}
		}
		strm.clear();
		snum.clear();
		for (int i = 0; i < num.size(); i++)
			snum += num[i];
		for (int i = 0; i < snum.length(); i++)
		{
			if (snum[i] != '0')
			{
				snum = snum.substr(i);
				break;
			}
			if (snum[snum.length() - 1] == '0')
			{
				snum.clear();
				snum += '0';
			}
		}
		cout << snum << endl;
	}
	return 0;
}
