//输出每个标号的重量赋值情形
//无解输出-1
//失算了，应该用结构数组的。
//LDawn的想法：1到n每个点依次确定他们的所有父节点，在安排节点时检查是否有父节点尚未进来，若有，则空出位置；（如果在讯在的过程中发现已经进栈的元素，说明存在环，return false）
//就是贪心的问题嘛，快打快打！
//方法2：先插进去，该位置有人，检查它的父节点是否为自己，若是，则占据该节点，使该节点之后的元素全部后移；若不是接着往下搜索，并重复此流程
//方法三：拓扑
//方法四：差分约束
//爆炸式兴奋，方法一成功！

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