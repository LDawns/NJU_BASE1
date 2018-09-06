//算法描述：
//while（！Qempty）
//	{
//		出栈首元素，分配最大重量，如若重量已经是-1，输出-1
//		将指向该元素的出度减一；如果因此出度为零，入队列；
//	}
//
//细节：判断重边!!!不然出度会抽风的！！或者检查qempty时是否已经将k分配完毕
//拓扑排序的细节：问题有时不会把所有的边都描述起来，有单边
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
			if (!matrix[a][b])								//判断重边!!!不然出度会抽风的！！
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

