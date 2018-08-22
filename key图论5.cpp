#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <algorithm>
int sscount = 0;
typedef long long ll;
using namespace std;
const int MAXN = 362900;//最多是9!/2
int fac[] = { 1,1,2,6,24,120,720,5040,40320,362880 }; //康拖展开判重
													  //         0!1!2!3! 4! 5!  6!  7!   8!    9!
bool vis[MAXN];//标记
char path[MAXN][40];//记录路径
int cantor(int s[])//康拖展开求该序列的hash值
{
	int sum = 0;
	for (int i = 0; i < 9; i++)
	{
		int num = 0;
		for (int j = i + 1; j < 9; j++)
			if (s[j] < s[i])num++;
		sum += (num*fac[9 - i - 1]);
	}
	return sum + 1;
}
struct node
{
	int matri[10];
	int position;
	char path[50];
	int state;
};
queue<node>que;
char dire[5] = "dlur";
int dir[4][2] = { { -1,0 },{ 0,1 },{ 1,0 },{ 0,-1 } };
void bfs()
{
	memset(vis, false, sizeof(vis));
	node cur;
	for (int i = 0; i < 8; i++)
		cur.matri[i] = i + 1;
	cur.matri[8] = 0;
	cur.state = 46234;
	cur.path[0] = '\0';
	cur.position = 8;
	que.push(cur);
	vis[cur.state] = true;
	path[cur.state][0] = '\0';
	while (!que.empty())
	{
		sscount++;
		cur = que.front();
		que.pop();
		int x = cur.position / 3;
		int y = cur.position % 3;
		for (int i = 0; i < 4; i++)
		{
			int tx = x + dir[i][0];
			int ty = y + dir[i][1];
			if (tx < 0 || tx > 2 || ty < 0 || ty > 2)
				continue;
			node t = cur;
			t.position = tx * 3 + ty;
			t.matri[cur.position] = t.matri[t.position];
			t.matri[t.position] = 0;
			t.state = cantor(t.matri);
			if (!vis[t.state])
			{
				path[t.state][0] = t.path[0] = dire[i];
				int len = strlen(cur.path);
				for (int j = 1; j <= len + 1; j++)
					path[t.state][j] = t.path[j] = cur.path[j - 1];
				vis[t.state] = true;
				que.push(t);
			}
		}
	}
}
char ch;
int q[10];
int main()
{
	bfs();
	while (cin >> ch)
	{
		if (ch == 'x')
			q[0] = 0;
		else
			q[0] = ch - '0';
		for (int i = 1; i < 9; i++)
		{
			cin >> ch;
			if (ch == 'x')
				q[i] = 0;
			else
				q[i] = ch - '0';
		}
		int ans = cantor(q);
		// printf("%d",ans);
		if (!vis[ans])
			printf("unsolvable\n");
		else
		{
			cout << path[ans] << endl;
		}
	}
	return 0;
}