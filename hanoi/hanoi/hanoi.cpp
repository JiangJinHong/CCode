#include <stdio.h> 
#include <cmath>
//第一个塔为初始塔，中间的塔为借用塔，最后一个塔为目标塔  
int i=1;//记录步数  
void move(int n,char from,char to) //将编号为n的盘子由from移动到to  
{
	printf("%d from %c to %c\n",n,from,to);  
}  
void hanoi(int n,char from,char denpend_on,char to)//将n个盘子由初始塔移动到目标塔(利用借用塔)  
{  
    if (n==1)  
    move(1,from,to);//只有一个盘子是直接将初塔上的盘子移动到目的地  
    else  
    {  
      hanoi(n-1,from,to,denpend_on);//先将初始塔的前n-1个盘子借助目的塔移动到借用塔上  
      move(n,from,to);              //将剩下的一个盘子移动到目的塔上  
      hanoi(n-1,denpend_on,from,to);//最后将借用塔上的n-1个盘子移动到目的塔上  
    }  
}  
int main()  
{  
     int n;  
     scanf("%d",&n);  
	 printf("%d\n", int(pow(2, n) - 1));
     char x='A',y='B',z='C';    
     hanoi(n,x,y,z);
	 return 0;
}  