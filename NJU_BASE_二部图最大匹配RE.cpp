#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 200;
int matrix[maxn][maxn];
int N; int mcount = 0;
bool visx[maxn], visy[maxn];
int match[maxn];
int a[maxn], b[maxn];

bool find(int x)
{
	for (int i = 0; i < N; i++)
	{
		if (!visy[i]&&matrix[x][i])
		{
			visy[i] = true;
			if (match[i] == -1 || find(match[i]))
			{
				match[i] = x;
				return true;
			}
		}
	}
	return false;
}

int main()
{
	while (~scanf("%d", &N))
	{
		mcount = 0;
		memset(match, -1, sizeof(match));
		for(int i=0;i<N;i++)
			for (int j = 0; j < N; j++)
			{
				cin >> matrix[i][j];
			}
		for (int i = 0; i < N; i++)
		{
			memset(visx, false, sizeof(visx));
			memset(visy, false, sizeof(visy));
			if (find(i))mcount++;
		}
		if (mcount < N)
		{
			cout << "-1" << endl;
			continue;
		}
		int top = 0;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (match[j] == i)
				{
					if (j == i)break;
					else
					{
						a[top] = i;
						b[top++] = j;
						swap(match[i], match[j]);
						break;						//居然在这里！
					}
				}
			}
		}
		cout << top << endl;
		for (int i = 0; i < top; i++)
		{
			cout << "C " << a[i]+1 << " " << b[i]+1 << endl;		//还有这里，槽，只能是C？//或者有哪里有问题，算了，过。
		}
	}
	return 0;
}