#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int k=0;
	for (int i = 2; i <= sqrt(n); ++i)
		if (n%i == 0) { k = 1; break; }
	if (k == 1)cout << "\\n";
	else cout << "\\t";
	return 0;
}