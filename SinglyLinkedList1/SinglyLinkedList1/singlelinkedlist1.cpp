#include <iostream>
#include "LinkList.cpp"
int main()
{
	int a[] = { 4,5,3,0,2,7,1,8,6,11,10,9 };
	LinkList<int> t(a, sizeof(a) / sizeof(a[0]));
	t.PrintList();
	cout << endl << "--------------------------" << endl;
	cout << "���鳤��Ϊ" << t.GetLength();
	cout << endl << "--------------------------" << endl;
	cout << "8��������λ��" << t.Locate(8);
	cout << endl << "--------------------------" << endl;
	t.Insert(4, 12);
	cout << "����12�ڵ��ĸ�λ��" << endl;
	t.PrintList();
	cout << endl << "--------------------------" << endl;
	t.Delete(4);
	cout << "ɾ�����ĸ���" << endl;
	t.PrintList();
	cout << endl << "--------------------------" << endl;
	return 0;
}