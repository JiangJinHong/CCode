#include <iostream>
#include <cstdlib>
using namespace std;
void CountingSort(int *a,int n)
{
	
	int b[10010];//数组大小
	memset(b, 0, sizeof(b));
	for (int i = 1; i <= n; i++)//
		b[a[i]]++;
	int s = 1;
	for (int j = 1; j <= 9999; j++)//
	{
		while(b[j])
		{
			a[s++] = j;
			b[j]--;
		}
	}
}
int main()
{
	int n,a[10010];
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	CountingSort(a, n);
	for (int j = 1; j <= n; j++)
		cout << a[j] << ' ';
	return 0;
}