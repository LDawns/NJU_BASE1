#include <iostream>
using namespace std;
//写递归最重要的就是看到重复!以及能写出递归表达式最好先写出来,具体实现再议
bool solve(int &w)//及其重要的递归特别是引用这个符号!相当于每次都能返回两个值,一个是正确性,一个是重量之和
{
	int W1, W2, D1, D2;
	cin >> W1 >> D1 >> W2 >> D2;
	bool b1 = true, b2 = true;
	if (!W1)b1=solve(W1);
	if (!W2)b2=solve(W2);
	w = W1 + W2;
	return b1 && b2 && (W1*D1 == W2 * D2);
}