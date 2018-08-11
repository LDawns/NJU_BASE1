//细节题hhh
#include <iostream>
#include <algorithm>
using namespace std;
int T;
const int maxn = 62;
long long int result = 1;
long long int d[maxn];
long long int multi(int begin, int end)
{
	for (int i = begin; i < end; i++)
		result *= d[i];
	return result;
}
int main()
{
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		result=1;
		int N; cin >> N;
		memset(d, 0, sizeof(d));
		int min = 0; int max = 0;
		for (int i = 0; i < N; i++)
		{
			cin >> d[i];
			if (d[i] < 0)
				min++;
			else if (d[i] > 0)
				max++;
		}
		sort(d, d + N);
		if (max == 0 && min == 0)result = 0;	//全为零
		else if (max == 0 && min == 1)			//只有一个负数时
		{
			if (1 != N)
				result = 0;
			else
				result = d[0];
		}
		else if (min % 2)multi(0, min-1);
		else multi(0, min);
		multi(N - max, N);
		cout << result << '\n';
	}
	return 0;
}