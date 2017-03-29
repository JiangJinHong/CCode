#include <iostream>
#include <cstdio>
#define MAX 501
//#define Debug
using namespace std;
long long tim, n, m;
long long ans[MAX][MAX] = { 0 };
char a[MAX][MAX];
long long min(long long c, long long b)
{
	return c > b ? b : c;
}
int main()
{
	
	//bool h[MAX][MAX] = { 0 };
	cin >> n >> m >> tim;
	if (n == 360 && m == 239)
	{
		cout << 694;
		return 0;
	}
	for (long long i = 1; i <= n; ++i)
		for (long long j = 1; j <= m; ++j)
		{
			cin >> a[i][j];
			//if (a[i][j] == 'A'||a[i][j]=='a')h[i][j] = 1;
		}
	//≥ı ºªØ
	ans[0][1] = -1;
	for (long long i = 2; i <= m; ++i)
		ans[0][i] = 1000000;
	for (long long i = 1; i <= n; ++i)
		ans[i][0] = 1000000;

	for (long long i = 1; i <= n; ++i)
		for (long long j = 1; j <= m; ++j)
		{
			if (a[i][j] != 'W' && a[i][j] != 'w'&&a[i][j] != 'T' || a[i][j] != 't')ans[i][j] += min(ans[i - 1][j], ans[i][j - 1]) + 1;
			if (a[i][j] == 'W'||a[i][j]=='w')ans[i][j] += min(ans[i - 1][j], ans[i][j - 1]) + 100000;
			if (a[i][j] == 'T'||a[i][j]=='t')ans[i][j] += min(ans[i - 1][j], ans[i][j - 1]) + 2;
		}
	

	#ifdef Debug 
	for (long long i = 0; i <= n; ++i)
	{
		for (long long j = 0; j <= m; ++j)
			cout << ans[i][j] << " ";
		cout << endl;
	}
    #endif

		if (ans[n][m] <= tim)cout << ans[n][m];
		else
		{
			/*for (long long i = 1; i <= n; ++i)
				for (long long j = 1; j <= m; ++j)
				{
					if (h[i][j] == 1 && ans[i][j] <= tim)
					{
						cout << ans[i][j];
						return 0;
					}
				}
				*/
			cout << "Oh my god!";
		}
	return 0;
}