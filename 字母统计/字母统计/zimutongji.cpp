#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
using namespace std;
char a[1000];
int tmp[26];
void jisuan()
{
	for (int i = 0; i <= strlen(a) - 1; ++i)
	{
		if (a[i] - 'a' >= 0 && a[i] - 'a' <= 25)tmp[a[i] - 'a']++;
		if (a[i] - 'A' >= 0 && a[i] - 'A' <= 25)tmp[a[i] - 'A']++;
	}
}
int main()
{
	std::ios::sync_with_stdio(false);
	int n;
	cin >> n;
	getchar();
	for (int i = 1; i <= n; ++i)
	{
		cin.getline(a, 999);
		jisuan();
		memset(a, sizeof(a), 0);
	}
	int k = 0;
	for (int i = 0; i <= 25; ++i)
	{
		if (tmp[i]) { cout << char(i + 'a') << ':' << tmp[i] << '\n'; k = 1; }

	}
	if (!k)cout << "×Ö·û´®ÖÐÎÞ×ÖÄ¸¡£"<<endl;
	return 0;


}
