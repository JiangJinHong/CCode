#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int a[21] = { 0 }, ans[21] = { 0 }, n(1);
	while (cin >> a[n])++n;
	
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j < i; ++j)
			if (a[j] > a[i])ans[i] = max(ans[j] + 1, ans[i]);
	cout << *max_element(ans + 1, ans + n + 1) << endl;

	for (int i = 1; i <= n; ++i)
		ans[i] = 1;

	for (int i = 1; i <= n; ++i)
		for (int j = 1; j < i; ++j)
			if (a[j] < a[i])ans[i] = max(ans[j] + 1, ans[i]);
	cout << *max_element(ans + 1, ans + n + 1);
	return 0;
}