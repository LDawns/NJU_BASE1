#include <iostream>
#include <queue>

using namespace std;
const int maxn = 50;
const int maxnn = 100;
int N, M, S, E;
int head[maxnn];
int edgecount = 0;
struct EDGE
{
	int u, v, w, next;
	EDGE() {};
	EDGE(int _u,int _v,int _w,int _next)
	{
		u = _u;
		v = _v;
		w = _w;
		next = _next;
	}
}edge[maxn];
void addEdge(int u, int v, int w)
{
	edge[edgecount] = EDGE(u, v, w, head[u]);
	head[u] = edgecount;
	edgecount++;
}
int main()
{
	memset(head, -1, sizeof(head));
	cin >> N >> M >> S >> E;
	for (int i = 0; i < M; i++)
	{
		int x, y, w;
		cin >> x >> y >> w;
		addEdge(x, y, w);
	}

	return 0;
}