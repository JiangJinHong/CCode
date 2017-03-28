#include <iostream>
using namespace std;
int a[20][3];
void front(int k);
void middle(int k);
void behind(int k);
int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> a[i][1] >> a[i][2];
	front(1);
	cout << endl;
	middle(1);
	cout << endl;
	behind(1);
	return 0;
}
void front(int k)
{
	cout << k << " ";
	if (a[k][1])front(a[k][1]);
	if (a[k][2])front(a[k][2]);
}
void middle(int k)
{
	if (a[k][1])middle(a[k][1]);
	cout << k << " ";
	if (a[k][2])middle(a[k][2]);
}
void behind(int k)
{
	if (a[k][1])behind(a[k][1]);
	if (a[k][2])behind(a[k][2]);
	cout << k << " ";
}