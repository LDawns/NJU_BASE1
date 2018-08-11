//N*N的图，两个兔子，不算重复，每隔一段时间左转，相遇互换方向并且取消左转。
//TOM在左上，jerry右下
//C方向，s速度，t左转时间
//一遍过
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;
const int maxn = 20;
map <char, int> dir;
int n, s1, s2, t1, t2;
char c1, c2;
struct rabbit
{
	int x;
	int y;
	int c;
	int s;
	int t;
	rabbit(int m, int n, char cc, int ss, int tt) { x = m; y = n; c = dir[cc]; s = ss; t = tt; }
};
rabbit walk(rabbit rot)
{
	if (rot.c == 0 || rot.c == 2)
	{
		int test = rot.y + (rot.c - 1)*rot.s;
		if (test < 0)
		{
			rot.c = (rot.c + 2) % 4;
			test = abs(test);
			rot.y = test;
		}
		else if (test >= n)
		{
			rot.c = (rot.c + 2) % 4;
			test = test - n + 1;
			rot.y = n - 1 - test;
		}
		else
			rot.y = test;
	}
	else
	{
		int test = rot.x + (rot.c - 2)*rot.s;
		if (test < 0)
		{
			rot.c = (rot.c + 2) % 4;
			test = abs(test);
			rot.x = test;
		}
		else if (test >= n)
		{
			rot.c = (rot.c + 2) % 4;
			test = test - n + 1;
			rot.x = n - 1 - test;
		}
		else
			rot.x = test;
	}
	return rot;
}
void solve(int k)
{
	rabbit tom(0, 0, c1, s1, t1);
	rabbit jerry(n - 1, n - 1, c2, s2, t2);
	for (int i = 0; i < k; i++)
	{
		if (tom.x == jerry.x&&tom.y == jerry.y)
		{
			char tem = tom.c;
			tom.c = jerry.c;
			jerry.c = tem;
		}
		else if(i!=0)
		{
			if (i%tom.t == 0)tom.c = (tom.c+1)%4;
			if (i%jerry.t == 0)jerry.c = (jerry.c + 1) % 4;
		}
		tom = walk(tom);
		jerry = walk(jerry);
	}
	cout << tom.y + 1 << " " << tom.x+ 1 << '\n';
	cout << jerry.y + 1 << " " << jerry.x + 1 << '\n';
}

int main()
{
	dir['N'] = 0; dir['W'] = 1; dir['S'] = 2; dir['E'] = 3;
	while ((cin >> n) && n != 0)
	{
		int k;
		cin >> c1 >> s1 >> t1;
		cin >> c2 >> s2 >> t2;
		cin >> k;
		solve(k);
	}
	return 0;
}