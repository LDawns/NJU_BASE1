//一个字符串的所有字串中
//最长的回文串作为value
//value越小安全性越高
//M为字母表中前M个字母
//N为密码长度
#include <iostream>
#include <string>
using namespace std;
int n;
string solve(int M, int N)
{
	string result;
	if (M == 1)for (int i = 0; i < N; i++)result += "a";
	else if (N == 1)result += "a";
	else if (M == 2)
	{
		if (N == 2)result = "ab";
		else if (N == 3)result = "aab";
		else if (N == 4)result = "aabb";
		else if (N = 5)result = "aaaba";
		else if (N = 6)result = "aaabab";
		else if (N = 7)result = "aaababb";
		else if (N = 8)result = "aaababbb";
		else
		{
			result += "aa";
			N -= 2;
			int sn = N / 6;
			for (int i = 0; i < sn; i++)
			{
				result += "aababb";
			}
			if (N % 6 == 1)result += "a";
			else if (N % 6 == 2)result += "aa";
			else if (N % 6 == 3)result += "aaa";
			else if (N % 6 == 4)result += "aaaa";
			else if (N % 6 == 5)result += "aabab";
		}
	}
	else if (M >= 3)
	{

	}
	return result;
}
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int M, N;
		cin >> M >> N;
		string result = solve(M, N);
		cout << "Case #" << i + 1 << ": " << result << '\n';
	}
	return 0;
}