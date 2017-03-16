#include <iostream>
#include <cmath>
using namespace std;
long gcd(long a, long b);
int main()
{
	long a, b, m;
	cin >> a >> b;
	m = a*b;
	int tmp = 0;
	for (int i = a; i <= sqrt(m); ++i)
		if (m%i == 0 && gcd(i, m / i) == a)++tmp;
	cout << 2 * tmp;
	return 0;
}
long gcd(long a, long b)
{
	return b == 0 ? a : gcd(b, a%b);
}