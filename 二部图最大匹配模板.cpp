//����ͼ���ƥ�� - �������㷨 - ģ��
#include <iostream>
using namespace std;
#define N 205 
int useif[N];  // ��¼y�нڵ��Ƿ�ʹ��
int link[N];  // ��¼��ǰ��y�ڵ�������x�Ľڵ�
int mat[N][N];// ��¼����x��y�ıߣ����i��j֮���б���Ϊ1������Ϊ0
int gn, gm;    //����ͼ��x��y�е����Ŀ
bool find(int t) //DFS�Ĺ���
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
int MaxMatch() //�������е�����������ö���ͼ���ƥ��
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