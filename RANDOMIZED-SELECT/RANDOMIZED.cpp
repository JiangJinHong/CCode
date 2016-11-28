#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int RANDOMIZED_SELECT(int *a, int l, int r, int i);
int main()
{
	int a[1000];
	int n,t;
	cin >> n;
	cin >> t;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	cout << RANDOMIZED_SELECT(a, 1, n, t);
	return 0;
}

int RANDOMIZED_SELECT(int *a, int left, int right, int x)
{
	  if (left == right)return a[left];
	    srand(time(NULL));
		int i = left, j = left, k = right, tmp,
			s = (rand() % (k - j + 1)) + j;
		tmp = a[k];
		a[k] = a[s];
		a[s] = tmp;
		int temp = a[k];
		for (j; j < k; j++)
		{
			if (a[j] <= temp)
			{
				tmp = a[i];
				a[i] = a[j];
				a[j] = tmp;
				i++;
			}
		}
		a[right] = a[i];
		a[i] = temp;
		int f = i - left + 1;
		if (x == f)return a[i];
		else if (x < f)return RANDOMIZED_SELECT(a, left, i - 1, x);
		else return RANDOMIZED_SELECT(a, i + 1, right, x - f);
}
