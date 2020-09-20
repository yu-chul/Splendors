#include "TakeCoins.h"
#include "UIRefresh.h"

#define TRUE 1
#define FALSE 0

int giveCoins(Player *p, char input[], int n)
{
	int i;
	int copyWhite, copyBlue, copyGreen, copyRed, copyBlack;
	int countWhite, countBlue, countGreen, countRed, countBlack;
	copyWhite = p->coin_white, copyBlue = p->coin_blue, copyGreen = p->coin_green, copyRed = p->coin_red, copyBlack = p->coin_black;	//��ҳ����������
	countWhite = 0, countBlue = 0, countGreen = 0, countRed = 0, countBlack = 0;					//�������������
	for (i = 0; i < n; i++)
	{
		switch (input[i])
		{
		case 'a':
			if (copyWhite == 0)
			{
				printf("��û���㹻�ı�ʯ�����������룺\n");
				return FALSE;
			}
			copyWhite--;
			countWhite++;
			break;
		case 'b':
			if (copyBlue == 0)
			{
				printf("��û���㹻�ı�ʯ�����������룺\n");
				return FALSE;
			}
			copyBlue--;
			countBlue++;
			break;
		case 'c':
			if (copyGreen == 0)
			{
				printf("��û���㹻�ı�ʯ�����������룺\n");
				return FALSE;
			}
			copyGreen--;
			countGreen++;
			break;
		case 'd':
			if (copyRed == 0)
			{
				printf("��û���㹻�ı�ʯ�����������룺\n");
				return FALSE;
			}
			copyRed--;
			countRed++;
			break;
		case 'e':
			if (copyBlack == 0)
			{
				printf("��û���㹻�ı�ʯ�����������룺\n");
				return FALSE;
			}
			copyBlack--;
			countBlack++;
			break;
		default:
			printf("���������������������룺\n");
			return FALSE;
			break;
		}
	}
	coin.white = coin.white + countWhite;
	coin.blue = coin.blue + countBlue;
	coin.green = coin.green + countGreen;
	coin.red = coin.red + countRed;
	coin.black = coin.black + countBlack;	//������Ӧ��������س���
	p->coin_white = p->coin_white - countWhite;
	p->coin_blue = p->coin_blue - countBlue;
	p->coin_green = p->coin_green - countGreen;
	p->coin_red = p->coin_red - countRed;
	p->coin_black = p->coin_black - countBlack;
	p->coin_total = p->coin_total - countWhite - countBlue - countGreen - countRed - countBlack; //��ȥ��Ӧ������ҳ��룬�����㵽����ܳ�������
	return TRUE;
}

int getCoins(Player *p, char input[], int n)	//�������ִ�����ƥ�䲢��������
{
	int i;
	int copyWhite, copyBlue, copyGreen, copyRed, copyBlack;
	int countWhite, countBlue, countGreen, countRed, countBlack;
	copyWhite = coin.white, copyBlue = coin.blue, copyGreen = coin.green, copyRed = coin.red, copyBlack = coin.black;	//��ʯ�س����������
	countWhite = 0, countBlue = 0, countGreen = 0, countRed = 0, countBlack = 0;					//�������������
	if (n == 2)
	{
		switch (input[0])
		{
		case 'a':
			if (copyWhite < 4)
			{
				printf("��ʯ�ر�ʯ���㣬���������룺\n");
				return FALSE;
			}
			copyWhite -= 2;
			countWhite += 2;
			break;
		case 'b':
			if (copyBlue < 4)
			{
				printf("��ʯ�ر�ʯ���㣬���������룺\n");
				return FALSE;
			}
			copyBlue -= 2;
			countBlue += 2;
			break;
		case 'c':
			if (copyGreen < 4)
			{
				printf("��ʯ�ر�ʯ���㣬���������룺\n");
				return FALSE;
			}
			copyGreen -= 2;
			countGreen += 2;
			break;
		case 'd':
			if (copyRed == 0 || (n == 2 && copyRed < 4))
			{
				printf("��ʯ�ر�ʯ���㣬���������룺\n");
				return FALSE;
			}
			copyRed -= 2;
			countRed += 2;
			break;
		case 'e':
			if (copyBlack == 0 || (n == 2 && copyBlack < 4))
			{
				printf("��ʯ�ر�ʯ���㣬���������룺\n");
				return FALSE;
			}
			copyBlack -= 2;
			countBlack += 2;
			break;
		default:
			printf("���������������������룺\n");
			return FALSE;
			break;
		}
	}
	else if (n==3)
	{
		for (i = 0; i < n; i++)
		{
			switch (input[i])
			{
			case 'a':
				if (copyWhite == 0 )
				{
					printf("��ʯ�ر�ʯ���㣬���������룺\n");
					return FALSE;
				}
				copyWhite--;
				countWhite++;
				break;
			case 'b':
				if (copyBlue == 0)
				{
					printf("��ʯ�ر�ʯ���㣬���������룺\n");
					return FALSE;
				}
				copyBlue--;
				countBlue++;
				break;
			case 'c':
				if (copyGreen == 0)
				{
					printf("��ʯ�ر�ʯ���㣬���������룺\n");
					return FALSE;
				}
				copyGreen--;
				countGreen++;
				break;
			case 'd':
				if (copyRed == 0)
				{
					printf("��ʯ�ر�ʯ���㣬���������룺\n");
					return FALSE;
				}
				copyRed--;
				countRed++;
				break;
			case 'e':
				if (copyBlack == 0)
				{
					printf("��ʯ�ر�ʯ���㣬���������룺\n");
					return FALSE;
				}
				copyBlack--;
				countBlack++;
				break;
			default:
				printf("���������������������룺\n");
				return FALSE;
				break;
			}
		}
	}
	coin.white = coin.white - countWhite;
	coin.blue = coin.blue - countBlue;
	coin.green = coin.green - countGreen;
	coin.red = coin.red - countRed;
	coin.black = coin.black - countBlack;	//��ȥ��Ӧ��������س���
	p->coin_white = p->coin_white + countWhite;
	p->coin_blue = p->coin_blue + countBlue;
	p->coin_green = p->coin_green + countGreen;
	p->coin_red = p->coin_red + countRed;
	p->coin_black = p->coin_black + countBlack;
	p->coin_total = p->coin_total + countWhite + countBlue + countGreen + countRed + countBlack; //������Ӧ������ҳ��룬�����㵽����ܳ�������
	return TRUE;
}

void takeCoins(Player *p)
{
	printf("����������һ������ȡ�ı�ʯ��");
	pos(2, 23);
	int flag = FALSE;
	char input[100];				//���������ַ�������
	flag = FALSE;
	while (flag == FALSE)		//�ж������Ƿ�Ϸ���������ΪTRUEʱ������ѭ��
	{
		pos(2, 23);
		gets_s(input);			//�������
		clearMsgBox();
		if ((strlen(input) == 3 && input[0] != input[1] && input[0] != input[2] && input[1] != input[2] ) || (strlen(input) == 2 && input[0] == input[1]))
			flag = getCoins(p, input, int(strlen(input)));
		else
		{
			printf("���������������������룺\n");
			flag = FALSE;
		}
	}
	printf("���ѳɹ���ȡ��ʯ��");
	Sleep(1000);
	for (int i = 0; i < numOfPlayer; i++)
		playerefresh(i);
	coinrefresh();
	clearMsgBox();
	if (p->coin_total > 10)	//����ҳ��������������ƣ�10����
	{
		flag = FALSE;
		printf("�������еı�ʯ�����ѳ���10����\n");
		pos(2, 23);
		printf("��������һ�����˻ص�%d����ʯ��\n", p->coin_total - 10);
		while (flag == FALSE)
		{
			pos(2, 24);
			gets_s(input);		//�������
			clearMsgBox();
			if (strlen(input) == p->coin_total - 10)
				flag = giveCoins(p, input, int(strlen(input)));
			else
			{
				printf("���������������������룺\n");
				flag = FALSE;
			}
		}
		printf("���ѳɹ��˻ر�ʯ��");
		Sleep(1000);
		clearMsgBox();
	}
}