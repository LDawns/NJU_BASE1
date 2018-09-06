//解决一个古老的3x3移方块小游戏
//哈哈哈，最后还要逆序输出，我忘了orz

#include <iostream>
#include <queue>
#include <string>
#include <sstream>
#include <vector>
#include <map>
using namespace std;
stringstream strm;
const int maxe = 100000000;
const int maxn = 362880;
int fac[] = { 1,1,2,6,24,120,720,5040,40320,362880 };
char path[maxn][50];
bool inq[maxn];
int dir[4][2] = { {-1,0},{1,0},{0,1},{0,-1} };
char dir2[5] = { 'l','r','d','u' };
map<char,char> dir3;


struct node
{
	int matri[10];
	int position;
	int state;
};
queue<node>q;
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
int kt(vector<int>s)
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

void build()//改进：在queue中不再使用vector，结果令人满意的达到了1s，ok！，剩下的改进再说吧
//打算把string换为char[]
//以及各种重复出现的变量化简一下。
{
	node base;
	for (int i = 1; i <= 9; i++)
		base.matri[i - 1] = i;
	base.position = 8;
	base.state = 1;
	q.push(base);
	inq[base.state] = true;
	while (!q.empty())
	{
		node vu = q.front(); q.pop();
		int w = vu.position;
		int wx = w % 3;
		int wy = w / 3;
		int u = vu.state;
		for (int i = 0; i < 4; i++)
		{
			int nx = wx + dir[i][0];
			int ny = wy + dir[i][1];
			if (nx >= 0 && nx < 3 && ny >= 0 && ny < 3)
			{
				int nw = ny * 3 + nx;
				node nb = vu;
				nb.position = nw;
				nb.matri[w] = nb.matri[nw];
				nb.matri[nw] = 9;
				int v = kt(nb.matri);
				nb.state = v;
				if (!inq[v])
				{
					inq[v] = true;
					q.push(nb);
					if (path[v][0]=='\0')
					{
						strcpy(path[v], path[u]);
						int len = strlen(path[v]);
						path[v][len] = dir2[i];
					}
				}
			}
		}
	}
}
int main()
{
	dir3['l'] = 'r';
	dir3['r'] = 'l';
	dir3['u'] = 'd';
	dir3['d'] = 'u';
	memset(inq, false, sizeof(inq));
	memset(path, '\0', sizeof(path));
	build();
	string g;
	while (getline(cin, g))
	{
		int pz[9]; char c;
		strm << g;
		for (int i = 0; i < 9; i++)
		{
			strm >> c;
			if (c == 'x')
				c = '9';
			pz[i] = c - '0';
		}
		int target = kt(pz);
		char result[50] = {};
		int slen = strlen(path[target]) - 1;
		for (int i = slen; i >= 0; i--)
		{
			result[slen - i] = dir3[path[target][i]];
		}
		if (!inq[target])
			printf("unsolvable\n");
		else
			cout << result << '\n';
	}
	return 0;
}