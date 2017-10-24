#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#ifndef Node_d
#define Node_d
template <class T>
struct Node
{
	T data;
	struct Node <T> *next;
};
#endif

#ifndef LinkList_d
#define LinkList_d
template <class T>
class LinkList
{
public:
	LinkList() { front = new Node<T>; front->next = NULL; }
	LinkList(T a[], int n);
	~LinkList();
	void PrintList();
	int GetLength();
	Node<T> *Get(int i);
	int Locate(T x);
	void Insert(int i, T x);
	T Delete(int i);

private:
	Node <T> * front;
};
#endif

