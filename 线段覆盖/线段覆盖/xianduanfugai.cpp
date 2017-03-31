#include <iostream>
#include <algorithm>
using namespace std;
struct seg { int l, r; }a[105];
bool cmp(seg x,seg y)
{
	return x.r < y.r;
}
int main()
{
	int n, tmp(1);
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		cin >> a[i].l >> a[i].r;
		if (a[i].l > a[i].r)swap(a[i].l, a[i].r);
	}
	sort(a + 1, a + n + 1,cmp);
	int mr = a[1].r;
	for(int i=1;i<=n;++i)
		if (a[i].l >= mr) { mr = a[i].r; ++tmp; }
	cout << tmp;
	return 0;
}