#include <iostream>
using namespace std;
int Fibonacci(int n);
int main()
{
	int n;
	cin >> n;
	cout << Fibonacci(n);
	return 0;
}
int Fibonacci(int n)
{
	if (n == 1)return 1;
	if (n == 2)return 1;
	else return Fibonacci(n - 1) + Fibonacci(n - 2);
}