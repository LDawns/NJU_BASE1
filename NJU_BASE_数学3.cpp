//����
//N  �� �� 0��N-1���; A boxes ��0��A-1���
//x����a��box���ҽ���x=a ��mod A��
//����B���º��ӣ���0��B-1��ţ�x��b�ţ����ҽ���x=b mod B
//��a��b��cost|a-b|
//�����ľ���ÿһ��������ĵ��ܺ�
//��������ѭ�����ɷ��ɴ˳�����
//��С���������Եģ�ѭ����������С��������
//����˼·��ȷ����ѭ���ڲ���ϸ�ڴ�������������������TL
//�ȹ�
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 10000000;
int T, N, A, B;
int cycle[maxn];
int multi(int a, int b)//��С������
{
	int c1, c2, c3;
	if (a > b) { c2 = b; c3 = a; }
	else {c2 = a; c3 = b;}
	while (c3 != 0)//շת�����������������c2��
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
