#include <stdio.h>
void qsort(int *a, int left, int right)
{
	int i = left, j = left, k = right, temp = a[right], tmp;
	for (j; j < k; j++)
	{
		if (a[j] <= temp)
		{
			tmp = a[j];
			a[j] = a[i];
			a[i] = tmp;
			i++;
		}
	}
	a[right] = a[i];
	a[i] = temp;
	if (left < i - 1)qsort(a, left, i - 1);
	if (i + 1 < right)qsort(a, i + 1, right);
}
int main()
{
	int n, i;
	int a[1000];
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	qsort(a, 1, n);
	for (i = 1; i <= n; i++)
		printf("%d ", a[i]);
	return 0;
}