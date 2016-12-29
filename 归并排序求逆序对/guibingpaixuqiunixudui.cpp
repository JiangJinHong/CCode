#include <iostream>
#include <cstdlib>
using namespace std;
int a[1001];
int temp[1001];
int tmp = 0;
void MergeArray(int a[], int p, int mid, int r)
{
	int i = p, j = r, k = mid, l = mid + 1;
	int t = 1;
	while (i <= k && l <= j)
	{
		if (a[i] <= a[l])
		{
			temp[t++] = a[i++];
			
		}
		else
		{
			temp[t++] = a[l++];
			tmp += mid - i + 1;//计算逆序对数目
		}
	}
	while (i <= k)
		temp[t++] = a[i++];

	while (l <= j)
		temp[t++] = a[l++];

	for (int a1 = 1; a1 <= t-1; a1++)
		a[p + a1 - 1] = temp[a1];
	
}
void MergeSort(int a[], int p, int r)
{
	if (p == r)return;
	int mid = (p + r) / 2;
	MergeSort(a, p, mid);
	MergeSort(a, mid+1, r);
	MergeArray(a, p, mid, r);
}
int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	MergeSort(a, 1, n);
	for (int i = 1; i <= n; i++)
		cout << a[i] << " ";
	cout << endl;
	cout << tmp;
	return 0;
}