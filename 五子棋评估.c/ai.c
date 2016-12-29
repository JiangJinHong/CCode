// Created by ������ on 2016/12/6.
//

#define OTHER 2
#define ME 1
#include "ai.h"
#define WinMark 10000
//===============================================================JiangS
int max = -1;
int ans = 0;//���ָ��
int tmp[8];//�� �� ���� ���� �� �� ���� ����
int tmpx[8];
int tmpy[8];
int xf[12] = { 0,-1,-1,-1,0,1,1,1,0,-1,-1,-1 };//�� �� ���� ���� �� �� ���� ���� �� �� ���� ����
int yf[12] = { 1,0,1,-1,-1,0,-1,1,1,0,1,-1 };//�� �� ���� ���� �� �� ���� ���� �� �� ���� ����
int location[20][20] = { {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
						 {1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1 },
						 {1,2,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,2,1 },
						 {1,2,3,4,4,4,4,4,4,4,4,4,4,4,4,4,4,3,2,1 },
						 {1,2,3,4,5,5,5,5,5,5,5,5,5,5,5,5,4,3,2,1 },
						 {1,2,3,4,5,6,6,6,6,6,6,6,6,6,6,5,4,3,2,1 },
						 {1,2,3,4,5,6,7,7,7,7,7,7,7,7,6,5,4,3,2,1 },
						 {1,2,3,4,5,6,7,8,8,8,8,8,8,7,6,5,4,3,2,1 },
						 {1,2,3,4,5,6,7,8,9,9,9,9,8,7,6,5,4,3,2,1 },
						 {1,2,3,4,5,6,7,8,9,10,10,9,8,7,6,5,4,3,2,1 },
						 {1,2,3,4,5,6,7,8,9,10,10,9,8,7,6,5,4,3,2,1 },
						 {1,2,3,4,5,6,7,8,9,9,9,9,8,7,6,5,4,3,2,1 },
						 {1,2,3,4,5,6,7,8,8,8,8,8,8,7,6,5,4,3,2,1 },
						 {1,2,3,4,5,6,7,7,7,7,7,7,7,7,6,5,4,3,2,1 },
						 {1,2,3,4,5,6,6,6,6,6,6,6,6,6,6,5,4,3,2,1 },
						 {1,2,3,4,5,5,5,5,5,5,5,5,5,5,5,5,4,3,2,1 },
						 {1,2,3,4,4,4,4,4,4,4,4,4,4,4,4,4,4,3,2,1 },
						 {1,2,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,2,1 },
						 {1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1 },
						 {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 } };
//===========================================================================
//attack


//===================================================================JiangS
//defend

//��������
void score1(int i, int temp)
{
	if (temp == 2)tmp[i] += 45;
	if (temp == 3)tmp[i] += 250;
	if (temp == 4)tmp[i] += 1500;
	if (temp >= 5)tmp[i] += 10000;
}
//���Ǿ������̱߽�����
void score2(int i)
{
	int t1=tmpx[i];
	int t2=tmpy[i];
	tmp[i] = tmp[i] + location[t1][t2];
}
//���س���
void check(const char b[BOARD_SIZE][BOARD_SIZE], int x, int y)
{
	//����
	int a1;
	for (a1 = 0; a1 <= 7; a1++)
	{
		tmp[a1] = 0; tmpx[a1] = 0; tmpy[a1] = 0;
	}

	int p = x - 1, r = y - 1;
	int i;
	for (i = 0; i <= 7; i++)//------�ҵ���������λ��
	{
		p = x - 1, r = y - 1;
		while (b[p][r] == OTHER)
		{
			p += xf[i];
			r += yf[i];
		}
		tmpx[i] = p + 1;
		tmpy[i] = r + 1;
		if (p < 0 || p>19 || r < 0 || r>19 || b[p][r] == ME)continue;
		else 
		{
			int p2 = p, r2 = r, temp = 0;
			int j;
			for (j = 0; j <= 3; j++)
			{
				while (b[p2][r2] == OTHER)
				{
					p2 += xf[j];
					r2 += yf[j];
				}
				p2 += xf[j + 4];
				r2 += yf[j + 4];
				while(b[p2][r2] == OTHER || p2 == p&&r2 == r)
				{
					temp++;
					p2 += xf[j + 4];
					r2 += yf[j + 4];
				}
				score1(i, temp);
				temp = 0;
				p2 = p;
				r2 = r;
			}
		}
	}
	int a2;
	for (a2 = 0; a2 <= 7; a2++)
	{
		score(a2);
	}
}
void Defence(const char b[BOARD_SIZE][BOARD_SIZE], int x, int y)
{
	int p = x, r = y;
	ans = 0;
	max = -1;
	check(b,p, r);
	int max = -1;
	int k;
	for (k = 0; k <= 7; k++)
	{
		if (max < tmp[k])
		{
			max = tmp[k];
			ans = k;
     	}
}
void initAI()
{

}

/*
* Game Start, you will put the first chess.
* Warning: This method will only be called when after the initialize ofi the  map, it is your turn to put the chess.
* Or this method will not be called.
* You should return a valid Position variable.
* ��ֿ�ʼ����������������
* ��ע�⣺ֻ���ڵ���ֳ�ʼ�����ֵ�������ʱ�Żᴥ������������������ֳ�ʼ����Ϻ��ֵ��������ӣ�������������ᱻ�����������ĿҪ��
* �����me��ȡֵֻ������ME(1)����board(����)��ΪME(1)��λ�ñ�ʾ������ӣ�board(����)��ΪOTHER(2)��λ�ñ�ʾ���ֵ����ӡ�
* ����Ҫ����һ���ṹ��Position����x���Ժ�y������������Ҫ���ӵ�λ�á�
*/
struct Position aiBegin(const char board[BOARD_SIZE][BOARD_SIZE], int me)
{
	int PotentialPoint = 0;

	int MaxScore = 0;
	int i, j;
	int k = 0, l = 0;
	struct Position preferedPos;

	for (i = 0; i < BOARD_SIZE; i++)
		for (j = 0; j < BOARD_SIZE; j++)
		{
			if (EMPTY == board[i][j])
			{
				if (JudgeEmpty(board, i, j) == 0)
					continue;
				PotentialPoint = JudgeFunction_One(board, i, j);
				if (PotentialPoint == MaxScore)
				{
					if (i >= 5 && j >= 5 && i <= BOARD_SIZE - 5 && j <= BOARD_SIZE - 5)
					{
						preferedPos.x = i;
						preferedPos.y = j;
					}
				}
				if (PotentialPoint>MaxScore)
				{
					MaxScore = PotentialPoint;
					preferedPos.x = i;
					preferedPos.y = j;
					if (MaxScore == WinMark)
						return preferedPos;
				}
			}
		}
	if (MaxScore == 0)
	{

		for (k = 5; k <BOARD_SIZE; k++)

			for (l = 5; l <BOARD_SIZE; l++)
			{
				if (board[k][l] == EMPTY)
				{
					preferedPos.x = k;
					preferedPos.y = l;
					return preferedPos;
				}
			}
	}
	return preferedPos;
}

/*
* Game ongoing, the competitor put the chess at the position (otherX, otherY). You should put your chess.
* You should return a valid Position variable.
* ��ֽ����У��Է���һ��������(otherX, otherY)��λ�ã��ֵ��������ˡ�
* �����me��ȡֵֻ������ME(1)����board(����)��ΪME(1)��λ�ñ�ʾ������ӣ�board(����)��ΪOTHER(2)��λ�ñ�ʾ���ֵ����ӡ�
* ����Ҫ����һ���ṹ��Position����x���Ժ�y������������Ҫ���ӵ�λ�á�
*/
struct Position aiTurn(const char board[BOARD_SIZE][BOARD_SIZE], int me, int otherX, int otherY)
{
	struct Position preferedPos;
	Defence(board, x, y);
	//if(max>450)
	{		preferedPos.x = tmpx[ans];
		    preferedPos.y = tmpy[ans];
		    return preferedPos;
    }
	
}


