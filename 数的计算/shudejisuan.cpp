#include <iostream>
using namespace std;
void digui(int i);
int tmp = 0;
int main()
{
	int n;
	cin >> n;
	digui(n);
	cout << tmp;
	return 0;
}
void digui(int i)
{
	tmp++;
	for (int j = 1; j <= i / 2; ++j)
		digui(j);
}