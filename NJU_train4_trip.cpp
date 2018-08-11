//³¬Ê±À²
//failed
#include <iostream>
using namespace std;
int alTest;
int M;
int N;
const int max = 100010;
int main()
{
	cin >> alTest;
	for (int i = 0; i < alTest; i++)
	{
		cin >> N >> M;
		unsigned mset[max];
		for (int i = 0; i < N; i++)
		{
			cin >> mset[i];
		}
		unsigned quest[max];
		for (int i = 0; i < M; i++)
		{
			cin >> quest[i];
		}
		unsigned result[max];
		for (int i = 0; i < M; i++)
		{
			unsigned tresult = 0;
			unsigned target = 0;
			for (int j = 0; j < N; j++)
			{
				if ((unsigned)(quest[i] ^ mset[j]) > tresult)
				{
					tresult = quest[i] ^ mset[j];
					target = mset[j];
				}
			}
			result[i] = target;
		}
		cout << "Case #" << i + 1 << ":" << endl;
		for (int i = 0; i < M; i++)
			cout << result[i] << endl;
	}
	return 0;
}