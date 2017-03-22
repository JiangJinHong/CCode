#include <iostream>
using namespace std;
int digui(int n);
int main()
{
	int n;
	cin >> n;
	cout<<digui(n);
	return 0;
}
int digui(int n)
{
	if (n >= 0)return 5;
	else return digui(n + 1) + digui(n + 2) + 1;
}