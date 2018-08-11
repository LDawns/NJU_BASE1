#include <iostream>
#include <vector>
using namespace std;
struct base
{
	int value=-1;
	bool done=false;
};
base maze[50][50];
int waDr[50][100];
int m, n, p, k, S;
int bsum;

void clear()
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{	if(maze[i][j].value<0)
			maze[i][j].done = false;
		}
}
void clear(int n)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			maze[i][j].done = false;
		}
}
bool walk(int a1,int b1,int a2,int b2,vector<int> key)
{
	if (maze[a2][b2].done)return false;
	if (a2 < 0 || a2 >= n || b2 < 0 || b2 >= m)return false;
	int nwaDr = waDr[a1 + a2 - a1][2 * b1 + b2 - b1];
	if (nwaDr == 0)return false;
	if (nwaDr == -1)return true;
	for (int i = 0; i < key.size(); i++)//�ض������������ķ���
		if (key[i] == nwaDr)//��Կ�ף�
			return true;
	return false;
}
//�ݹ�Ҫע���һ���㣺ȫ�ֱ��������⣬�����Ұ�vector�ŵ�����ȥ�ˡ�
//���ﻹ�ǳ���bsum���ⲻ�����κ�ȫ�ֱ�������
//�������bugҪ�������ͱ����maze.done���ɾֲ����������ұ�Ϊ�βΡ�
//��key�����ټ�һ����*bool����50��
void solve(int r, int c, int sum, vector<int> key)//����ո�ѧ����dfs�ݹ����ݽṹ�����
{
	if (maze[r][c].value > 0&&!maze[r][c].done) {	
		key.push_back(maze[r][c].value);
		clear();
	}
	maze[r][c].done = true;
	if (r == n - 1 && c == m - 1)
	{
		if (sum < bsum)
			bsum = sum;
		clear(0);
		return;
	}
	sum++;
	if (walk(r, c, r - 1, c,key))solve(r - 1, c,sum, key);
	if (walk(r, c, r + 1, c,key))solve(r + 1, c, sum, key);
	if (walk(r, c, r, c - 1,key))solve(r, c - 1, sum, key);
	if (walk(r, c, r, c + 1,key))solve(r, c + 1, sum, key);
	clear(0);
}

int main()
{
	memset(waDr, -1, sizeof(waDr));
	cin >> n >> m >> p>> k;
	for (int i = 0; i < k; i++)
	{
		int a1, b1, a2, b2, g;
		cin >> a1 >> b1 >> a2 >> b2 >>g;
		waDr[a1 + a2 - a1 - 1][2 * b1 + b2 - b1 - 2] = g;
	}
	cin >> S;
	for (int i = 0; i < S; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		maze[a - 1][b - 1].value = c;
	}
	bsum = 1000000000;
	vector<int> key;
	solve(0, 0, 0, key);
	cout << bsum <<'\n';
	return 0;
}