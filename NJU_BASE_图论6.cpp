//���ÿ����ŵ�������ֵ����
//�޽����-1
//ʧ���ˣ�Ӧ���ýṹ����ġ�
//LDawn���뷨��1��nÿ��������ȷ�����ǵ����и��ڵ㣬�ڰ��Žڵ�ʱ����Ƿ��и��ڵ���δ���������У���ճ�λ�ã��������Ѷ�ڵĹ����з����Ѿ���ջ��Ԫ�أ�˵�����ڻ���return false��
//�Ż��㷨��ÿ�δ���һ���㵽ÿ�δ���һ����ͨ��֧
//˼·�������ģ���ȻҪʹ��i��С����ôҲ����ζ��i���ڵ���ͨ��֧ͬ��ȷ�������ǵ�λ�ã�����ͨ��֧�ڲ���ȡС��С��Ĵ󼴿���ɿ���
//����̰�ĵ�����������
//����2���Ȳ��ȥ����λ�����ˣ�������ĸ��ڵ��Ƿ�Ϊ�Լ������ǣ���ռ�ݸýڵ㣬ʹ�ýڵ�֮���Ԫ��ȫ�����ƣ������ǽ����������������ظ�������
//������������
//�����ģ����Լ��
//��ըʽ�˷ܣ�����һ�ɹ���
//�ðɣ���������Խ�硣������ȵ���˵������һ��

#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;
const int maxn = 410;
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
	for (int i = 1; i <= N; i++)
	{
		if (ler[i][u]) 
		{
			if (!ins[i] && vis[i])
			{
				int num = fan[u];
				for (int j = 0; fa[i][j] != -1; num++, j++)
					fa[u][num] = fa[i][j];
				fa[u][num] = i;
				fan[u] = num + 1;

				continue;
			}
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
		for (int j = 0; fa[u][j] != -1; j++,num++)
			fa[ans][num] = fa[u][j];
		fa[ans][num] = u;
		fan[ans] = num + 1;
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
		int out[maxn];
		memset(out, 0, sizeof(out));
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
				int n = 0;
				while (out[n])
					n++;
				int facount = 0;
				int fanum = fan[i];
				sort(fa[i], fa[i] + fanum);
				for (int j = 0; j < n; j++)
				{
					for (int k = 0; fa[i][k] != -1; k++)
					{
						if (out[j] == fa[i][k])
							facount++;
					}
				}
				int sub = fan[i] - facount;
				for (int j = 0; j < sub; j++)
					out[n + j] = fa[i][j];
				out[n + sub] = i;
			}
		}
		if (!result)continue;
		else
		{
			int rout[maxn];
			for (int i = 0; i <= N; i++)	rout[out[i]] = i+1 ;
			for (int i = 1; i <= N; i++)cout << rout[i] << " ";
			cout << endl;
		}
	}

	return 0;
}