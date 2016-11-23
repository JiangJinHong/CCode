#include <stdio.h>
int h[105][6];//[0]boolean,[1]length,[2]'A',[3]'a',[4]'1',[5]'~';
char a[105][53];
int n;
void check(int i)
{
	int j = 1, lenth = 0, t = 0;
	if (i == n)t = 1;
	while (a[i][j] != '\0')
	{
		     if (a[i][j] <= 90 && a[i][j] >= 65)h[i][2] = 1;
		else if (a[i][j] <= 122 && a[i][j] >= 97)h[i][3] = 1;
		else if(a[i][j] <= 57 && a[i][j] >= 48)h[i][4] = 1;
		else h[i][5] = 1;
		j++;
		lenth++;
	}
	if (lenth < 6 && t) { printf("NO"); return ; }
	if (lenth < 6 && !t) {printf("NO\n"); return ;}
	if (h[i][2] + h[i][3] + h[i][4] + h[i][5] >= 3)h[i][0] = 1;
	if (h[i][0] == 1 && t)printf("YES");
	if (h[i][0] == 1 && !t)printf("YES\n"); 
	if (h[i][0] == 0 && t)printf("NO");
	if (h[i][0] == 0 && !t)printf("NO\n");
}
int main()
{
	int i;
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
		scanf("%s", &a[i][1]);
	for (i = 1; i <= n; i++)
		check(i);
	//for (i = 1; i <= n; i++)
	//	printf("%s\n", &a[i][1]);

	return 0;
}