//这个树更像是字典树
#include <cstdio>
#include <iostream>
using namespace std;
typedef long long int ll;
const int N = 2;
struct tree
{
	ll f;
	tree *next[N];
	tree()
	{
		for (int i = 0; i<N; i++) next[i] = NULL;
		f = 0;
	}
};
int a[33];
void insert(tree *root, int *a)
{
	int len = 31;
	tree *p = root;
	while (len >= 0)
	{
		int id = a[len];
		if (p->next[id] == NULL)
		{
			tree *temp = new tree();
			p->next[id] = temp;
		}
		p = p->next[id];
		if (id) p->f = ll(1) << len;
		len--;
	}
}
ll find(tree *root, int *a)
{
	tree *p = root;
	int len = 31;
	ll ans = 0;
	while (len >= 0)
	{
		int id = a[len];
		if (p->next[id] == NULL) id ^= 1;//若不存在,则取另一个
		p = p->next[id];
		if (id) ans += p->f;
		len--;
	}
	return ans;
}
void del(tree *root)//递归删除,nice
{
	for (int i = 0; i<N; i++)
		if (root->next[i])
			del(root->next[i]);
	delete(root);
}
void ch(int n, int *a)//转换为二进制
{
	int len = 0;
	while (n)
	{
		a[len++] = n % 2;
		n /= 2;
	}
}
int main()
{
	int t, n, m;
	scanf("%d", &t);
	int t1 = 1;
	while (t--)
	{
		tree *root = new tree();
		scanf("%d%d", &n, &m);
		int x;
		for (int i = 0; i<n; i++)
		{
			scanf("%d", &x);
			memset(a, 0, sizeof(a));
			ch(x, a);
			insert(root, a);
		}
		printf("Case #%d:\n", t1++);
		while (m--)
		{
			scanf("%d", &x);
			memset(a, 0, sizeof(a));
			ch(x, a);
			for (int i = 0; i<32; i++) a[i] ^= 1;//意图寻找到最大的,即反码
			printf("%I64d\n", find(root, a));
		}
		del(root);
	}
	return 0;
}
