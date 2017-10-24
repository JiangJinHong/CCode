#include <iostream>
#include "LinkList.cpp"
int main()
{
	int a[] = { 4,5,3,0,2,7,1,8,6,11,10,9 };
	LinkList<int> t(a, sizeof(a) / sizeof(a[0]));
	t.PrintList();
	cout << endl << "--------------------------" << endl;
	cout << "数组长度为" << t.GetLength();
	cout << endl << "--------------------------" << endl;
	cout << "8在数组中位置" << t.Locate(8);
	cout << endl << "--------------------------" << endl;
	t.Insert(4, 12);
	cout << "插入12在第四个位置" << endl;
	t.PrintList();
	cout << endl << "--------------------------" << endl;
	t.Delete(4);
	cout << "删除第四个数" << endl;
	t.PrintList();
	cout << endl << "--------------------------" << endl;
	return 0;
}