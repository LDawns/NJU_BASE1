//�����Լ�ʵ����һ��ͼ�ۻ������о����
#include <iostream>
#include <queue>
#include <functional>//��Ϊ����greater<int>()
using namespace std;
const int maxn = 50;
const int maxnn = 10000;
const int inf = 1000000000;
int N, M, S, E;
int head[maxnn];
int edgecount = 0;
int visitcount[maxnn];
int d[maxnn];
int sd[maxnn]; 
int sdcount[maxnn];
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
	priority_queue<pii, greater<int>> q;
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
	}	
	//pii(s, d[s]);//��˵���ǲ��Ƕ���ġ���
	q.push((d[s], s));
	while (!q.empty())
	{
		int dist, u;
		(dist, u) = q.top();//����Ҳ��orz��C++�Ĵ������ǰ�����
		q.pop();
		done[u] = false;
		if (++ visitcount[u] > N)return false;
		for (int e = head[u]; e != -1; e = edge[e].next)
		{
			int v = edge[e].v;
			int w = edge[e].w;
			if (w + dist <= d[v])//����Ҫ��Ҫ�Ӹ����ںţ�������ĵĵ�ȷȷ�Ǵζ�·��
			{
				d[v] = w + dist;
			}
			else if( w + dist - d[v] < sd[v] )
			{
				sd[v] = w + dist -d[v];
			}
			else if (w + dist == sd[v])
			{
				sdcount[v]++;
			}
			if (!done[v])
			{
				done[v] = true;
				q.push((d[v], v));
			}
		}
	}
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