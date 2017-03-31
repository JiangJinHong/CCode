#include <iostream>
#include <algorithm>
using namespace std;
struct xian { int l, r, v; };
bool cmp(xian x, xian y);
int main()
{
	//init
	int n;
	xian a[1001] = { 0 };
	int dp[1001] = { 0 };
	
	//in
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> a[i].l >> a[i].r >> a[i].v;
	
	//sort
	sort(a + 1, a + n + 1, cmp);

	//dp
	int ans(a[1].v);
	int maxa;
	for (int i = 1; i <= n; ++i)
	{
		maxa = 0;
		for (int j = 1; j <= i; ++j)
			if (a[j].r <= a[i].l&&a[j].v > maxa)
				maxa = a[j].v;
		a[i].v += maxa;
		ans = max(ans, a[i].v);
	}

	//out 
	cout << ans;
	return 0;
}
bool cmp(xian x, xian y)
{
	return x.r < y.r;
}