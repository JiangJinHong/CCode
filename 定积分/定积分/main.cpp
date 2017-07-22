#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
bool cmp(int a, int b)
{
	return a > b;
}
int main()
{
	int n;
	cin >> n;
	int *p = new int[n]();
	int *t = p;
	for (int i = 1; i <= n; ++i,++t)
		cin >> *t;
	int value;
	cin >> value;
	sort(p, p + n, cmp);
	int tmp(1);
	t = p;
	while (*t > value)
		tmp++, ++t;
	//for (int i = 1; i <= n; ++i, ++t)
		//cout << *t<<' ';
	delete[]p;
	cout << tmp;
	return 0;
}