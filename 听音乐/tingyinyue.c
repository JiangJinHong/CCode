#include <stdio.h>
float a[15];
void qsort(float *a, int left, int right)
{
	int i = left, j = left, k = right;
	float temp = a[right], tmp;
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
	float n1, n2, all;
	
	scanf("%f %f", &n1, &n2);
	all = n1 - n2;
	int i;
	for (i = 1; i <= 10; i++)
		scanf("%f", &a[i]);
	qsort(a, 1, 10);
	int t = 0;

	for (i = 1; i <= 10; i++)
	{
		all = all - a[i];
		if (all < 0)
		{
			t = i - 1;
			break;
		}
		if (i == 10 && all >= 0)t = 10;
	}
	if (t != 0)printf("%d\n", t);
	else printf("%d", t);
		for (i = 1; i <= t; i++)
		{
			if (i < t)printf("%.1f ", a[i]);
			else printf("%.1f", a[i]);
		}
	
	return 0;
}