#include <cstdio>
int visit[15];
int a[15];
int n;
void out()
{
	for (int i = 0; i <= n - 1; ++i)
	{
		if (i != n - 1)printf("%d ", a[i]);
		else printf("%d\n", a[i]);
	}
}
void dfs(int k)
{
	for (int i = 1; i <= n; ++i)
	{
		if (!visit[i])
		{
			visit[i] = 1;
			a[n - k] = i;
			if (k != 1) { dfs(k - 1); }
			else { out(); }
			visit[i] = 0;
		}

	}

}
int main()
{
	scanf("%d", &n);
	dfs(n);
	return 0;
}