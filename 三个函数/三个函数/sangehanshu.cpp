/*
5.2 ��д�����������ֱ������������
����һ����������a��������b���̵��������֣�
����������������a��������b��������
���������ú���һ�ͺ�������ɷ���������λ�Ĺ��ܣ����������1��32767֮���������
��ӡ��һ�����֣�ÿ�����ּ��һ�������磬���룺4562  �����4 5 6 2
*/
#include <iostream>
using namespace std;
int f1(int a, int b);
int f2(int a, int b);
void f3(int n);
int main()
{
	int n;
	cin >> n;
	if (!n) { cout << 0; return 0; }
	f3(n);
	return 0;
}
inline int f1(int a, int b)
{
	return a / b;
}
inline int f2(int a, int b)
{
	return a%b;
}
void f3(int n)
{
	int t = 0;
	int a[20] = { 0 };
	while(n)
	{
		a[t++] = f2(n, 10);
		n = f1(n, 10);
	}
	for (int i = t - 1; i > 0; --i)
		cout << a[i] << ' ';
	cout << a[0];
}