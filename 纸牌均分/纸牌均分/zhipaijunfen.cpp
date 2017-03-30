#include <iostream>
using namespace std;
int main()
{
	int n, a[101] = { 0 }, average(0), tmp(0);
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		cin >> a[i];
		average += a[i];
	}
	average /= n;
	for (int i = 1; i <= n - 1; ++i)
	{
		if (a[i] != average) { a[i + 1] -= average - a[i]; ++tmp; }
	}
	cout << tmp;
	return 0;
}