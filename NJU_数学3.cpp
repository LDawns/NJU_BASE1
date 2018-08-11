#include <iostream>
#include <vector>
using namespace std;
int T;
typedef long long ll;
int main()
{
	cin >> T;
	for (int i = 0; i < T; i++)
	{

	}
}





//贴一下关键代码
//
//
//ll p = 0, sum = 0;
//while (p<n)
//{
//	ll t1 = a - p % a, t2 = b - p % b;
//	ll add = min(t1, t2);
//	if (p + add >= n) add = n - p;
//	sum += (p%a + p % b)*add;
//	p += add;
//}
//
//
//if ((t = lcm(a, b)) >= n) cout << f(n, a, b) << endl;
//else cout << f(t, a, b)*(n / t) + f(n%t, a, b) << endl;