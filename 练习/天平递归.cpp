#include <iostream>
using namespace std;
//д�ݹ�����Ҫ�ľ��ǿ����ظ�!�Լ���д���ݹ���ʽ�����д����,����ʵ������
bool solve(int &w)//������Ҫ�ĵݹ��ر��������������!�൱��ÿ�ζ��ܷ�������ֵ,һ������ȷ��,һ��������֮��
{
	int W1, W2, D1, D2;
	cin >> W1 >> D1 >> W2 >> D2;
	bool b1 = true, b2 = true;
	if (!W1)b1=solve(W1);
	if (!W2)b2=solve(W2);
	w = W1 + W2;
	return b1 && b2 && (W1*D1 == W2 * D2);
}