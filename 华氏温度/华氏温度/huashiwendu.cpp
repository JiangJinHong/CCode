/*5.1 编写函数，把华氏温度F（double型）转换为摄氏温度C（double型）
，公式为C = (F - 32) / 1.8。
键盘输入一个华氏温度，可以得到相应的摄氏温度。
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