#include <iostream>
#include <cstdio>
using namespace std;
void swap(int *a, int x, int y)
{
	int tmp;
	tmp = a[x];
	a[x] = a[y];
	a[y] = tmp;
}
void MAX_HEAPIFY(int *a,int i,int n)
{
	int l = 2 * i, r = 2 * i + 1;
	int largest;
	if (l <= n&&a[l] > a[i])
		largest = l;
	else largest = i;
	if (r <= n&&a[r] > a[largest])
		largest = r;
	if(largest!=i)
	{
		swap(a, i, largest);
		MAX_HEAPIFY(a, largest, n);
	}
}
void BUILD_MAX_HEAP(int *a,int n)
{
	int k = n, i;
	for (i = n / 2; i >= 1; i--)
		MAX_HEAPIFY(a, i, n);
}
void HEAPSORT(int *a, int n)
{
	BUILD_MAX_HEAP(a, n);
	int i, k = n;
	for (i = n; i >= 2; i--)
	{
		swap(a, 1, i);
		k--;
		MAX_HEAPIFY(a, 1, k);
	}
}
int main()
{
	int i, n;
	int a[1000];
	cin >> n;
	for (i = 1; i <= n; i++)
		cin >> a[i];
	HEAPSORT(a, n);
	for (i = 1; i <= n; i++)
		cout << a[i] << ' ';
	return 0;
}