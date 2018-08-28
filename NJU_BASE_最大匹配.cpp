//每一行数据都看作为一个节点
//矩阵的绝对位置“第i行”也可以看为n个节点
//这就是从n到n的二部图匹配问题
#include <iostream>
using namespace std;
const int maxn = 200;
const int maxd = 400;
int matrix[maxn][maxn];
int mdata[maxd];
bool doing[maxn];
bool done[maxn];
int link[maxn];
int vrow[maxn];
int datacount = 0;
int edgecount = 0;
int n;
bool found(int x)
{
	for (int i = 0; i < n; i++)
	{
		if (matrix[x][i]&&!doing[i]) 
		{
			doing[i] = true;//这个的所有元素都要在main里面的循环中每次都memset为false
			if (!done[i] || found(link[i]))
			{
				done[i] = true;
				link[i] = x;
				return true;
			}
		}
	}
	return false;
}
void exchange(int a, int b)
{
	int tem;
	for (int i = 0; i < n; i++)
	{
		tem = matrix[a][i];
		matrix[a][i] = matrix[b][i];
		matrix[b][i] = tem;
	}
}
int main()
{
	while (~scanf("%d", &n))
	{
		memset(mdata, -1, sizeof(mdata));
		datacount = 0;
		edgecount = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
			{
				cin >> matrix[i][j];
			}
		for (int i = 0; i < n; i++)
		{
			memset(doing, false, sizeof(doing));
			if (found(i))
			{
				edgecount++;
			}
		}
		if (edgecount != n)
		{
			cout << "-1" << endl;
			continue;
		}
		for (int i = 0; i < n; i++)
			vrow[i] = i;							//原来绝对位置上的行现在所在之地
		for (int i = 0; i < n; i++)
		{
			int now = vrow[link[i]];
			if (now != i)
			{
				mdata[datacount++] = now;
				mdata[datacount++] = i;
				vrow[i] = now;
			}
		}
		for (int i = 0; mdata[i] != -1; i++)
		{
			if (!(i%2))
			{
				if(i>0)
				cout << endl;
				cout << "R ";
			}
			cout << mdata[i] << " ";
		}
	}
	return 0;
}