//���⣬��ǰm����ĸ����ɳ���Ϊn���ַ�����ʹ���Ӵ��л�������С
//��m = 1ʱ���ض�ȫ��a��
//��m >= 3ʱ���ض�ȫ��abcѭ������ΪҪ���ɻ��ģ����������Ҷ˵���ͬ���ҵڶ�����ͬ������֤����
//a���ұ߱ض���b��a����߱ض���c�����Ժ�a�ıض����ܳɻ��ġ�������a��ֻ��bc������abcѭ����������С��
//��m = 2ʱ��˼��������m>2��ѭ�����ӡ���ֻ��a��b������ĸ������Ҫ������ĸ��ϣ���aa, bb, ab, ba
//����ȡ�����ж��£���������С���ֵ�����С�����Է���aababbѭ���Ļ�������С��Ϊ4.��n <= 8ʱ��Ҫ���У�
//��Ϊn <= 8ʱ, ��С������С��4.��n >= 9ʱ����ͷ���aa�����������������ʹ�ֵ�����С��ɾȥaa�󣬽��ž���
//aababbѭ���ˡ�
//ע����ǣ�aababbѭ����ʣ���ʱ�򣬻���Ҫ���С���Ϊʣ������������ұߵ���Ӱ�죬�����ø�С���ֵ���
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int t;
	int n, m;
	int cas = 0;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d%d", &m, &n);
		printf("Case #%d: ", ++cas);
		if (m == 1)
		{
			for (int i = 0; i < n; i++)
			{
				printf("a");
			}
		}
		else if (m == 2)
		{
			if (n == 1)
				printf("a");
			else if (n == 2)
				printf("ab");
			else if (n == 3)
				printf("aab");
			else if (n == 4)
				printf("aabb");
			else if (n == 5)
				printf("aaaba");
			else if (n == 6)
				printf("aaabab");
			else if (n == 7)
				printf("aaababb");
			else if (n == 8)
				printf("aaababbb");
			else
			{
				printf("aa");//�������aa
				n = n - 2;
				int num = n / 6;
				for (int i = 1; i <= num; i++)
				{
					printf("aababb");
				}
				if (n % 6 == 1)
					printf("a");
				if (n % 6 == 2)
					printf("aa");
				if (n % 6 == 3)
					printf("aaa");
				if (n % 6 == 4)
					printf("aaaa");
				if (n % 6 == 5)
					printf("aabab");
			}
		}
		else
		{
			int num = n / 3;
			for (int i = 1; i <= num; i++)
			{
				printf("abc");
			}
			if (n % 3 == 1)
				printf("a");
			if (n % 3 == 2)
				printf("ab");
		}
		printf("\n");
	}
	return 0;
}