#include <iostream>
using namespace std;
long long gcd(long long a, long long b);
int main()
{
	long long a, b;
	cin >> a >> b;
	cout<<gcd(a, b);
	return 0;
}
long long gcd(long long a, long long b)
{
	return b == 0 ? a : gcd(b, a%b);
}