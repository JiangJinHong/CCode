#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int ans[5001] = { 0 }, a[5001] = { 0 };
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];

	for (int i = 1; i <= n; ++i)
		ans[i] = 1;

	for (int i = 1; i <= n; ++i)
		for (int j = 1; j < i; ++j)
			if (a[j] < a[i])ans[i] = max(ans[j] + 1, ans[i]);
	cout << *max_element(ans + 1, ans + n + 1);
	return 0;
}