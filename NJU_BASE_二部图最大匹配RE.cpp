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
						break;						//��Ȼ�����
					}
				}
			}
		}
		cout << top << endl;
		for (int i = 0; i < top; i++)
		{
			cout << "C " << a[i]+1 << " " << b[i]+1 << endl;		//��������ۣ�ֻ����C��//���������������⣬���ˣ�����
		}
	}
	return 0;
}