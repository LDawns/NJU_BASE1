//��ͨ����ͼ
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define inf 0x7fffffff

int map[505][505], dis[505], dise[505];//dise[]��ǰ�� 
int t, n, m, u, v, w;
bool uni;
int mst;//��С�������Ĵ�С 
struct Edge//��¼��С�������ı� 
{
	int u, v, w;
}edge[505];

void prim()
{
	uni = true;
	mst = 0;
	int k = 0;
	int now = 1;
	int min_node;
	int min_edge;
	for (int i = 1; i <= n; i++) dis[i] = inf;
	for (int i = 1; i<n; i++)//��һ��prim�����С������ 
	{
		dis[now] = -1;
		min_edge = inf;
		for (int j = 1; j <= n; j++)
		{
			if (now != j && dis[j] >= 0)
			{
				if (map[now][j]<dis[j])
				{
					dis[j] = map[now][j];
					dise[j] = now;//��¼ǰ�� 
				}
				if (dis[j] <= min_edge)
				{
					min_edge = dis[j];
					min_node = j;
				}
			}
		}
		edge[i].u = min_node;
		edge[i].v = dise[min_node];
		edge[i].w = map[edge[i].u][edge[i].v];//��¼�� 
		now = min_node;
		mst += min_edge;
	}
	for (int k = 1; k<n; k++)//�ڶ���prim 
	{
		int sec_mst = 0;
		bool flag = 1;
		map[edge[k].u][edge[k].v] = map[edge[k].v][edge[k].u] = inf;//ɾ�� 
		if (k>1)
			map[edge[k - 1].u][edge[k - 1].v] = map[edge[k - 1].v][edge[k - 1].u] = edge[k - 1].w;//�ָ��� 
		for (int i = 1; i <= n; i++) dis[i] = inf;
		for (int i = 1; i<n; i++)
		{
			dis[now] = -1;
			min_edge = inf;
			for (int j = 1; j <= n; j++)
			{
				if (now != j && dis[j] >= 0)
				{
					dis[j] = min(dis[j], map[now][j]);
					if (dis[j] <= min_edge)
					{
						min_edge = dis[j];
						min_node = j;
					}
				}
			}
			if (min_edge == inf)//Ҫ�ǵ��ж��Ƿ���ڴ�С������ 
			{
				flag = 0;
				break;
			}
			now = min_node;
			sec_mst += min_edge;
		}
		if (flag&&sec_mst == mst)
		{
			uni = false;
			return;
		}
	}
}
int main()
{
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				map[i][j] = inf;
		for (int i = 1; i <= m; i++)
		{
			scanf("%d%d%d", &u, &v, &w);
			map[u][v] = map[v][u] = w;
		}
		prim();
		if (!uni) printf("Not Unique!\n");
		else printf("%d\n", mst);
	}
	return 0;
}