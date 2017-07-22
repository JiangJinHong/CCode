#include <iostream>
#define ArraySize 100
using namespace std;
void scan_d(int &ret);
int main()
{
	std::ios::sync_with_stdio(false);
	int n;
	int a[ArraySize];
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		scan_d(a[i]);
	}
	for (int i = 1; i <= n; ++i)
	{
		cout << a[i];
	}
	return 0;
}
void scan_d(int &ret)
{
	char c;
	ret = 0;
	while ((c = getchar()) < '0' || c > '9');
	while (c >= '0'&&c <= '9') ret = ret * 10 + (c - '0'), c = getchar();
}