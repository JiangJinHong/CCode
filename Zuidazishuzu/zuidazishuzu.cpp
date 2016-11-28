#include <iostream>
#include <limits.h>
using namespace std;
int cross_middle(int *a, int l, int m, int r)
{
	int i,sum = 0,l_max = INT_MIN,r_max = INT_MIN;
	for (i = m; i >= l; i--)
	{
		sum += a[i];
		if (sum > l_max) l_max = sum;
	}
	sum = 0;
	for (i = m + 1; i <= r; i++) 
	{
		sum += a[i];
		if (sum>r_max) r_max = sum;
	}
	return (l_max + r_max);
}
int FMaxSubarray(int *a, int l, int r) 
{
	if (l == r) return a[l];
	int m = (l + r) / 2,
		l_max, r_max, m_max;
	l_max = FMaxSubarray(a, l, m);
	r_max = FMaxSubarray(a, m + 1, r);
	m_max = cross_middle(a, l, m, r);
	if (l_max >= r_max && l_max >= m_max) return l_max;
	  else if (r_max >= m_max) return r_max;
	    else return m_max;
}
int main() 
{
	int b[1000] ;
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> b[i];
	cout << FMaxSubarray(b, 1, n);
	return 0;
}