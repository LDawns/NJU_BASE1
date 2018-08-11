#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#define Maxn 1010
#define Maxm Maxn*Maxn
#define inf 100000000
#define T 400
using namespace std;
int head[Maxn], vi[Maxn], col[Maxn], map[Maxn][Maxn], e, n, cnt[Maxn], dis[Maxn];
void init()
{
	memset(head, -1, sizeof(head));
	memset(vi, 0, sizeof(vi));
	memset(map, 0, sizeof(map));
	memset(col, -1, sizeof(col));
	e = 0;
}
struct Edge {
	int u, next, v, val;
}edge[Maxm];
void addedge(int u, int v)
{
	edge[e].u = u; edge[e].v = v; edge[e].next = head[u]; head[u] = e++;
	edge[e].v = u; edge[e].u = v; edge[e].next = head[v]; head[v] = e++;
}
void add(int u, int v, int val)
{
	edge[e].u = u, edge[e].v = v, edge[e].val = val, edge[e].next = head[u], head[u] = e++;
}
void find(int u, int c)
{
	int i, j, temp;
	vi[u] = 1;
	for (i = head[u]; i != -1; i = edge[i].next) {
		temp = edge[i].v;
		if (col[temp] == -1) {
			col[temp] = c;
			find(temp, c ^ 1);
		}
	}
}
int spfa()
{
	int i, j, v, u;
	queue<int> q;
	memset(cnt, 0, sizeof(cnt));
	memset(vi, 0, sizeof(vi));
	for (i = 0; i <= n; i++) {
		dis[i] = inf;
	}
	dis[0] = 0;
	q.push(0);
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		vi[u] = 0;
		for (i = head[u]; i != -1; i = edge[i].next) {
			v = edge[i].v;
			if (dis[v]>dis[u] + edge[i].val) {
				dis[v] = dis[u] + edge[i].val;
				cnt[v]++;
				if (cnt[v]>n) return 0;
				if (!vi[v]) {
					q.push(v);
					vi[v] = 1;
				}
			}
		}
	}
	return 1;
}
int solve()
{
	int i, j, u, v;
	for (i = 1; i <= n; i++)  if (!vi[i]) find(i, 0);
	for (i = 0; i<e; i++) if (col[edge[i].u] == col[edge[i].v]) return 0;
	memset(head, -1, sizeof(head));
	e = 0;
	for (i = 1; i <= n; i++) {
		for (j = i + 1; j <= n; j++) {
			if (!map[i][j] && col[i] == col[j]) continue;
			u = i, v = j;
			if (col[u] == 0)
				swap(u, v);
			if (map[u][v])
				add(u, v, -T);
			else
				add(v, u, T - 1);
		}
		if (col[i] == 0) {
			add(i, 0, T - 1);
			add(0, i, 0);
		}
		else {
			add(0, i, T - 1);
			add(i, 0, 0);
		}
	}
	return spfa();
}
int main()
{
	int t, i, j;
	char str[310];
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		init();
		for (i = 1; i <= n; i++) {
			scanf("%s", &str);
			for (j = 0; j<n; j++) {
				if (str[j] == '1' && !map[i][j + 1]) {
					addedge(i, j + 1);
					map[i][j + 1] = map[j + 1][i] = 1;
				}
			}
		}
		if (!solve())
			printf("No\n");
		else
			printf("Yes\n");
	}
	return 0;
}