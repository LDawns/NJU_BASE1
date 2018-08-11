#include <iostream>
#include <string>
#include <map>
#include <set>
#include <stack>
#include <algorithm>
#include <vector>
#include <iterator>	//������
using namespace std;
typedef set<int> Set;		//Ϊ�������ӳ���ȡ������
map<Set, int> IDcache;		//�Ѽ���ӳ���ID
vector<Set> Setcache;		//��IDȡ����
#define ALL(x) x.begin(),x.end()
#define INS(x) inserter(x,x.begin())
//�о������Լ������ջ�ڵ�Ԫ��ʼ�ձ������Ѵ�����ϵ�����ŶԿ�.
int ID(Set x)
{
	if (IDcache.count(x))
	{
		return IDcache[x];
	}
	Setcache.push_back(x);
	return IDcache[x] = Setcache.size() - 1;
}
//���ϵ����ݽṹ�Ҹо��ǳ��ؼ�!��ؼ�ס!
int main()
{
	stack<int> s;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string op;
		cin >> op;
		if (op[0] == 'P') s.push(ID(Set()));
		else if (op[0] == 'D') s.push(s.top());
		else
		{
			Set x1 = Setcache[s.top()]; s.pop();
			Set x2 = Setcache[s.top()]; s.pop();
			Set x;
			if (op[0] == 'U') set_union(ALL(x1), ALL(x2), INS(x));
			else if (op[0] == 'I') set_intersection(ALL(x1), ALL(x2), INS(x));
			else if (op[0] == 'A') { x = x2; x.insert(ID(x1)); }
			s.push(ID(x));
		}
		cout << Setcache[s.top()].size() << endl;
	}
	
}
//��������:�����Ȱ�set�Ĵ��嶨����,Ȼ���ÿһ��set��������,���˱�ſ���������vector�ڲ��Ҷ�Ӧset,Ҳ����ֱ����ջ
//��ID������д�����������map���ر��,������vector������һ��Set,Ȼ���vector��ʱ�Ĵ�С������,���ر��ֵ.
//��ע:cache��Ϊ���ٻ���