//b general:0
//r general:1
//³µ £º2   ÅÚ£º3   Âí£º4
//w : -1

#include <iostream>
#include <map>
#include <algorithm>

using namespace std;
map<char, int> type;
int dir[4][2] = { {0,1}, {0,-1}, {1,0}, {-1,0} };
int chessboard[10][9];
void copy(int newboard[][9], int oldboard[][9])
{
	for(int i=0;i<10;i++)
		for (int j = 0; j < 9; j++)
		{
			newboard[i][j] = oldboard[i][j];
		}
}
bool checkmate(int x,int y,int board[][9])
{
	for(int i=0;i<10;i++)
		for (int j = 0; j < 9; j++)
		{
			if (board[i][j])
			{
				int ctype = board[i][j];
				if (ctype == 1)
				{
					if (j == y)
					{
						bool eat=true;
						for (int k = x + 1; k <= i - 1; k++)
						{
							if (board[k][j] != -1)eat = false;
								break;
						}
						if (eat)return true;
					}
				}
				else if (ctype == 2)
				{
					if (j == y)
					{
						bool eat = true;
						int r = min(i, x);
						int l = max(i, x);
						for (int k = r + 1; k <= l - 1; k++)
						{
							if (board[k][j] != -1)eat = false;
							break;
						}
						if (eat)return true;
					}
					else if (i == x)
					{
						bool eat = true;
						int u = min(j, y);
						int d = max(j, y);
						for (int k = u + 1; k <= d - 1; k++)
						{
							if (board[i][k] != -1)eat = false;
							break;
						}
						if (eat)return true;
					}
				}
				else if (ctype == 3)
				{
					if (i == x)
					{
						int count = 0;
						int r = min(x, i);
						int l = max(x, i);
						for (int k = r + 1; k <= l - 1; k++)
						{
							if (board[x][k])count++;
						}
						if (count == 1)return true;

					}
					else if (y == j)
					{
						int count = 0;
						int u = min(x, i);
						int d = max(x, i);
						for (int k = u + 1; k <= d - 1; k++)
						{
							if (board[k][y])count++;
						}
						if (count == 1)return true;
					}
				}
				else if (ctype == 4)
				{
					bool leg = false;
					for (int k = 0; k < 4; k++)
						if (board[i + dir[k][0]][j + dir[k][1]] != -1) { leg = true; break; }
					if (leg)continue;
					else
					{
						if (abs(i - x) == 1)
						{
							if (abs(j - y) == 2)
								return true;
						}
						else if (abs(i - x) == 2)
						{
							if (abs(j - y) == 1)
								return true;
						}
					}
				}
			}
		}
	return false;
}
bool move(int ox, int oy, int nx, int ny, int board[][9])
{
	int testboard[10][9];
	copy(testboard, board);
	testboard[ox][oy] = -1;
	testboard[nx][ny] = 0;
	if (checkmate(nx,ny,testboard))
		return false;
	else
		return true;
}
bool couldmove(int x, int y)
{
	if (x < 0 || x > 2 || y < 3 || y > 5 )
	{
		return false;
	}
}

int main()
{
	type['G'] = 1; type['R'] = 2; type['C'] = 3; type['H'] = 4;
	int N, x, y;
	while ((cin >> N >> x >> y) && N != 0)
	{
		memset(chessboard, -1, sizeof(chessboard));
		chessboard[x - 1][y - 1] = 0; x = x - 1; y = y - 1;
		for (int i = 0; i < N; i++)
		{
			char c; int rx; int ry;
			cin >> c >> rx >> ry;
			chessboard[rx - 1][ry - 1] = type[c];
		}
		bool die = true;
		for (int i = 0; i < 4; i++)
		{
			if (couldmove(x + dir[i][0], y + dir[i][1]))
			{
				if (move(x, y, x + dir[i][0], y + dir[i][1], chessboard))
				{
					die = false;
					break;
				}
			}
		}
		if (die)cout << "YES" << '\n';
		else cout << "NO" << '\n';
	}
	return 0;
}