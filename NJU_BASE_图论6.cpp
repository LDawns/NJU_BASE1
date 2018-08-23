//���ÿ����ŵ�������ֵ����
//�޽����-1
//ʧ���ˣ�Ӧ���ýṹ����ġ�
//LDawn���뷨��1��nÿ��������ȷ�����ǵ����и��ڵ㣬�ڰ��Žڵ�ʱ����Ƿ��и��ڵ���δ���������У���ճ�λ�ã��������Ѷ�ڵĹ����з����Ѿ���ջ��Ԫ�أ�˵�����ڻ���return false��
//����̰�ĵ�����������
//����2���Ȳ��ȥ����λ�����ˣ�������ĸ��ڵ��Ƿ�Ϊ�Լ������ǣ���ռ�ݸýڵ㣬ʹ�ýڵ�֮���Ԫ��ȫ�����ƣ������ǽ����������������ظ�������
//������������
//�����ģ����Լ��
//��ըʽ�˷ܣ�����һ�ɹ���

#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <stack>
using namespace std;
const int maxn = 210;
bool ler[maxn][maxn];
bool vis[maxn];
bool ins[maxn];
int fan[maxn];
int fa[maxn][maxn];
stack <int> s;
int T; int N, M;
bool dfs(int u,int ans)
{
	s.push(u);
	ins[u] = true;
	for (int i = 0; i < N; i++)
	{
		if (ler[i][u]) 
		{
			if (ins[i]||!dfs(i,u))
			{
				return false;
			}
		}
	}
	vis[u] = true;
	s.pop(); 
	if (ans != -1)
	{
		int num = fan[ans];
		for (int j = 0; fa[u][j] != -1; j++)
			fa[ans][j] = fa[u][j];
		fa[ans][num] = u;
		fan[ans] += fan[u] + 1;
	}
	return true;
}
void init()
{
	memset(fa, -1, sizeof(fa));
	memset(vis, false, sizeof(vis));
	memset(fan, 0, sizeof(fan));
	memset(ler, false, sizeof(ler));
}
int main()
{
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		bool result=true;
		int out[maxn] = {};
		cin >> N >> M;
		init();
		for (int i = 0; i < M; i++)
		{
			int a, b;
			cin >> a >> b;
			ler[a][b] = true;
		}
		for (int i = 1; i <= N; i++)
		{
			if (!vis[i])
			{
				vis[i] = true;
				memset(ins, false, sizeof(ins));
				if (!dfs(i,-1))
				{
					cout << "-1" << endl;
					result = false;
					break;
				}
				
			}
			int n = fan[i];
			while (out[n])
				n++;
			int facount = 0;
			int fanum = 0;
			for (int j = 0; j < n; j++)
			{
				for (int k = 0; fa[i][k]!=-1; k++)
				{
					fanum++;
					if (out[j] == fa[i][k])
						facount++;
				}
			}
			int sub = fanum - facount;
			while (out[n + sub])
				n++;
			out[n+sub] = i;
		}
		if (!result)continue;
		else
		{
			for (int i = 0; i < N; i++)
			{
				cout << out[i] << " ";
			}
			cout << endl;
		}
	}
	return 0;
}