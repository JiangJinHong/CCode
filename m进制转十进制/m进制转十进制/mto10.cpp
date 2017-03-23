#include <iostream>
#include <string>
#include <cmath>
using std::cin;
using std::cout;
using std::string;
int k(char c)
{
	if (c >= 48 && c <= 57)
		return c - 48;
	if (c >= 65 && c <= 90)
		return 10 + static_cast<int>(c - 65);
}
int main()
{
	string s1;
	int n;
	cin >> s1 >> n;
	int lenth = s1.size(), ans(0), t(0);
	for (int i=lenth-1;i>=0;--i)
	{
		ans += static_cast<int>(pow(n, t++))*(k(s1[i]));
	}
	cout << ans;
	return 0;
}