#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int INF = 1000000000;
const int maxe = 1000000000;
const int maxn = 1000000000;
struct Edge
{
	int from; int to; int cap; int flow; int next;
	Edge(int u, int v, int c, int f,int n) :from(u), to(v), cap(c), flow(f),next(n) {}
}edge[maxe];
struct EK
{
	int edgecount = 0;
	int a[maxn];
	int p[maxn];
	int head[maxn];

	void init()
	{
		memset(head, -1, sizeof(head));
		edgecount = 0;
	}

	void addedge(int u, int v,int c,int f)					//��ʽǰ����//����vectorʵ�֣�������һЩ�鷳�������ҵ�������Ч�ʲ��ߣ����Ǿ�û���������ɵ��Ҹ�
	{
		edge[edgecount] = Edge(u, v, c, 0,head[u]);
		head[u] = edgecount++;
		edge[edgecount++] = Edge(v, u, 0, 0,head[v]);
		head[v] = edgecount++;
	}

	int Maxflow(int s, int t)
	{
		int flow = 0;
		while (true)
		{
			memset(a, 0, sizeof(a));
			queue<int> q;
			q.push(s);
			a[s] = INF;
			while (!q.empty())
			{
				int u = q.front(); q.pop();
				for (int e = head[u]; e != -1; e = edge[e].next)
				{
					int v = edge[e].to;
					int f = edge[e].flow;
					int c = edge[e].cap;
					if (!a[v] && (c > f))
					{
						p[v] = e;
						a[v] = min(a[u], c - f);
						q.push(v);
					}
				}
				if (a[t])break;
			}
			if (!a[t])break;
			for (int v = t; v != s; v = edge[p[v]].from)
			{
				edge[p[v]].flow += a[t];
				edge[p[v]^1].flow -= a[t];			//�෴�ߣ�����0��1��2��3��ǰ�涨���������
			}
			flow += a[t];
		}
		return flow;
	}
};