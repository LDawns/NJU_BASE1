#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 1000;
const int INF = 1000000000;
int white[maxn]; int more[maxn];	//零数组和多余数组
int boxes[maxn];					//盒子里的蛋糕
int love[maxn][maxn];				//权值
int ex[maxn], ey[maxn];				//x和y的期望
int match[maxn];					//最终结果
bool visx[maxn], visy[maxn];		//访问判定
int xn; int myn;					//x和y子图的点数
int slack[maxn];					//y还需努力的点数
//思路即是将多余的蛋糕视为x子图，零点视为y子图，而每一个蛋糕距离零的距离的负数视为权重，求最大权问题
int n;
bool dfs(int x)
{
	visx[x] = true;
	for (int i = 0; i < myn; i++)
	{
		if (visy[i])continue;
		int gap = ex[x] + ey[i] - love[x][i];
		if (0 == gap)
		{
			visy[i] = true;
			if (match[i] == -1 || dfs(match[i]))
			{
				match[i] = x;
				return true;
			}
		}
		else
		{
			slack[i] = min(slack[i], gap);
		}
	}
	return false;
}
int KM()
{
	memset(match, -1, sizeof(match));
	memset(ey, 0, sizeof(ey));

	for (int i = 0; i < xn; i++)						//初始化ex为其最大权值之y
	{
		ex[i] = love[i][0];
		for (int j = 1; j < myn; j++)
		{
			ex[i] = max(ex[i], love[i][j]);
		}
	}


	for (int i = 0; i < xn; i++)
	{
		fill(slack, slack + myn, INF);
		while (true)
		{
			memset(visx, false, sizeof(visx));
			memset(visy, false, sizeof(visy));
			if (dfs(i))break;
			int d = INF;
			for (int j = 0; j < myn; j++) {
				if (!visy[j])
					d = min(d, slack[j]);
			}
			for (int j = 0; j < xn; j++)
			{
				if (visx[j])ex[j] -= d;
			}
			for (int j = 0; j < myn; j++)
			{
				if (visy[j])ey[j] += d;
			}
		}
	}
	int res = 0;
	for (int i = 0; i < myn; ++i)
	{
		if (match[i] != -1)
			res += abs(love[match[i]][i]);
	}
	return res;
}
int main()
{
	while (~scanf("%d", &n))
	{
		memset(white, -1, sizeof(white));
		memset(more, -1, sizeof(more));
		myn = 0; xn = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> boxes[i];
			if (0 == boxes[i])
			{
				white[myn++] = i;
			}
			else if (boxes[i] > 1)
			{
				for (int j = 0; j < boxes[i] - 1; j++)
					more[xn + j] = i;
				xn += boxes[i] - 1;
			}
		}
		for (int i = 0; i < xn; i++)
		{
			for (int j = 0; j < myn; j++)
			{
				int l = abs(white[j] - more[i]);
				int r = n - l;
				love[i][j] = -min(r, l);
			}
		}
		cout << KM() << endl;
	}
}
