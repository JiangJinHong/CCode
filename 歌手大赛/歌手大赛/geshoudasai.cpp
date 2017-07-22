/*5.3 歌手大奖赛共有10位评委，为每位选手打分（double型）。预赛部分歌手的分数，
为去掉1个最高分、1个最低分后其余8个分数的平均值；决赛部分歌手的分数，为去掉2个
最高分、2个最低分后其余6个分数的平均值。通过键盘输入10位评委的打分，以及当前处
于哪个阶段（预赛部分用1表示，决赛部分用2表示）。主函数中，只负责输入数据、调用
分数计算函数、输出结果，评分计算部分编写独立函数完成。*/
#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;
void jisuan1(double a[]);
void jisuan2(double a[]);
int main()
{
	double a[10] = { 0 };
	for (int i = 0; i <= 9; ++i)
		cin >> a[i];
	int stage;
	cin >> stage;
	if (stage == 1)jisuan1(a);
	if (stage == 2)jisuan2(a);
	return 0;
}
void jisuan1(double a[])
{
	sort(a, a + 10);
	double ans(0);
	for (int i = 1; i <= 8; ++i)
		ans += a[i];
	cout<< ans / 8;
}
void jisuan2(double a[])
{
	sort(a, a + 10);
	double ans(0);
	for (int i = 2; i <= 7; ++i)
		ans += a[i];
	cout<< ans / 6;
}