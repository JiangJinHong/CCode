#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int a[11];
	
	for (int i = 1; i <= 10; ++i)
		cin >> a[i];
	sort(a + 1, a + 11);

	for (int i = 1; i <= 10; ++i)
		cout << a[i]<<' ';
	return 0;
}