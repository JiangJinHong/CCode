#include <stdio.h>
#include <string.h>
char mw[110], my[110], ans[110];
int main()
{
	scanf("%s", mw);
	scanf("%s", my);
	int length_mw = strlen(mw), length_my = strlen(my);
	int i = length_my ;
	while (i <= length_mw - 1)
	{
		my[i] = my[i - length_my];
		i++;
	}
	for (i = 0; i < length_mw; i++)
		mw[i] -= 69;
	for (i = 0; i < length_mw; i++)
		my[i] -= 96;
	for (i = 0; i < length_mw; i++)
		ans[i]=mw[i]-my[i];
	for (i = 0; i < length_mw; i++)
	{
		ans[i] = (ans[i] % 26) + 96;
		printf("%c", ans[i]);
	}
	
	//printf("%s", my);

	return 0;
}