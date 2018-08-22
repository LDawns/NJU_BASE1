#include <iostream>
#include <string>
#include <sstream>
using namespace std;
int pz[9]; int pos;
void walk(char dir)
{
	if (dir == 'l')
	{
		pz[pos] = pz[pos - 1];
		pz[pos - 1] = 9;
		pos -= 1;
	}
	else if (dir == 'r')
	{
		pz[pos] = pz[pos + 1];
		pz[pos + 1] = 9;
		pos += 1;
	}
	else if (dir == 'u')
	{
		pz[pos] = pz[pos - 3];
		pz[pos - 3] = 9;
		pos -= 3;
	}
	else if (dir == 'd')
	{
		pz[pos] = pz[pos + 3];
		pz[pos + 3] = 9;
		pos += 3;
	}
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << pz[3 * i + j] << ' ';
		}
		cout << endl;
	}
	cout << endl;
}
int main()
{
	stringstream strm;
	string input;
	getline(cin,input);
	strm << input;
	
	for (int i = 0; i < 9; i++)
	{
		strm >> pz[i];
		if (pz[i] == 9)
			pos = i;
	}
	getline(cin, input);
	for (int i = 0; i < input.length(); i++)
	{
		walk(input[i]);
	}
	return 0;
}