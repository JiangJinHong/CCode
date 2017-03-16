#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;
int main()
{
	char a[101];
	int t;
	cin.getline(a,100);
	//cout << strlen(a);
	for(int i=strlen(a)-1;i>=0;--i)
		if (a[i] == ' ') 
		{
			t = i + 1;
			while (a[t] != ' '&&t<=strlen(a)-1)
			{
				cout << a[t++];
			}
			cout << " ";
		}
	t = 0;
	while (a[t] != ' ')
		cout << a[t++];
	return 0;
}