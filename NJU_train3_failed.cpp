//failed 
//举例子举得太少.
//看一看RMQ吧= =
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <sstream>
using namespace std;
const int MAX = 1000;
struct isort
{
	int ID;
	char orgin;
};
bool cmp(const isort &a, const isort &b)
{
	return a.orgin > b.orgin;
}
vector<char> num;
isort iID[MAX];
int main()
{
	string snum;
	cin >> snum;
	stringstream strm;
	strm << snum;
	char c;
	int i = 0;
	while (strm >> c)
	{
		num.push_back(c);
		iID[i].ID = i;
		iID[i].orgin = c;
		i++;
	}
	int n;
	cin >> n;
	if (n >= num.size())
	{
		cout << "0" << endl;
		return 0;
	}
	sort(iID, iID + num.size(), cmp);
	for (int i = 0; i < n; i++)
	{
		num.erase(num.begin() + iID[i].ID);
		for (int j = i+1; j < n; j++)
		{
			if (iID[j].ID > iID[i].ID)
			{
				iID[j].ID--;
			}
		}
	}
	strm.clear();
	snum.clear();
	for (int i = 0; i < num.size(); i++)
		snum += num[i];
	for (int i = 0; i < snum.length(); i++)
	{
		if (snum[i] != '0')
		{
			snum = snum.substr(i);
			break;
		}
		if (snum[snum.length() - 1] == '0')
		{
			snum.clear();
			snum += '0';
		}
	}
	cout << snum.c_str() << endl;
	return 0;
}

