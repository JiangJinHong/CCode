#include <iostream>
using namespace std;
//�����������
int dfs(int k, int t);
int main()
{
	int n;
	cin >> n;
	cout << dfs(n, 1);

	return 0;
}
int dfs(int k, int t)
{
	static int ans = 0;
	if (k == 0) { return ++ans; }//�˻�����
	for (int i = t; i <= k; ++i)
		dfs(k - i, i);
	return ans;
}