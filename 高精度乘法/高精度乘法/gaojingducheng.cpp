#include <iostream>
#include <string>
#define MAX_A 1002
using namespace std;
string a, b;
void HAAcheng(short a1[], short b1[], short ans[])
{
	for(int i=1;i<=a.size();++i)
		for (int j = 1; j <= b.size(); ++j)
		{
			ans[j + i - 1] += b1[j] * a1[i];
			if (ans[j + i - 1] >= 10) 
			{
				ans[j + i] += ans[j + i - 1] / 10;
			    ans[j + i - 1] %= 10;
			}
		}
}
int main()
{
	short a1[MAX_A] = { 0 }, b1[MAX_A] = { 0 }, ans[MAX_A] = { 0 };
	cin >> a >> b;
	int k(0);
	for (int i = a.size(); i >= 1; --i)
		a1[i] = a[k++] - 48;
	k = 0;
	for (int i = b.size(); i >= 1; --i)
		b1[i] = b[k++] - 48;
	HAAcheng(a1, b1, ans);

	k = MAX_A - 1;
	while (!ans[k])k--;
	for (int i = k; i >= 1; --i)
		cout << ans[i];
	return 0;
}