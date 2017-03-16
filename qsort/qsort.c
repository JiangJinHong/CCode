#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void QSORT(int *a, int left, int right)
{
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
	if (left < i - 1)QSORT(a, left, i - 1);
	if (i + 1 < right)QSORT(a, i + 1, right);
}
int main()
{
	int n, i;
	int a[100001];
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	QSORT(a, 1, n);
	for (i = 1; i <= n; i++)
		printf("%d ", a[i]);
	return 0;
}