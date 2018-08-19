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
//��ʽǰ��������ĺ���
//��Щmong�������̫������������hhh
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
void deledge(int u, int v)//��w��Ϊ-1��������ռ䲻��Ҫ�
{
	int e = head[u];
	while (edge[e].v != v)
		e = edge[e].next;
	edge[e].w = -1;
}
bool findway(int u, int v)//��һ��bfs��������//���У����ñ���ߵ������Ҳ�Ͳ���ɾ��//���ǵ���dfs��������˵��
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
//�Ҿ�֪��dfs�Ĳ�������
//�о�ջ��ը������
//��Ⱥmong�д��������´洢���������ˤ
void Tarjan(int u, int *dfn, int *low, int &sccCount, int &dfnCount, int *sccID)
{
	dfn[u] = low[u] = dfnCount++;													//��߲�����д����orz�������ܲ���ʱ�����˰���������˲��������
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