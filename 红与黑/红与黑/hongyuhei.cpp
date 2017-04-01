#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
char a[100][100] = { 0 };
bool h[100][100] = { 0 };
int tmp(0);
void dfs(int n,int m,int ti,int tj);
int main()
{
	
	int n, m;
	int ti, tj;
	while (1)
	{
		cin >> m >> n;
		if (!n && !m)return 0;
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= m; ++j)
			{
				cin >> a[i][j];
				if (a[i][j] == '@') { ti = i; tj = j; }
			}
		h[ti][tj] = 1;
		dfs(n,m,ti,tj);
		cout << tmp+1 << endl;
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= m; ++j)
			{
				a[i][j] =h[i][j]= 0;
			}
		tmp = 0;
	}
	return 0;
}
void dfs(int n, int m,int ti,int tj)
{
	if (ti + 1 <= n && !h[ti + 1][tj] && a[ti + 1][tj] == '.') 
	{
		++tmp; h[ti + 1][tj] = 1; dfs(n, m, ti + 1, tj);
	}
	if (ti - 1 >= 1 && !h[ti - 1][tj] && a[ti - 1][tj] == '.')
	{
		++tmp; h[ti - 1][tj] = 1; dfs(n, m, ti - 1, tj);
	}
	if (tj - 1 >= 1 && !h[ti][tj - 1] && a[ti][tj - 1] == '.')
	{
		++tmp; h[ti][tj - 1] = 1; dfs(n, m, ti, tj - 1);
	}
	if (tj + 1 <=m  && !h[ti][tj +1] && a[ti][tj + 1] == '.')
	{
		++tmp; h[ti][tj + 1] = 1; dfs(n, m, ti, tj + 1);
	}
}