#include <iostream>
#include <fstream>
#include <random>
#include <time.h>
#include <string>
#include <sstream>
using namespace std;
int main()
{
	long int pre = clock();
	long long int i = 0;
	fstream file("test.txt", ios::out);
	if (!file)
	{
		cout << "failed";
		system("pause");
	}
	srand(time(0));
	while (true)
	{
		unsigned long long int number1 = rand();
		string snum;
		stringstream strm;
		strm.clear();
		strm << number1;
		strm >> snum;
		for (int i = 0; i < 2; i++)
		{
			unsigned long long int number2 = rand();
			strm.clear();
			string tem;
			strm << number2;
			strm >> tem;
			snum += tem;
		}
		file << snum << " ";
		int n = rand() % snum.length();
		file << n << '\n';
		if (clock() - pre > 7200)
			break;
	}
	file.close();
	return 0;
}