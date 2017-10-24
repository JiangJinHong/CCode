#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;

#ifndef DataType_d
#define DataType_d

struct DataType
{
	
	int ID;
	char name[10];
	char ch ;
	char phone[13];
	char addr[31];
	DataType *next;
};
#endif

#ifndef LinkList_d
#define LinkList_d

class LinkList
{
public:
	LinkList() 
	{
		front = new DataType;
		front->next = NULL;
	}
	LinkList(DataType a[], int n);
	~LinkList();
	void Add(DataType a);
	void Delete(char a[]);
	void Modify(char a[], char b[], char c[]);
	void Modify(char a[]);
	void Check(char a[]);
	void PrintList();
	void SaveList(DataType a[]);
private:
	DataType * front;
	
};
#endif

