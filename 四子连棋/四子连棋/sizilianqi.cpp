#include <iostream>
#include <algorithm>
#define MAX_A 5
#define Black 66
#define White 87
#define Empty 79
#define Debug
using namespace std;
const int mov[8][2]{ {1,0},{-1,0},{0,1},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1} };
int main()
{
	//init
	char a(0);
	int b[MAX_A][MAX_A];
	//in
	int k(0);
	for (int i = 1; i <= 4; ++i)
		for (int j = 1; j <= 4; ++j)
		{
			cin >> a;
			b[i][j] = a;
		}
	
#ifdef Debug
	for (int i = 1; i <= 4; ++i)
	{
		for (int j = 1; j <= 4; ++j)
			cout << b[i][j] << ' ';
		cout << '\n';
	}
#endif
	return 0;
}
	//dfs
void dfs(int k,int color)
	{
		pd();
		for (int i = 1; i <= 4; ++i)
			for (int j = 1; j <= 4; ++j)
			{
				if (b[i][j] == Empty)
				{
					for (int k = 0; k <= 3; ++k)
						if (b[i + mov[k][0]][j + mov[k][1]] == Black)

				}

			}
	}


