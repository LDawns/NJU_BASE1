//���ÿ����ŵ�������ֵ����
//�޽����-1
//��˼����뷨��1��nÿ��������ȷ�����ǵ����и��ڵ㣬�ڰ��Žڵ�ʱ����Ƿ��и��ڵ���δ���������У���ճ�λ�ã��������Ѷ�ڵĹ����з����Ѿ���ջ��Ԫ�أ�˵�����ڻ���return false��
//����̰�ĵ�����������
//����2���Ȳ��ȥ����λ�����ˣ�������ĸ��ڵ��Ƿ�Ϊ�Լ������ǣ���ռ�ݸýڵ㣬ʹ�ýڵ�֮���Ԫ��ȫ�����ƣ������ǽ����������������ظ�������
//������������
//�����ģ����Լ��
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
	if(ans!=-1)
	fan[ans] += fan[u] + 1;
	return true;
}
int main()
{
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		bool result=true;
		int out[maxn] = {};
		cin >> N >> M;
		memset(vis, false, sizeof(vis));
		memset(fan, 0, sizeof(fan));
		memset(out, 0, sizeof(out));
		memset(ler, false, sizeof(ler));
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
			out[n] = i;
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