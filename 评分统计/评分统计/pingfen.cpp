#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	double a[11], ans(0);
	for (int i = 1; i <= 8; ++i)
	{
		cin >> a[i];
		ans += a[i];
	}
	ans -= *max_element(a + 1, a + 9);
	ans -= *min_element(a + 1, a + 9);
	cout <<"平均成绩是"<< ans/6;
	return 0;
}