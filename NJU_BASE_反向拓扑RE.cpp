//�㷨������
//while����Qempty��
//	{
//		��ջ��Ԫ�أ�����������������������Ѿ���-1�����-1
//		��ָ���Ԫ�صĳ��ȼ�һ�������˳���Ϊ�㣬����У�
//	}
//
//ϸ�ڣ��ж��ر�!!!��Ȼ���Ȼ���ģ������߼��qemptyʱ�Ƿ��Ѿ���k�������
//���������ϸ�ڣ�������ʱ��������еı߶������������е���
//AC
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int T;
int N,M,w;
const int maxn = 300;
int weight[maxn];
bool matrix[maxn][maxn];
int outn[maxn];
bool tp()
{
	priority_queue<int>q;
	for (int i = 1; i <= N; i++)
	{
		if (outn[i] == 0)
			q.push(i);
	}
	while (!q.empty())
	{
		int u = q.top(); q.pop();
		weight[u] = w--;
		if (w == -1)
			return false;
		for (int i = 1; i <= N; i++)
		{
			if (matrix[i][u])
			{
				outn[i]--;
				if (outn[i] == 0)
					q.push(i);
			}
		}
	}
	if (w != 0)
		return false;
	else
		return true;
}
int main()
{
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin>>N >> M;
		w = N;
		memset(matrix, false, sizeof(matrix));
		memset(outn, 0, sizeof(outn));
		for (int i = 0; i < M; i++)
		{
			int a, b;
			cin >> a >> b;
			if (!matrix[a][b])								//�ж��ر�!!!��Ȼ���Ȼ���ģ���
			{
				matrix[a][b] = true;
				outn[a]++;
			}
		}
		if (tp())
		{
			for (int i = 1; i <= N; i++)
			{
				cout << weight[i] << " ";
			}
			cout << endl;
		}
		else
		{
			cout << "-1" << endl;
		}
	}
	return 0;
}

