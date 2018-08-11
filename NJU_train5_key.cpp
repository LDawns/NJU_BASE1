#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXNUM 50005

using namespace std;
//father:存储的是节点的父节点的下标，dist存储的是相对于父节点的距离
int father[MAXNUM], dist[MAXNUM];
int n, m;

int find_father(int a)
{
	if (father[a] == a)return a;
	int tem = father[a];
	father[a] = find_father(father[a]);
	dist[a] += dist[tem];
	return father[a];
}

void union_set(int a, int b, int x)
{
	int ra = find_father(a);
	int rb = find_father(b);
	father[rb] = ra;
	dist[rb] = dist[a] + x - dist[b];
}
int main()
{
	int a, b, ra, rb, x, conflics;
	while (scanf("%d%d", &n, &m) != EOF)
	{
		memset(dist, 0, sizeof(dist));
		for (int i = 0; i <= n; i++)
			father[i] = i;
		conflics = 0;
		for (int i = 0; i<m; i++)
		{
			scanf("%d%d%d", &a, &b, &x);
			find_father(a);//ra = find_father(a);
			find_father(b);//rb = find_father(b);
			if (father[a]==father[b])//ra==rb
			{
				if (dist[b] - dist[a] != x)conflics++;
			}
			else union_set(a, b, x);
		}
		printf("%d\n", conflics);
	}
	return 0;
}