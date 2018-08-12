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
			find(temp, c ^ 1);						//这些dalao就喜欢按位操作，什么鬼代码风格哦，要是我就if(c==0)c=1;else c=0;你说多好，就是效率略低嘛
		}
	}
}
//是这个道理了orz
//每次取出队首结点u，并且枚举从u出发的所有边(u, v)，如果d[u] + w(u, v) < d[v]，则更新d[v] = d[u] + w(u, v)，
//然后判断v点在不在队列中，如果不在就将v点放入队尾。这样不断从队列中取出结点来进行松弛操作，直至队列空为止。 
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
				if (cnt[v]>n) return 0;										//走进了负环，不存在的
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
	for (i = 1; i <= n; i++)  if (!vi[i]) find(i, 0);						//分配正负
	for (i = 0; i<e; i++) if (col[edge[i].u] == col[edge[i].v]) return 0;	//如果相邻正负号相同，则是奇环，返回false
	memset(head, -1, sizeof(head));
	e = 0;
	for (i = 1; i <= n; i++) {
		for (j = i + 1; j <= n; j++) {
			if (!map[i][j] && col[i] == col[j]) continue;					//这些个dalao就喜欢乱占空间。。。从零开始不好吗针是。。
			u = i, v = j;
			if (col[u] == 0)
				swap(u, v);
			if (map[u][v])
				add(u, v, -T);
			else
				add(v, u, T - 1);
		}
		if (col[i] == 0) {													//约束其为负，并且其绝对值小于T
			add(i, 0, T - 1);
			add(0, i, 0);
		}
		else {																//约束其为正，并且其绝对值小于T
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