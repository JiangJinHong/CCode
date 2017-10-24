#include "linklist.h"
#include <cstring>
int StrToInt(char a[])
{
	int ans(0);
	char *p = &a[0];
	int i = 0;
	while (a[i])
	{
		ans *= 10;
		ans += (a[i++] - '0');
	}

	return ans;
}

LinkList::LinkList(DataType a[], int n)//头插法
{
	front = new DataType;
	front->next = NULL;
	for (int i = n - 1; i >= 0; --i)
	{
		DataType *s = new DataType;
		s->ID = a[i].ID;
		s->ch = a[i].ch;
		strcpy(s->name, a[i].name);
		strcpy(s->phone , a[i].phone);
		strcpy(s->addr, a[i].addr);
		s->next = front->next;
		front->next = s;
	}
}

LinkList::~LinkList()
{
	DataType *p = front;
	while (p)
	{
		front = p;
		p = p->next;
		delete front;
	}
}

void LinkList::Add(DataType a)
{
	DataType *p = front;
		DataType *s = new DataType;
		s->ID = a.ID;
		s->ch = a.ch;
		strcpy(s->name, a.name);
		strcpy(s->addr, a.addr);
		strcpy(s->phone, a.phone);
		s->next = p->next;
		p->next = s;
}

void LinkList::Delete(char a[])
{
	DataType *p = front->next;
	DataType *t = front;
	if ('0' <= a[0] && a[0] <= '9')
	{
		int temp = StrToInt(a);
		while (p)
		{
			if (p->ID == temp)break;
			p = p->next;
			t = t->next;
		}
	}
	else
	while (p)
	{
		if (strcmp(p->name,a)==0)break;
		p = p->next;
		t = t->next;
	}

	if (t) {
		t->next = p->next;
		delete p;
	}
	else cout << "不存在此数据" << endl;
}

void LinkList::Modify(char a[])
{
	DataType *p = front;
	DataType *s = new DataType;
	char temp[35];
	char*q = &a[0];
	if (p)
	{
		int i(0);
		while (*q!=',')
		{
			temp[i++] = *(q++);
		}
		temp[i] = '\0';
		++q;
		s->ID=StrToInt(temp);

			i = 0;
			while (*q != ',')
			{
				temp[i++] = *(q++);
			}
			temp[i] = '\0';
			strcpy(s->name, temp);
			++q;

			i = 0;
			while (*q != ',')
			{
				temp[i++] = *(q++);
			}
			temp[i] = '\0';
			s->ch = *(q - 1);
			++q;

		i = 0;
		while (*q != ',')
			{
				temp[i++] = *(q++);
			}
			temp[i] = '\0';
			strcpy(s->phone,temp);
			++q;

		i = 0;
		while (*q != '\n'&&*q!='\0')
			{
				temp[i++] = *(q++);
			}
			temp[i] = '\0';
			strcpy(s->addr,temp);
	}
	s->next = p->next;
	p->next = s;
}
void LinkList::Modify(char a[], char b[], char c[])
{
	DataType *p = front->next;
	while (p)
	{
		if (strcmp(p->name, a) == 0)break;
		p = p->next;
	}
	if (p) {
		switch (b[0])
		{
		case 'I':
			p->ID = StrToInt(c);
			break;
		case'n':
			strcpy(p->name, c);
			break;
		case'c':
			p->ch = c[0];
			break;
		case'p':
			strcpy(p->phone, c);
			break;
		case'a':
			strcpy(p->addr, c);
			break;
		default:
			cout << "格式错误" << endl;
			break;
		}
	}
	else cout << "查无此人,无法修改" << endl;
	}

void LinkList::Check(char a[])
{
	DataType *p = front->next;
	if ('0' <= a[0] && a[0] <= '9')
	{
		int temp = StrToInt(a);
		while (p)
		{
			if (p->ID==temp)break;
			p = p->next;
		}
	}
	else
	{
		while (p)
		{
			if (strcmp(p->name, a) == 0)break;
			p = p->next;
		}
	}
	if (p) {
		cout << p->ID << " " << p->name << " " << p->ch << " " << p->phone << " " << p->addr << endl;
	}
	else cout << "查无此人"<<endl;
}

void LinkList::PrintList()
{
	DataType *p = front->next;
	
	while (p)
	{
		cout << p->ID << " " << p->name << " " << p->ch << " " << p->phone << " " << p->addr << endl;
		p = p->next;
	}
	cout << "共x条信息\n" << endl;
}

void LinkList::SaveList(DataType a[])
{
	DataType *p = front->next;
	int i(0);
	while (p)
	{
		a[i].ID = p->ID;
		strcpy(a[i].name , p->name);
		a[i].ch = p->ch;
		strcpy(a[i].phone , p->phone);
		strcpy(a[i].addr , p->addr);
		++i;
		p = p->next;
	}

}


