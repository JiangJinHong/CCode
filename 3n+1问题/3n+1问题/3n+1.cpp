#include <iostream>
using namespace std;
int pd(int k);
int tmp = 0;
int main()
{
	int n;
	cin >> n;
	int a[101];
	for (int i = 1; i <= n; ++i)
	{
		cin >> a[i];
		cout << pd(a[i]) << endl;
		tmp = 0;
	}

	return 0;
}
int pd(int k)
{
	if (k == 1)return tmp;
	if (tmp >= 1000)return -1;
	if (k % 2 == 0) { ++tmp; pd(k / 2); }
	else { ++tmp; pd(3 * k + 1); }
	return tmp;  
}


