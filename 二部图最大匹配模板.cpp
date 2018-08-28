//二分图最大匹配 - 匈牙利算法 - 模板
#include <iostream>
using namespace std;
#define N 205 
int useif[N];  // 记录y中节点是否使用
int link[N];  // 记录当前与y节点相连的x的节点
int mat[N][N];// 记录连接x和y的边，如果i和j之间有边则为1，否则为0
int gn, gm;    //二分图中x和y中点的数目
bool find(int t) //DFS的过程
{
	int i;
	for (i = 1; i <= gm; i++)
	{
		if (useif[i] == 0 && mat[t][i])
		{
			useif[i] = 1;
			if (link[i] == -1 || find(link[i]))
			{
				link[i] = t;
				return true;
			}
		}
	}
	return false;
}
int MaxMatch() //主函数中调用它就能求得二分图最大匹配
{
	int i, num;
	num = 0;
	memset(link, -1, sizeof(link));
	for (i = 1; i <= gn; i++)
	{
		memset(useif, 0, sizeof(useif));
		if (find(i)) num++;
	}
	return num;
}