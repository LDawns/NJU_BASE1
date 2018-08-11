#include <iostream>
#include <string>
#include <sstream>
using namespace std;
typedef long long ll;
const int N = 2;								//N元树
const int maxn = 1000;							//最长通路
int in[maxn], post[maxn], n;					//中序和后序的遍历结果,n代表节点数
struct tree
{
	ll value;
	tree* next[N];
	tree()
	{
		for (int i = 0; i < N; i++)
		{
			next[i] = NULL;
			value = 0;
		}
	}
};
bool read_list(int*a)							//数组有时候也还是很好的,一个完整通路最好用数组来搞
{
	string line;
	stringstream strm;
	strm.clear();
	if (!getline(cin,line))return false;
	strm << line;
	int tem; n = 0;
	while (strm >> tem) { a[n++] = tem; }		//这个n搞得很巧妙嘛
	return n > 0;
}
tree* build(int L1, int R1, int L2, int R2)		//根据中序,后序递归的建造整个树
{
	if (L1 > R1)								//停止,否则可能越界
		return NULL;
	tree*root = new tree();
	root->value = post[R2];
	int p;
	for (p = L1; in[p] != root->value; p++);
	int cnt = p - L1;
	root->next[1] = build(p + 1, R1,L2+cnt,R2-1);
	root->next[0] = build(L1, p - 1, L2, L2 + cnt - 1);
	return root;
}
void del(tree*root)								//递归释放
{
	tree*p = root;
	for (int i = 0; i < N; i++)
	{
		if (p->next[i])
			del(p->next[i]);
	}
	delete(root);
}
int leaf; int bsum;
void dfs(tree*root,int sum)//这个结构真棒！
{
	tree*p = root;
	sum += p->value;
	if (!p->next[0] && !p->next[1])
	{
		if (sum < bsum)
		{
			bsum = sum;
			leaf = p->value;
		}
		else if (sum == bsum && p->value < leaf)
		{
			leaf = p->value;
		}
	}
	if (p->next[0])dfs(p->next[0], sum);//此sum是每一层的,由于函数特性..说不清楚,但有感觉
	if (p->next[1])dfs(p->next[1], sum);//分两个函数,代表二叉,多叉则多分
}
int main()
{
	while (read_list(in))
	{
		read_list(post);
		tree*root = build(0,n-1,0,n-1);
		bsum = 100000000;
		dfs(root, 0);
		cout << leaf << endl;
	}
	return 0;
}