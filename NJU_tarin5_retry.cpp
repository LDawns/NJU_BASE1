#include <iostream>
using namespace std;
int n, m;
const int maxn = 50010;
struct base
{
	int fa;
	int dis=0;
};
base p[maxn];
int findfa(int x)
{ 
	if (p[x].fa == x) return x;
	int tem = p[x].fa;
	p[x].fa = findfa(p[x].fa);
	p[x].dis += p[tem].dis;
	return p[x].fa;
}
int main()
{
	while (scanf("%d%d", &n, &m) != EOF)
	{
		int result = 0;
		for (int i = 0; i <= n; i++)
		{
			p[i].fa = i;
		}
		for (int i = 0; i < m; i++)
		{
			int a, b, x;
			cin >> a >> b >> x;
			int ra=findfa(a); int rb=findfa(b);
			if (ra==rb)
			{
				if (x != p[b].dis - p[a].dis)
					result++;
			}
			else
			{
				int ra = findfa(a);
				int rb = findfa(b);
				p[rb].dis = p[a].dis + x - p[b].dis;
				p[rb].fa = ra;
			}
		}
		cout << result << '\n';
	}
	return 0;
}