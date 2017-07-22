#include<iostream>
using namespace std;
int main()
{
	int i, j;
	int a[100] = { 3,4,6,8,12,14,18,20,24,30,32,38,42,44,48,54,60,62,68,72,74,80,84,90,98 };
	for (i = 1; i <= 100; i++)
	{
		if (i % 10 == 0)
		{
			cout << i << endl;
		}
		else
		{
			cout << i << " ";
		}
	}
	j = 1;
	for (i = 0; i <= 24; i++)
	{

		if (j % 10 == 0)
		{
			cout << a[i] << endl;
		}
		else
		{
			cout << a[i] << " ";
		}
		j++;
	}
	cout << endl;
	return 0;
}
