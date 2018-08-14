#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define N 60
#define INF 100000000
int n, m;
int vis[N][2];
int d[N][2], dp[N][2];
int ma[N][N];
void init()
{
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= n; j++)
			ma[i][j] = INF;
}
void djstl(int s, int e)
{
	for (int i = 0; i<n; i++)
		d[i][0] = d[i][1] = INF;
	memset(vis, 0, sizeof(vis));
	memset(dp, 0, sizeof(dp));
	d[s][0] = 0;
	dp[s][0] = 1;
	while (1)
	{
		int maxn = INF;
		int v, flag;
		for (int j = 0; j<n; j++)
		{
			if (!vis[j][0] && maxn>d[j][0])
			{
				maxn = d[j][0];
				v = j; flag = 0;
			}
			else if (!vis[j][1] && maxn>d[j][1])
			{
				maxn = d[j][1];
				v = j; flag = 1;
			}
		}
		if (v == e && flag == 1) break;
		if (maxn == INF) break;
		vis[v][flag] = 1;
		for (int j = 0; j<n; j++)
		{
			if (!vis[j][0] && d[v][flag] + ma[v][j]<d[j][0])
			{
				d[j][1] = d[j][0];
				d[j][0] = d[v][flag] + ma[v][j];
				dp[j][1] = dp[j][0];
				dp[j][0] = dp[v][flag];
			}
			else if (!vis[j][0] && d[v][flag] + ma[v][j] == d[j][0])
				dp[j][0] += dp[v][flag];
			else if (!vis[j][1] && d[v][flag] + ma[v][j]<d[j][1])
			{
				d[j][1] = d[v][flag] + ma[v][j];
				dp[j][1] = dp[v][flag];
			}
			else if (!vis[j][1] && d[v][flag] + ma[v][j] == d[j][1])
				dp[j][1] += dp[v][flag];
		}
	}
}

int main()
{
	int s, e;
	int x, y, w;
	while (~scanf("%d %d %d %d", &n, &m, &s, &e))
	{
		init();
		for (int i = 0; i<m; i++)
		{
			scanf("%d %d %d", &x, &y, &w);
			ma[x][y] = w;
		}
		djstl(s, e);
		printf("%d %d\n", d[e][1], dp[e][1]);
	}
	return 0;
}
