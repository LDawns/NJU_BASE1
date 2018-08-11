#include <iostream>
#include <string>
#include <sstream>
using namespace std;
typedef long long ll;
const int N = 2;								//NԪ��
const int maxn = 1000;							//�ͨ·
int in[maxn], post[maxn], n;					//����ͺ���ı������,n����ڵ���
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
bool read_list(int*a)							//������ʱ��Ҳ���Ǻܺõ�,һ������ͨ·�������������
{
	string line;
	stringstream strm;
	strm.clear();
	if (!getline(cin,line))return false;
	strm << line;
	int tem; n = 0;
	while (strm >> tem) { a[n++] = tem; }		//���n��ú�������
	return n > 0;
}
tree* build(int L1, int R1, int L2, int R2)		//��������,����ݹ�Ľ���������
{
	if (L1 > R1)								//ֹͣ,�������Խ��
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
void del(tree*root)								//�ݹ��ͷ�
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
void dfs(tree*root,int sum)//����ṹ�����
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
	if (p->next[0])dfs(p->next[0], sum);//��sum��ÿһ���,���ں�������..˵�����,���ио�
	if (p->next[1])dfs(p->next[1], sum);//����������,�������,�������
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