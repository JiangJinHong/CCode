/*5.1 ��д�������ѻ����¶�F��double�ͣ�ת��Ϊ�����¶�C��double�ͣ�
����ʽΪC = (F - 32) / 1.8��
��������һ�������¶ȣ����Եõ���Ӧ�������¶ȡ�
*/

#include <iostream>
using namespace std;
int main()
{
	double C, F;
	cin >> F;
	C = (F - 32) / 1.8;
	cout << C;
	return 0;
}