/*5.3 ���ִ�������10λ��ί��Ϊÿλѡ�ִ�֣�double�ͣ���Ԥ�����ָ��ֵķ�����
Ϊȥ��1����߷֡�1����ͷֺ�����8��������ƽ��ֵ���������ָ��ֵķ�����Ϊȥ��2��
��߷֡�2����ͷֺ�����6��������ƽ��ֵ��ͨ����������10λ��ί�Ĵ�֣��Լ���ǰ��
���ĸ��׶Σ�Ԥ��������1��ʾ������������2��ʾ�����������У�ֻ�����������ݡ�����
�������㺯���������������ּ��㲿�ֱ�д����������ɡ�*/
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