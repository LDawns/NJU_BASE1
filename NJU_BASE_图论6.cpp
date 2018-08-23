//输出每个标号的重量赋值情形
//无解输出-1
//失算了，应该用结构数组的。
//LDawn的想法：1到n每个点依次确定他们的所有父节点，在安排节点时检查是否有父节点尚未进来，若有，则空出位置；（如果在讯在的过程中发现已经进栈的元素，说明存在环，return false）
//优化算法：每次处理一个点到每次处理一个连通分支
//思路是这样的，既然要使得i最小，那么也就意味着i所在的连通分支同样确立了他们的位置，对连通分支内部再取小的小大的大即可完成考验
//就是贪心的问题嘛，快打快打！
//方法2：先插进去，该位置有人，检查它的父节点是否为自己，若是，则占据该节点，使该节点之后的元素全部后移；若不是接着往下搜索，并重复此流程
//方法三：拓扑
//方法四：差分约束
//爆炸式兴奋，方法一成功！
//好吧，会有数组越界。。这个等等再说啊，下一题

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