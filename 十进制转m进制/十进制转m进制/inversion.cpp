#include <iostream>
using namespace std;
void inversion(int n, int m);
int main()
{
	int n,m;
	cin >> n >> m;
	inversion(n, m);
	return 0;
}
void inversion(int n, int m)
{
	int a;
	if (n == 0)
		return ;
	a = n%m;
	n = n/m;
	inversion(n, m);
	if (a >= 10)cout << char('A' + a - 10);
	else cout << a;
}