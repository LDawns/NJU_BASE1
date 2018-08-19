//终于自己实现了一波图论基础，感觉不差。
#include <iostream>
#include <queue>
#include <functional>//因为用了greater<int>
using namespace std;
const int maxn = 100000000;
const int maxnn = 10000;
const int inf = 1000000000;
int N, M, S, E;
int head[maxnn];
int edgecount = 0;
int visitcount[maxnn];
int d[maxnn];
int sd[maxnn]; 
int sdcount[maxnn], dcount[maxnn];
typedef pair<int, int> pii;
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
bool spfa(int s)
{
	priority_queue< pii, vector<pii>, greater<pii> > q;//骚操作。虽然我不懂原理就是了orz
	bool done[maxnn];
	for (int i = 0; i < N; i++)
	{
		if (i != s)
		{
			sd[i] = inf;
			d[i] = inf;
		}
		else
		{
			sd[i] = inf;
			d[i] = 0;
		}
		done[i] = false;
		visitcount[i] = 0;
		sdcount[i] = 0;
		dcount[i] = 0;
	}	
	q.push(pii(d[s],s));
	while (!q.empty())
	{
		pii pu;
		int dist, u;
		pu = q.top();//这样也行orz，C++的处理真是棒极了
		dist = pu.first; u = pu.second;
		q.pop();
		done[u] = false;
		if (++ visitcount[u] > N)return false;
		for (int e = head[u]; e != -1; e = edge[e].next)
		{
			int v = edge[e].v;
			int w = edge[e].w;
			if (w + dist <= d[v])//考虑要不要加个等于号，让下面的的的确确是次短路？
			{
				if (w + dist != d[v])
				{
					sd[v] = d[v] - w - dist;
					sdcount[v] = dcount[v];
					dcount[v] = 1;
				}
				else  dcount[v]++;
				d[v] = w + dist;
			}
			else if( w + dist - d[v] < sd[v] )
			{
				sd[v] = w + dist -d[v];
				sdcount[v] = 1;
			}
			else if (w + dist - d[v] == sd[v])
			{
				sdcount[v]++;
			}
			if (!done[v])
			{
				done[v] = true;
				q.push(pii(d[v], v));
			}
		}
	}
	return true;
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
	spfa(S);
	int shortest = d[E];
	int min = inf;
	int rcount = 0;
	for (int i = 0; i < N; i++)
	{
		if (sd[i] < min)
		{
			min = sd[i];
			rcount = 0;
			rcount += sdcount[i];
		}
		else if (sd[i] == min)
		{
			rcount += sdcount[i];
		}
	}
	int sec = d[E] + min;
	cout << sec << " " << rcount << '\n';
	return 0;
}