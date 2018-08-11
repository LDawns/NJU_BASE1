#include <iostream>
#include <string>
#include <map>
#include <set>
#include <stack>
#include <algorithm>
#include <vector>
#include <iterator>	//迭代器
using namespace std;
typedef set<int> Set;		//为了下面的映射和取出集合
map<Set, int> IDcache;		//把集合映射成ID
vector<Set> Setcache;		//据ID取集合
#define ALL(x) x.begin(),x.end()
#define INS(x) inserter(x,x.begin())
//感觉就是自己必须对栈内的元素始终保有早已处理完毕的信念才对咯.
int ID(Set x)
{
	if (IDcache.count(x))
	{
		return IDcache[x];
	}
	Setcache.push_back(x);
	return IDcache[x] = Setcache.size() - 1;
}
//以上的数据结构我感觉非常关键!务必记住!
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
//整理如下:我们先把set的大定义定下来,然后对每一个set赋予其标号,而此标号可以用来在vector内查找对应set,也可以直接入栈
//而ID函数的写法则是有则据map返回标号,无则在vector中新增一个Set,然后据vector此时的大小定其标号,返回标号值.
//另注:cache意为高速缓存