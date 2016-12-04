//最坏为线性的选择算法
#include <ctime>  
#include <iostream>   
#include <cstdlib>
using namespace std;
void Swap(int &x, int &y);
inline int Random(int x, int y);
void BubbleSort(int a[], int l, int r);
int Partition(int a[], int l, int r, int x);
int Select(int a[], int l, int r, int k);

int main()
{
	int a[10000];
	srand((unsigned)time(0));
	int n1,n2;//---------n1数组数字数量------n2第几个数字
	cin >> n1;
	cin >> n2;
	for (int j = 1; j <= n1; j++)
	{
		cin >> a[j];
	}
	cout << Select(a, 1, n1, n2) << endl;
	/*BubbleSort(a, 1, n1);
     for (int j = 1; j <= n1; j++)
	{
		cout << a[j] << " ";
	}
	cout << endl;
	cout << a[n2];*/
}

void Swap(int &x, int &y)//-----------交换
{
	int temp = x;
	x = y;
	y = temp;
}

inline int Random(int x, int y)//-------------随机
{
	int ran_num = rand() % (y - x + 1) + x;
	return ran_num;
}
 

void BubbleSort(int a[], int l, int r)//------------冒泡排序
{
	bool exchange;
	for (int i = l; i <= r - 1; i++)
	{
		exchange = false;
		for (int j = l ; j <= r; j++)
		{
			if (a[j]<a[j - 1])
			{
				Swap(a[j], a[j - 1]);
				exchange = true;
			}
		}   
		if (exchange == false)//--------提前跳出条件
			break;
	}
}


int Partition(int a[], int l, int r, int x)//---------分割
{
	int i = l - 1, j = r + 1;
	while (true)
	{
		while (a[++i] < x && i < r);
		while (a[--j] > x);
		if (i >= j)
		{
			break;
		}
		Swap(a[i], a[j]);
	}
	return j;
}


int Select(int a[], int l, int r, int k)
{
	if (r - l < 75)
	{
		BubbleSort(a, l, r);
		return a[l + k - 1];
	}
	for (int i = 1; i <= (r - l + 1) / 5; i++)
	{
		//将元素每5个分成一组，分别排序，并将该组中位数与a[l+i]交换位置  
		//使所有中位数都排列在数组最左侧，以便进一步查找中位数的中位数  
		BubbleSort(a, l + 5 * (i - 1), l + 5 * (i - 1) + 4);
		Swap(a[l + 5 * (i - 1) + 2], a[l + i - 1]);
	}
	//找中位数的中位数  
	int x = Select(a, l, l - 1 + (r - l + 1) / 5, (r - l + 1) / 10);
	int i = Partition(a, l, r, x);
	int j = i - l + 1;
	if (k <= j)
	{
		return Select(a, l, i, k);
	}
	else
	{
		return Select(a, i + 1, r, k - j);
	}
}