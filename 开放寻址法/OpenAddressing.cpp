//����Ѱַ��  
//ɢ�к�����������̽�⡢����̽�⡢˫��̽��  
#include<iostream>  
using namespace std;  
//����ɢ�з�  
int h1(int k,int m)  
{  
	return k%m;
}  
//�˷�ɢ�з�  
int h2(int k,int m,float A)  
{  
	float fnum = (float)k;
		float re = ((fnum*A) - (int)(fnum*A))*m;
		return (int)re;
}  
//ȫ��ɢ�з�,pΪ����  
int h3(int k,int p,int m)  
{  
    int a,b;  
    a=11;  
    b=13;  
	return ((a*k + b) % p) % m;
}  
//����̽��  
int LinerProbing(int k,int m,int i)  
{  
	return (h1(k, m) + i) % m;
}  
//����̽��  
int QuadraticProbing(int k,int m,int i)  
{  
	int c1 = 17, c2 = 67;
  
	return (h1(k, m) + c1*i + c2*i*i) % m;
}  
//˫��̽��  
int DoublefunProbing(int k,int m,int i)  
{  
	return (h3(k, 17, m) + i*h1(k, m)) % m;
}  
//����ֵΪk��Ԫ�ص�����m���۵�T��  
int Insert(int *T,int k,int m)  
{  
    int i=1,j;  
    while(1)  
    {  
        //����˫��̽��ó�����λ��  
        j=DoublefunProbing(k,m,i);  
        if(i==m+1)  
        {  
            break;  
        }  
        //T[j]==-1��ʾ�ò�Ϊ��  
        if(T[j]==-1)  
        {  
            T[j]=k;  
            return j;  
        }  
        i++;  
    }  
    return -1;  
}  
//ɾ��ֵΪk��Ԫ���ھ���m���۵�T��  
bool Delete(int *T,int k,int m)  
{  
    int i=1,j;  
    while(1)  
    {  
        j=DoublefunProbing(k,m,i);  
        if(i==m+1)  
        {  
            return 0;  
        }  
        if(T[j]==-1)  
        {  
            return 0;  
        }  
        if(T[j]==k)  
        {  
            T[j]=-1;  
            return 1;  
        }  
        i++;  
    }  
}  
//����ֵΪk��Ԫ���ھ���m���۵�T��  
int Search(int *T,int k,int m)  
{  
    int i=1,j;  
    while(1)  
    {  
        j=DoublefunProbing(k,m,i);  
        if(i==m+1)  
        {  
            return -1;  
        }  
        if(T[j]==-1)  
        {  
            return -1;  
        }  
        if(T[j]==k)  
        {  
            return j;  
        }  
        i++;  
    }  
}  
int main()  
{  
    int a[11]={0,4,8,2,6,41,21,53,496,3216,48};  
    int T[101]={0};  
    int i;  
    for(i=0;i<101;i++)  
    {  
        T[i]=-1;  
    }  
    for(i=1;i<=10;i++)  
    {  
        Insert(T,a[i],100);  
    }  
    for(i=1;i<=100;i++)  
    {  
        if(T[i]!=-1)  
        {  
            cout<<T[i]<<" ";  
        }  
    }  
    cout<<endl;  
    cout<<Search(T,2,100)<<endl;  
    Delete(T,2,100);  
    cout<<Search(T,2,100)<<endl;  
}  