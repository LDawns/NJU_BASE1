#include<iostream>
using namespace std;
#include<cstdio>
#include<cmath>
const int maxn = 500001;
int main()
{
	int city, box;
	while (~scanf("%d%d", &city, &box))
	{
		if (city == -1 && box == -1)
			break;
		else
		{
			int cities[maxn];//城市
			for (int i = 0; i<city; i++)
				cin >> cities[i];
			int max = cities[0];//当前最大值
			for (int i = 0; i<city; i++)
			{
				if (max<cities[i])
					max = cities[i];
			}
			if (city == box)
				cout << max << endl;
			else
			{
				int l = 1, r = max;
				while (l<r)
				{
					int mid = (l + r) / 2;
					int sum = 0;
					for (int i = 0; i<city; i++)
					{
						sum = sum + ceil((cities[i] * 1.0) / mid);//我是真的看不懂这个鬼式子],ceil去掉还不行= =
						//ceil的意义我大概知晓了,但是这个式子还是有一些迷醉
					}
					if (sum>box)
						l = mid + 1;
					else r = mid;
				}
				cout << r << endl;
			}
		}
	}
}