#include <iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int k(n),t(1);
	while (k > 0)
	{
		k -= t;
		++t;
	}
	k += t-1;
	if((t+1)%2==0)cout << k << "/" << t  - k;
	else cout << t-k << "/" << k;
	return 0;
}