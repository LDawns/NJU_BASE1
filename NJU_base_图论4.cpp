#include <iostream>
#include <stack>
#include <algorithm>
#include <queue>
using namespace std;
const int maxe = 51000;
const int maxn = 21000;
int head[maxn];
int edgecount = 0;
int T;
stack <int> s;
bool instack[maxn];
bool done[maxn];
//链式前向星是真的好用
//这些mong男是真的太他娘有魅力了hhh
struct EDGE
{
	int u, v, w, next;
	EDGE() {};
	EDGE(int _u,int _v,int _d,int _next)
	{
		u = _u; v = _v; w = _d; next = _next;
	}
}edge[maxe];
void addedge(int u, int v, int w)
{
	edge[edgecount] = EDGE(u, v, w, head[u]);
	head[u] = edgecount++;
}
void deledge(int u, int v)//把w置为-1，嘛，反正空间不重要嘛。
{
	int e = head[u];
	while (edge[e].v != v)
		e = edge[e].next;
	edge[e].w = -1;
}
bool findway(int u, int v)//试一试bfs，嘻嘻嘻//不行，不好保存边的情况，也就不好删边//还是得用dfs，晚上再说吧
{
	queue<int>q;
	bool qdone[maxn];
	memset(qdone, false, sizeof(qdone));
	q.push(u);
	while (!q.empty())
	{
		int qu = q.front();
		qdone[qu] = false;
		q.pop();
		for (int e = head[qu]; e != -1; e = edge[e].next)
		{
			int qv = edge[e].v;
			if (qv == v && edge[e].w)
				return true;
			else if (!qdone[qv])
				q.push(qv);
		}
	}
	return false;
}
//我就知道dfs的参数超多
//感觉栈会炸啊。。
//这群mong男从来不害怕存储的问题的吗（摔
void Tarjan(int u, int *dfn, int *low, int &sccCount, int &dfnCount, int *sccID)
{
	dfn[u] = low[u] = dfnCount++;													//这边差点给我写错了orz，还是跑步的时候想了半天想岔气了才想出来的
	s.push(u); instack[u] = true; done[u] = true;
	for (int e = head[u]; e != -1; e = edge[e].next)
	{
		int v = edge[e].v;
		if (instack[v])low[u] = min(low[u], dfn[v]);
		else 
		{
			Tarjan(v, dfn, low, sccCount, dfnCount, sccID);
			low[u] = min(low[v], low[u]);
		}
	}
	if (dfn[u] == low[u])
	{
		while (s.top())
		{
			int t = s.top();
			s.pop();
			sccID[t] = sccCount;
			if (t == u)
				break;
		}
		sccCount++;
	}
}
bool subCycle()
{

}
int main()
{
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		bool result = true;
		memset(done, false, sizeof(done));
		memset(head, -1, sizeof(head));
		memset(instack, false, sizeof(instack));
		edgecount = 0;
		int dfn[maxn]; int low[maxn]; int sccID[maxn];
		int sccCount=0;
		int dfnCount=0;
		int n; cin >> n;
		int a, b;
		while ((cin >> a >> b) && (a != 0 || b != 0))
		{
			addedge(a, b, 1);
		}
		Tarjan(i, dfn, low, sccCount, dfnCount, sccID);
		for (int i = 0; i < n; i++)
			if (!done[i])result = false;
		if (sccCount > 1)result = false;
		if (!result)
		{
			cout << "NO" << '\n';
			continue;
		}

	}
}