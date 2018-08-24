//分析
//N  球 从 0到N-1标号; A boxes 从0到A-1标号
//x球在a号box当且仅当x=a （mod A）
//现买B个新盒子，从0到B-1编号，x在b号，当且仅当x=b mod B
//从a到b，cost|a-b|
//总消耗就是每一个球的消耗的总和
//发现总有循环，可否由此出发？
//最小公倍数？对的！循环次数即最小公倍数！
//基本思路正确，对循环内部的细节处理不够完善完美，导致TL
//先过
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 10000000;
int T, N, A, B;
int cycle[maxn];
int multi(int a, int b)//最小公倍数
{
	int c1, c2, c3;
	if (a > b) { c2 = b; c3 = a; }
	else {c2 = a; c3 = b;}
	while (c3 != 0)//辗转相除求公因数，储存在c2中
	{
		c1 = c2 % c3;
		c2 = c3;
		c3 = c1;
	}
	return a * b / c2;
}
int main()
{
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		int result = 0;
		cin >> N >> A >> B;
		if (A == B)
		{
			cout << "0" << endl;
			continue;
		}
		int n=multi(A, B);
		if (n < N)
		{
			for (int i = 0; i < n; i++)
			{
				int a = i % A; int b = i % B;
				cycle[i] = abs(a - b);
				result += cycle[i];
			}
			int rn = N / n;
			result *= rn;
			int rr = N % n;
			for (int i = 0; i < rr; i++)
			{
				result += cycle[i];
			}
		}
		else
		{
			for (int i = 0; i < N; i++)
			{
				int a = i % A; int b = i % B;
				result += abs(a - b);
			}
		}
		cout << result << endl;
	}
	return 0;
}
