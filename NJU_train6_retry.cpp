//well done!
//但是状态压缩还是没有会用
//bfs应该差不多了
//一把钥匙对应一个buff一样的
//给visited 或者 done 多赋值一个这样子的状态就是。
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int n, m, p;
int k;
const int maxn = 50;
int S;
int  waDr[maxn][maxn][maxn][maxn];
int key[maxn][maxn];
vector <int> done[maxn][maxn];
int dir[4][2] = {{ 0,1 } ,{0, -1}, {1, 0}, {-1, 0}};
struct node
{
	int x, y;
	int step;
	vector <int> key;
};
bool walk(int a2,int b2,node c)
{
	if (a2 < 0 || a2 >= n || b2 < 0 || b2 >= m)return false;
	if (waDr[c.x][c.y][a2][b2] == 0)return false;
	
	for (int i = 0; i < c.key.size(); i++)
	{
		bool have = false;
		for (int j = 0; j < done[a2][b2].size(); j++)
		{
			if (c.key[i] == done[a2][b2][j])
			{
				have = true;
				break;
			}
		}
		if (!have) {
			break;
		}
		if (i == c.key.size() - 1)
			return false;
	}
	if (waDr[c.x][c.y][a2][b2] > 0)
	{
		for(int i = 0; i < c.key.size(); i++)
		{
			if (c.key[i] == waDr[c.x][c.y][a2][b2])
				return true;
		}
		return false;
	}
	return true;
}
int solve()
{
	queue <node> q;
	node init;
	init.x = 0; init.y = 0; init.step = 0;
	init.key.push_back(0);
	q.push(init);
	while (!q.empty())
	{
		node c = q.front(); q.pop();
		if (c.x == n - 1 && c.y == m - 1)
		{
			return c.step;
		}
		if (key[c.x][c.y] > 0)
		{
			bool have = false;
			for (int i = 0; i < c.key.size(); i++)
			{
				if (c.key[i] == key[c.x][c.y])
				{
					have = true;
					break;
				}
			}
			if (!have)
				c.key.push_back(key[c.x][c.y]);
		}
		if (c.key.size() == 0)
			done[c.x][c.y].push_back(0);
		else 
		{
			for (int i = 0; i < c.key.size(); i++)
			{
				bool have = false;
				for (int j = 0; j < done[c.x][c.y].size(); j++)
				{
					if (c.key[i] == done[c.x][c.y][j])
					{
						have = true;
						break;
					}
				}
				if (!have)done[c.x][c.y].push_back(c.key[i]);
			}
		}
		

		for (int i = 0; i < 4; i++)
		{
			if (walk(c.x + dir[i][0], c.y + dir[i][1], c))
			{
				node d;
				d.step=c.step+1;
				d.x=c.x + dir[i][0];
				d.y=c.y+ dir[i][1];
				d.key = c.key;
				q.push(d);
			}
		}
	}
	return -1;

}
int main()
{
	memset(key, 0, sizeof(key));
	memset(waDr, -1, sizeof(waDr));

	cin >> n >> m >> p;
	cin >> k;
	for(int i = 0; i < k; i++)
	{
		int a1, b1, a2, b2, g;
		cin >> a1 >> b1 >> a2 >> b2 >> g;
		waDr[a1-1][b1-1][a2-1][b2-1] = g;
		waDr[a2-1][b2-1][a1-1][b1-1] = g;
	}
	cin >> S;
	
	for (int i = 0; i < S; i++)
	{
		int a, b, g;
		cin >> a >> b >> g;
		key[a-1][b-1] = g;
	}
	cout << solve() << endl;
	return 0;
}