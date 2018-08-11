//failed again= =
//³¬Ê±,shit!
#include<iostream>
#include <algorithm>
using namespace std;
const int MAXCITY=50000;
struct base
{
	int people;
	int box;
	int opeople;
};



bool cmp(const base&a, const base &b)//remember it!
{
	return a.people>b.people;// down down down
}

int main()
{
	int cities=0; int boxes=0;
	while (cin >> cities >> boxes)
	{
		if (cities == -1 || boxes == -1) break;
		base city[MAXCITY];
		for (int i = 0; i < cities; i++)
		{
			cin >> city[i].people;
			city[i].box = 1;
			city[i].opeople = city[i].people;
		}
		sort(city, city + cities, cmp);
		boxes -= cities;
		for (int i = 0; i < boxes; i++)
		{
			city[0].box++;
			city[0].people=city[0].opeople / city[0].box;
			for (int j = 0; j < cities-1; j++)
			{
				if (city[j].people < city[j + 1].people)
					swap(city[j], city[j + 1]);
				else
					break;
			}
			//sort(city, city + cities, cmp);
		}
		cout << city[0].people << endl;
	}
	return 0;
}