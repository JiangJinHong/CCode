#include <iostream>
#include <fstream>

#include "linklist.h"

void Warn(int a)
{
	if (a % 5 == 0)
	{
		cout << "\n��ѡ����Ҫ���еĲ�����������ţ�\n1.�鿴��ǰͨѶ¼\n2.��ѧ��/������ѯĳ��\n3.��ѧ��/����ɾ��ĳ����Ϣ\n";
		cout << "4.���һ��ѧ������Ϣ\n5.�˳���������\n6.�˳�������\n7.�鿴��ʾ��Ϣ\n" << endl;
	}
}


int main()
{
	cout << "��ӭʹ��ͨѶ¼" << endl;
	cout << "���ݼ�����..." << endl;
	ifstream ifile("in.txt");

	int n(0);
	ifile >> n;
	DataType *b=new DataType[n];
	for (int i = 0; i < n; ++i)
	{
		ifile >> b[i].ID >> b[i].name >> b[i].ch >> b[i].phone;
		ifile.getline(b[i].addr,32);
	}
	LinkList t(b, n);
	/*
	for (int i = 0; i < n; ++i)
	{
		cout << a[i].ID <<" "<< a[i].name <<" "<< a[i].ch <<" "<< a[i].phone <<" "<< a[i].addr<<endl;
	}
	*/
	delete[]b;
	cout << "���ݼ������!"<<endl;
	
	char temp[80];
	int tmp(0);
	int condition(7);
	while (true) 
	{
		switch (condition)
		{
		case 1:
			t.PrintList();
			break;
		case 2:
			cout << "��������Ҫ��ѯ��ѧ��/����" << endl;
			cin >> temp;
			t.Check(temp);
			break;
		case 3:
			cout << "��������Ҫɾ����ѧ����ѧ��/����" << endl;
			cin >> temp;
			t.Delete(temp);
			--n;
			cout << "��ɾ��" << temp << "����Ϣ"<<endl;
			break;
		case 4:
			cout << "�밴��ѧ�������Ա�绰��ַ��˳������ѧ����Ϣ���м���'��'����" << endl;
			getchar();
			cin.getline(temp,80,'\n');
			t.Modify(temp);
			++n;
			cout << "��Ϣ¼��ɹ���"<<endl;
			break;
		case 5:
		{
			cout << "ͨѶ¼���˳���û�б��棡" << endl;
			return 0;
		}
			break;

		case 6:
		{
			ofstream ofile("in.txt", std::ios::trunc);
			DataType *a = new DataType[n];
		t.SaveList(a);
		ofile << n << endl;
		for (int i = 0; i < n; ++i)
		{
			ofile << a[i].ID << " " << a[i].name << " " << a[i].ch << " " << a[i].phone << " " << a[i].addr << endl;
		}
		delete[]a;
	
		cout << "ͨѶ¼�ѱ��沢�˳���" << endl;
		return 0;
		}
			break;
		case 7:
			cout << "\n��ѡ����Ҫ���еĲ�����������ţ�\n1.�鿴��ǰͨѶ¼\n2.��ѧ��/������ѯĳ��\n3.��ѧ��/����ɾ��ĳ����Ϣ\n";
			cout << "4.���һ��ѧ������Ϣ\n5.�˳���������\n6.�˳�������\n7.�鿴��ʾ��Ϣ\n"<<endl;
			break;
		default:
			cout << "����ָ�����򲻴��ڣ�����������" << endl;
			++tmp;
			Warn(tmp);
			
			break;
		}
		if (condition != 7)condition = 7;
		while (!(cin >> condition))
		{
			
			cin.clear();
			while (cin.get() != '\n')
			{
				continue;
			}
			cout << "����ָ�����򲻴��ڣ�����������"<<endl;
			tmp++;
			Warn(tmp);
		}
	}
	


}