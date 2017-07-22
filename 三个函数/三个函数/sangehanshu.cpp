/*
5.2 编写三个函数，分别完成如下任务：
函数一，计算整数a除以整数b的商的整数部分；
函数二，计算整数a除以整数b的余数；
函数三，用函数一和函数二完成分离整数各位的功能，对于输入的1～32767之间的整数，
打印出一列数字，每个数字间空一个格。例如，输入：4562  输出：4 5 6 2
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