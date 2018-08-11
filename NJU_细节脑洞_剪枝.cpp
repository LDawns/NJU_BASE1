#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<functional>
#define MAX 65
using namespace std;

int a[MAX];
int used[MAX];
int n, l, last;


bool dfs(int remain, int sum)  //remain表示剩余木棒数，sum表示要拼成一根棍子还需要的长度
{
	if (remain == 0 && sum == 0)
		return true;
	if (sum == 0)
		sum = l;
	int start = 0;
	if (sum != l)
		start = last + 1;                  //剪枝2
	for (int i = start; i<n; i++)
	{
		if (!used[i] && a[i] <= sum)
		{
			if (i>0)
			{
				if (!used[i - 1] && a[i - 1] == a[i])   //剪枝1
					continue;
			}
			used[i] = 1;
			last = i;
			if (dfs(remain - 1, sum - a[i]))
				return true;
			else
			{
				used[i] = 0;
				if (sum == l || a[i] == sum)     //剪枝3,4
					return false;
			}
		}
	}
	return false;
}



int main()
{
	int i;
	while (1)
	{
		cin >> n;
		if (n == 0)
			break;
		int total = 0;
		for (i = 0; i<n; i++)
		{
			scanf("%d", &a[i]);
			total += a[i];
		}
		memset(used, 0, sizeof(used));
		sort(a, a + n, greater<int>());
		for (l = a[0]; l <= total / 2; l++)
		{
			if (total%l)   continue;				//如果不能是总数的约数，那么必定不行！
			if (dfs(n, l))
			{
				cout << l << endl;
				break;
			}
		}
		if (l>total / 2)							//超过总数的一半，必定是总数。
			cout << total << endl;
	}
}