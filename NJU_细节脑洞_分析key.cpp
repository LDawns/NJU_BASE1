//题意，用前m个字母，组成长度为n的字符串，使得子串中回文数最小
//当m = 1时，必定全是a。
//当m >= 3时，必定全是abc循环，因为要构成回文，回文中左右端点相同，且第二级相同。举例证明：
//a的右边必定是b，a的左边必定是c。所以含a的必定不能成回文。而不含a的只有bc，所以abc循环回文数最小。
//当m = 2时，思考用上述m>2的循环来接。当只有a，b两个字母。所以要两个字母组合，有aa, bb, ab, ba
//任意取三个判断下，回文数最小，字典序最小。可以发现aababb循环的回文数最小，为4.当n <= 8时需要特判，
//因为n <= 8时, 最小回文数小于4.当n >= 9时，开头添加aa不会增大回文数，且使字典序最小。删去aa后，接着就是
//aababb循环了。
//注意的是，aababb循环有剩余的时候，还需要特判。因为剩余的数不会有右边的数影响，可以用更小的字典序。
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
				printf("aa");//首先输出aa
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