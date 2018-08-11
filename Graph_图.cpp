#include <iostream>
#include <string>
#include <cstdio>
using namespace std;
const int maxn = 100 + 5;
int idx[maxn][maxn];
char pic[maxn][maxn];
int m, n;
void dfs(int r, int c,int num)							//算‘@’连通分支的总数的算法
{
	if (r < 0 || r >= m || c < 0 || c >= num)return;	//边界
	if (idx[r][c] > 0 || pic[r][c] != '@')return;		//算法
	idx[r][c] = num;
	for(int i=-1;i<=1;i++)
		for (int j = -1; j <= 1; j++)					//相邻八个点
		{
			if (i == 0 && j == 0)continue;
			else dfs(r + i, c + j, num);
		}
}
