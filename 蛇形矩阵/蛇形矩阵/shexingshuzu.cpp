#include <iostream>
#include <cmath>
using namespace std;
int ans(0);
int a[101][101];
void move(int &x, int &y, const int mid);
int main()
{
	int n;
	cin >> n;
	int mid = n / 2 + 1;
	int x(mid), y(mid), t(0);
    while(x>=1&&x<=n&&y>=1&&y<=n)
	{
		a[x][y] = ++t;
		move(x, y, mid);
	}
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
			if (j != n)cout << a[j][i] << " ";
			else cout << a[j][i];
		cout << endl;
	}
	cout << ans;
	return 0;
}
void move(int &x, int &y, const int mid)
{
	static const int n = mid * 2 - 1;
	if (x == y&&x < mid) { ans += a[x][y]; ++y; return ; }
	if (x == y&&x > mid) { ans += a[x][y]; ++x; return; }
	if (x + y - 1 == n&&y < mid) { ans += a[x][y]; --x; return; }
	if ((x + y - 1 == n&&y > mid)||(x==y&&y==mid)) { ans += a[x][y]; ++x; return; }
	if (x < y&&x + y - 1 < n) { ++y; return; }
	if (x < y&&x + y - 1 > n) { ++x; return; }
	if (x > y&&x + y - 1 < n) { --x; return; }
	if (x > y&&x + y - 1 > n) { --y; return; }
}
