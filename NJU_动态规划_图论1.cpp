//对所有的i，|ai|<T
//并且对它的相邻点j来说，|ai-aj|>=T
//并且如果|ai-aj|>=T，那么它们必定是相邻点
//即（vi.vj)属于E，当且仅当|ai-aj|>=T
//若有奇数个点构成的环，一定不行
//正与正不相邻，负与负不相邻
//N字为基本构造，二字为判否标准
//等等一周后再回来重写吧？
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int TC;
bool near[300][300];
bool done[300];
//看了一些大佬的代码，改善了以下递归的结构，简单的来说就是
//dfs把每一个点都看成是根节点
//ok
//还是蛮有成就感的hhh
bool cycle(int ans, int now, int n, vector<int>line)
{
	done[now] = true;
	line.push_back(now);
	int len = line.size();
	for (int j = 0; j < len-1; j++)
	{
		if (line[j] != ans)
		{
			if (line[j] == now)
				if ((len - j - 1) % 2)
					return true;
				else
					return false;
		}
	}
	for (int j = 0; j < n; j++)
	{
		if (j != ans&&near[now][j] && cycle(now, j, n, line))
			return true;
	}
	line.clear();
	return false;
}
bool solve(int n)
{
	vector<int>line;
	for (int i = 0; i < n; i++)
		if (!done[i] && cycle(i, 0, n, line))
			return false;
	bool result=true;
	return result;
}
int main()
{
	cin >> TC;
	for (int i = 0; i < TC; i++)
	{
		int n; cin >> n;
		int T;
		for (int i=0; i < n; i++)
		{
			string tem;
			cin >> tem;
			for (int j = 0; j < n; j++)
				near[i][j] = tem[j]-'0';
		}
		memset(done, false, sizeof(done));
		bool result = solve(n);
		
		
		
		if (result)cout << "Yes" << '\n';
		else cout << "No" << '\n';
	}
	return 0;
}