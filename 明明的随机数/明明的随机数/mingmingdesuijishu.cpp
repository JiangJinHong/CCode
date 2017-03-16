#include <iostream>
#include <cstdlib>
using namespace std;
int compare(const void *a, const void *b)
{
	int *pa = (int*)a;
	int *pb = (int*)b;
	return (*pa) - (*pb);  //从小到大排序
}

int main()
{
	int a[1000] = { 0 };
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
	cin >> a[i];
	int tmp = 0;
	qsort(a, n, sizeof(int), compare);
	int k = 0;
	for(int i=0;i<n-1;++i)
	{
		if (a[i] == a[i + 1] && a[i] != 0) 
		{ 
			k = i + 1;
			while (a[k] == a[i]) { a[k] = 0; ++k; ++tmp; }
		}
	}
	cout << n - tmp << endl;
	for (int i = 0; i <= n; ++i)
		if (a[i] != 0)
		{
			if (i != n)cout << a[i] << " ";
			else cout << a[i];
		}
	return 0;
}