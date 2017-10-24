#include <iostream>
#include <fstream>

#include "linklist.h"

void Warn(int a)
{
	if (a % 5 == 0)
	{
		cout << "\n请选择需要进行的操作并输入序号：\n1.查看当前通讯录\n2.按学号/姓名查询某人\n3.按学号/姓名删除某条信息\n";
		cout << "4.添加一个学生的信息\n5.退出但不保存\n6.退出并保存\n7.查看提示信息\n" << endl;
	}
}


int main()
{
	cout << "欢迎使用通讯录" << endl;
	cout << "数据加载中..." << endl;
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
	cout << "数据加载完成!"<<endl;
	
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
			cout << "请输入需要查询的学号/姓名" << endl;
			cin >> temp;
			t.Check(temp);
			break;
		case 3:
			cout << "请输入需要删除的学生的学号/姓名" << endl;
			cin >> temp;
			t.Delete(temp);
			--n;
			cout << "已删除" << temp << "的信息"<<endl;
			break;
		case 4:
			cout << "请按照学号姓名性别电话地址的顺序输入学生信息，中间用'，'隔开" << endl;
			getchar();
			cin.getline(temp,80,'\n');
			t.Modify(temp);
			++n;
			cout << "信息录入成功！"<<endl;
			break;
		case 5:
		{
			cout << "通讯录已退出但没有保存！" << endl;
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
	
		cout << "通讯录已保存并退出！" << endl;
		return 0;
		}
			break;
		case 7:
			cout << "\n请选择需要进行的操作并输入序号：\n1.查看当前通讯录\n2.按学号/姓名查询某人\n3.按学号/姓名删除某条信息\n";
			cout << "4.添加一个学生的信息\n5.退出但不保存\n6.退出并保存\n7.查看提示信息\n"<<endl;
			break;
		default:
			cout << "输入指令错误或不存在！请重新输入" << endl;
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
			cout << "输入指令错误或不存在！请重新输入"<<endl;
			tmp++;
			Warn(tmp);
		}
	}
	


}