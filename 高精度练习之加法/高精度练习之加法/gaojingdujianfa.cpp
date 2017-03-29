#include <iostream>
#include <string>
#define MAXAR 523
using namespace std;
int main()
{
	string a, b;
	short a1[MAXAR] = { 0 }, b1[MAXAR] = { 0 }, ans[MAXAR] = { 0 };
		cin >> a >> b;
		int k = 0;
		for (int i = a.size(); i >= 1; --i)
			a1[i] = static_cast<int>(a[k++] - 48);
		k = 0;
		for (int i = b.size(); i >= 1; --i)
			b1[i] = static_cast<int>(b[k++] - 48);
		 k = (a.size() > b.size()) ? a.size() : b.size();
		for (int i = 1; i <= k; ++i)
		{
			ans[i] += a1[i] + b1[i];
			if (ans[i] >= 10) { while (ans[i] >= 10) { ans[i] -= 10; ++ans[i + 1]; } }
		}
		k = MAXAR - 1;
		while (ans[k] == 0)--k;
		for (int i = k; i >=1 ; --i)
			cout << ans[i];
	return 0;
}