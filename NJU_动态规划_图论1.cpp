//�����е�i��|ai|<T
//���Ҷ��������ڵ�j��˵��|ai-aj|>=T
//�������|ai-aj|>=T����ô���Ǳض������ڵ�
//����vi.vj)����E�����ҽ���|ai-aj|>=T
//�����������㹹�ɵĻ���һ������
//�����������ڣ����븺������
//N��Ϊ�������죬����Ϊ�з��׼
//�ȵ�һ�ܺ��ٻ�����д�ɣ�
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int TC;
bool near[300][300];
bool done[300];
//����һЩ���еĴ��룬���������µݹ�Ľṹ���򵥵���˵����
//dfs��ÿһ���㶼�����Ǹ��ڵ�
//ok
//�������гɾ͸е�hhh
bool cycle(int ans, int now, int n, vector<int>line)
{
	done[now] = true;
	line.push_back(now);
	int len = line.size();
	for (int j = 0; j < len-1; j++)
	{
		if (line[j] != ans)
		{
			if (line[j] == now)
				if ((len - j - 1) % 2)
					return true;
				else
					return false;
		}
	}
	for (int j = 0; j < n; j++)
	{
		if (j != ans&&near[now][j] && cycle(now, j, n, line))
			return true;
	}
	line.clear();
	return false;
}
bool solve(int n)
{
	vector<int>line;
	for (int i = 0; i < n; i++)
		if (!done[i] && cycle(i, 0, n, line))
			return false;
	bool result=true;
	return result;
}
int main()
{
	cin >> TC;
	for (int i = 0; i < TC; i++)
	{
		int n; cin >> n;
		int T;
		for (int i=0; i < n; i++)
		{
			string tem;
			cin >> tem;
			for (int j = 0; j < n; j++)
				near[i][j] = tem[j]-'0';
		}
		memset(done, false, sizeof(done));
		bool result = solve(n);
		
		
		
		if (result)cout << "Yes" << '\n';
		else cout << "No" << '\n';
	}
	return 0;
}