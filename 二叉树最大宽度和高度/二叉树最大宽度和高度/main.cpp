#include<iostream>
using namespace std;
int a[17][2];
int width[1000];//������¼ÿһ��Ŀ��
int x = 0, deep = 0, height = 0;//deep������¼��ǰ�߶ȣ�height������¼���߶�
void dfs(int i, int deep)
{
	
	if (deep > height)
		height = deep;
	++width[deep];
	if (a[i][0])
		dfs(a[i][0], deep + 1);
	if (a[i][1])
		dfs(a[i][1], deep + 1);
}
int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> a[i][0] >> a[i][1];

	dfs(1, 1);
	for (int i = 1; i <= 1000; ++i)
	{
		if (width[i] > x)
			x = width[i];
	}
	cout << x << " " << height;
}