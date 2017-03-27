#include <iostream>
using namespace std;
int calculate(int t,int &a,int &b);
void dfs(int k,int n[]);
bool visit[5] = { 0 };
int ans(0);
int main()
{
	int n[5] = { 0 };
	cin >> n[1] >> n[2] >> n[3] >> n[4];
	dfs(1,n);
	return 0;
}
int calculate(int t,int &a,int &b)
{
	if (t == 1)return a + b;
	if (t == 2)return a - b;
	if (t == 3)return a * b;
	if (t == 4)return a / b;
}
void dfs(int k,int n[])
{
	if (k == 4)return;
	
	for (int i = 1; i <= 4; ++i)
	{
		if(!visit[])ans+=calculate(i, n[k], n[k + 1]);
	}
}