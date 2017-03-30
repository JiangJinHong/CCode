#include <iostream>
#include <string>
#define MAX_A 501
using namespace std;
string a, b;
void HAAminus(short a1[], short b1[],short ans[],bool t)
{
	if (!t)ans[0] = 1;
	int k = (a.size() > b.size()) ? a.size() : b.size();
	int s;
	for (int i = 1; i <= k; ++i)
	{
		if (a1[i] < b1[i])
		{
			s = i + 1;
			while (!a1[s]&&s<=k)
			{
				a1[s++] = 9;
			}
			--a1[s];
           ans[i] = a1[i] + 10 - b1[i];
		}
		else ans[i] = a1[i] - b1[i];
	}
}
int main()
{
	short a1[MAX_A] = { 0 }, b1[MAX_A] = { 0 }, ans[MAX_A] = { 0 };
	
	cin >> a>> b;
	int k(0);
	for (int i = a.size(); i >= 1; --i)
 		a1[i] = a[k++]-48;
	k = 0;
	for (int i = b.size(); i >= 1; --i)
		b1[i] = b[k++] - 48;

	if (a.size() < b.size() || (a.size() == b.size() && a < b))HAAminus(b1, a1, ans, 0);
	else HAAminus(a1, b1, ans,1);

	k = MAX_A - 1;
	while (!ans[k])--k;
	if (ans[0])cout << '-';
	for (int i = k; i >= 1; --i)
		cout << ans[i];
	return 0;
}