#include <stdio.h> 
#include <cmath>
//��һ����Ϊ��ʼ�����м����Ϊ�����������һ����ΪĿ����  
int i=1;//��¼����  
void move(int n,char from,char to) //�����Ϊn��������from�ƶ���to  
{
	printf("%d from %c to %c\n",n,from,to);  
}  
void hanoi(int n,char from,char denpend_on,char to)//��n�������ɳ�ʼ���ƶ���Ŀ����(���ý�����)  
{  
    if (n==1)  
    move(1,from,to);//ֻ��һ��������ֱ�ӽ������ϵ������ƶ���Ŀ�ĵ�  
    else  
    {  
      hanoi(n-1,from,to,denpend_on);//�Ƚ���ʼ����ǰn-1�����ӽ���Ŀ�����ƶ�����������  
      move(n,from,to);              //��ʣ�µ�һ�������ƶ���Ŀ������  
      hanoi(n-1,denpend_on,from,to);//��󽫽������ϵ�n-1�������ƶ���Ŀ������  
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