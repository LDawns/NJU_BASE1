//��Ҫ������fatherһ��ҪԤ������Ϊ�Լ�!
//������кܶ�bug
//Ȼ�������漰�����鼯
//��ν���鼯Ҳ����ѹ�����ϣ�����ڵ㵽���ľ���,Ѱ��ȼ۹�ϵ,������Ŀ
//��������ǲ�������Ŀ�����·.
#include <iostream>
using namespace std;
struct base
{
	int faNum=0;
	int dis = 0;
};
const int PMAX = 50000;
const int QMAX = 100000;
base people[PMAX];
int N, M, result=0;
void findFA(int num)
{
	int fa = people[num].faNum;
	while (people[fa].faNum != 0)
	{
		people[num].dis += people[fa].dis;
		people[num].faNum = people[fa].faNum;
		fa = people[num].faNum;
		people[num].dis %= 300;
	}
}
int main()
{
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		int s, t, d;
		cin >> s >> t >> d;
		findFA(s); findFA(t);
		if (people[t].faNum)
		{
			if (!people[s].faNum)
			{
				if (s == people[t].faNum)
				{
					if (d != people[t].dis)
						result++;
				}
				else
				{
					people[s].faNum = people[t].faNum;
					people[s].dis = people[t].dis - d;
				}
			}
			else
			{
				if (people[s].faNum == people[t].faNum)
				{
					if (d != (people[t].dis - people[s].dis))
						result++;
				}
				else
				{
					int mfa = people[t].faNum;
					people[mfa].faNum = s;
					people[mfa].dis = d - people[t].dis+people[s].dis;
				}
			}
		}
		else
		{
			if (people[s].faNum == t)
			{
				if (d != 300 - people[s].dis)
					result++;
			}
			else
			{
				people[t].faNum = s;
				people[t].dis = d;
			}
		}
	}
	cout << result << '\n';
	return 0;
}