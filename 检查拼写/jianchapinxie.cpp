#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;
int h[105];
int main()
{
	int n,j,k;
	char a[25];
	char b[25][101];
	cin >> a;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> b[i][0];
	for (j = 1; j <= n; j++)
		for ( k = 0; k <= strlen(a) - 1; k++)
			if (a[k] == b[k][j])h[j]++;
	int max = -1;
	int t = 0;
	int a1;
	for ( a1 = n; a1 >= 1; a1--)
		if (h[a1] > max)
		{
			max = h[a1];
			t = a1;
		}
	int i=0;
	if (max >= n-1)
		while (b[i][t] != 'NULL')
		{
			cout << b[i][t];
			i++;
		}
	else 
	{
		cout << "NOANSWER";	
	}
	return 0;
}