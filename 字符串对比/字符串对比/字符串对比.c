#include<stdio.h>
#include<string.h>
int main()

{
	char a[30], b[30];
	scanf("%s%s", a, b);
	if (strlen(a) != strlen(b))
		printf("1");
	else if (strcmp(a, b) == 0)
		printf("2");
	else if (strnicmp(a, b, 30) == 0)
		printf("3");
	else
		printf("4");
	return 0;
}