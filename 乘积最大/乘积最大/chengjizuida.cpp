#include <iostream>
using namespace std;
int N, K;
long long ans = 1, maxans = 1;
char a[100];
bool ab[100];
void mark(int t)
{
	ab[t] = 1;
}
void unmark(int t)
{
	ab[t] = 0;
}
void jisuan()
{
	long long res = 0;
	for (int i = 0; i <= N - 1; ++i)
	{
	    res = res * 10 + int(a[i] - '0');
		if (ab[i]) 
		{
			ans *= res;
			res = 0;
		}
	}
	if (maxans < ans)maxans = ans;
	ans = 0;
}
int main()
{
	cin >> N >> K;
	cin >> a;
	if (K == 1)
		for (int i = 0; i <= N - 2; ++i)
		{
			mark(i);
			jisuan();
			unmark(i);
		}
	cout << maxans;
	return 0;
}