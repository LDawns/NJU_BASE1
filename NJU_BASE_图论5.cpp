//解决一个古老的3x3移方块小游戏
#include <iostream>
#include <queue>
#include <string>
#include <sstream>
using namespace std;
stringstream strm;

const int maxe = 100000000;
const int maxn = 362880;
const int INF = 1000000000;
int edgecount = 0;
int head[maxn];
int fac[] = { 1,1,2,6,24,120,720,5040,40320,362880 };
vector <char> way[maxn];
bool inq[maxn];
struct EDGE
{
	int u, v, next; char dir;
	EDGE() {};
	EDGE(int _u, int _v, int _next,char _dir)
	{
		u = _u; v = _v; next = _next; dir = _dir;
	}
}edge[maxe];
void addedge(int u, int v,char dir)
{
	edge[edgecount] = EDGE(u, v, head[u],dir);
	head[u] = edgecount++;
}
void disc(int s)
{
	queue<int>q;
	q.push(s);
	inq[s] = true;
	
	while (!q.empty())
	{
		int u = q.front();
		q.pop(); inq[u] = false;
		for (int e = head[u]; e != -1; e = edge[e].next)
		{
			int v = edge[e].v;
			int wv = way[v].size();
			int wu = way[u].size();
			if (wv)
			{
				if (wv > wu + 1)
				{
					way[v] = way[u];
					way[v].push_back(edge[e].dir);
					if (!inq[v])
					{
						inq[v] = true;
						q.push(v);
					}
				}
			}
			else
			{
				way[v] = way[u];
				way[v].push_back(edge[e].dir);
				if (!inq[v])
				{
					inq[v] = true;
					q.push(v);
				}
			}
			
		}
	}
}
int * ana(int x)
{
	int n = 9;
	int m = 9;
	int result[9];
	vector<int> v;  // 存放当前可选数
	vector<int> a;  // 所求排列组合
	for (int i = 1; i <= n; i++)
		v.push_back(i);
	for (int i = m; i >= 1; i--)
	{
		int r = x % fac[i - 1];
		int t = x / fac[i - 1];
		x = r;
		sort(v.begin(), v.end());// 从小到大排序
		a.push_back(v[t]);      // 剩余数里第t+1个数为当前位
		v.erase(v.begin() + t);   // 移除选做当前位的数
	}
	for (int i = 0; i < 9; i++)
	{
		result[i] = a[i];
	}
	return result;
}
int kt(int *s)
{
	int sum = 0;
	for (int i = 0; i<9; i++)
	{
		int num = 0;
		for (int j = i + 1; j<9; j++)
			if (s[j]<s[i])num++;
		sum += (num*fac[8 - i]);
	}
	return sum + 1;
}
void build()//不能接受的算法！！！//啊啊那些mong男是怎么做到的？？？
{
	for (int i = 0; i < maxn; i++)
	{
		int *board = ana(i);
		int white;
		for (int j = 0; j < 9; j++)
			if (board[j] == 9)
				white = j;
		int r = white % 3;
		if ((white + 1) % 3 == r)
		{
			int *nb = board;
			nb[white] = nb[white + 1];
			nb[white + 1] = 9;
			addedge(i, kt(nb), 'r');
		}
		if ((white - 1) % 3 == r)
		{
			int *nb = board;
			nb[white] = nb[white - 1];
			nb[white - 1] = 9;
			addedge(i, kt(nb), 'l');
		}
		if ((white - 3) >= 0)
		{
			int *nb = board;
			nb[white] = nb[white - 3];
			nb[white - 3] = 9;
			addedge(i, kt(nb), 'u');
		}
		if ((white + 3) < 9)
		{
			int *nb = board;
			nb[white] = nb[white + 3];
			nb[white + 3] = 9;
			addedge(i, kt(nb), 'd');
		}
	}
}
int main()
{
	string g;
	getline(cin, g);
	int pz[9]; char c;
	strm << g;
	memset(inq, false, sizeof(inq));
	memset(head, -1, sizeof(head));
	for (int i = 0; i < 9; i++)
	{
		strm >> c;
		if (c == 'x')
			c = '9';
		pz[i] = c - '0';
	}
	int target = kt(pz);
	if (target == 1)
		cout << '\n';
	else
	{
		build();
		disc(1);
		if (way[target].empty())
			cout << "no solution!";
		else
			for (int i = 0; i < way[target].size(); i++)
				cout << way[target][i];
		cout << '\n';
	}
	return 0;
}