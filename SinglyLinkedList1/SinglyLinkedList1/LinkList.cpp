#include "LinkList.h"

template <class T>
LinkList<T>::LinkList(T a[], int n)//头插法
{
	front = new Node <T>;
	front->next = NULL;
	for (int i = n - 1; i >= 0; --i)
	{
		Node <T> *s = new Node<T>;
		s->data = a[i];
		s->next = front->next;
		front->next = s;
	}
}
/*
template <class T>
LinkList<T>::LinkList(T a[], int n)//尾插法
{
front = new Node <T>;
Node<T> *r = front;
for (int i = 0; i < n; ++i)
{
Node <T> *s = new Node<T>;
s->data = a[i];
r->next = s;
r = s;
}
r->next = NULL;
}
*/

template <class T>
LinkList<T>::~LinkList()
{
	Node <T> *p = front;
	while (p)
	{
		front = p;
		p = p->next;
		delete front;
	}
}

template <class T>
void LinkList<T>::PrintList()
{
	Node<T> *p = front->next;
	int tmp(0);
	while (p)
	{

		cout << p->data << " ";
		++tmp;
		//if (tmp % 10 == 0)cout << endl;
		p = p->next;
	}
}

template <class T>
int LinkList<T>::GetLength()
{
	Node<T> *p = front;
	int length(0);
	if (p->next == NULL)return length;
	while (p)
	{
		p = p->next;
		++length;
	}
	return length - 1;
}

template <class T>
Node <T>*LinkList<T>::Get(int i)
{
	Node <T> *p = front->next;
	int j = 1;
	while (p&&j != i)
	{
		p = p->next;
		++j;
	}
	return p;
}

template <class T>
int LinkList<T>::Locate(T x)
{
	Node <T>*p = front->next;
	int j = 1;
	while (p)
	{
		if (p->data == x)return j;
		p = p->next;
		++j;
	}
	return -1;
}

template <class T>
void LinkList<T>::Insert(int i, T x)
{
	Node <T>*p = front;
	if (i != 1)p = Get(i - 1);
	if (p) {
		Node<T>*s = new Node<T>;
		s->data = x;
		s->next = p->next;
		p->next = s;
	}
	else throw "插入位置错误";
}

template <class T>
T LinkList<T>::Delete(int i)
{
	Node <T>*p = front;
	if (i != 1)p = Get(i - 1);
	if (!p && !p->next)throw "位置错误";
	Node <T>*q = p->next;
	p->next = q->next;
	T x = q->data;
	delete q;
	return x;
}
