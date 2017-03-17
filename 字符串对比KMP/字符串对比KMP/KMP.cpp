#include <iostream>
#include <cstring>
using namespace std;
void NEXT(char x[],int Ipre[]);
int max(int a, int b);
int main()
{
	char a[10000], b[1000];
	int Ipre[1000];
	cin >> a >> b;
	NEXT(b,Ipre);
	//for (int i = 0; i <= strlen(b)-1; ++i)
		//cout << Ipre[i];
	int k = 0;
	for(int i=0;i<=strlen(a)-strlen(b);)
		for (int j = 0; j <= strlen(b) - 1; ++j)
		{
			if (a[i + j] != b[j])
			{
				i = i + max(j - Ipre[j], 1);
				break;
			}
			if (j == (strlen(b) - 1))
			{ cout << i+1; return 0; }
		}
	cout << "error";
	return 0;
}
void NEXT(char x[],int Ipre[])
{
	Ipre[0] = 0;
	for (int i = 1; i<strlen(x); ++i)
	{
		int k = Ipre[i - 1];
		while (x[i] != x[k] && k != 0)
			k = Ipre[k - 1];     
		if (x[i] == x[k])
			Ipre[i] = k + 1;
		else
			Ipre[i] = 0;       
	}

}
int max(int a,int b)
{
	return a > b ? a : b;
}