#include "TakeNoble.h"

#define TRUE 1
#define FALSE 0

int ifSelectNoble(Player *p, int n)
{
	if (CmmnNoble[n].white == -1)
	{
		printf("���������������������룺");
		return FALSE;
	}
	else if (p->bonus_white >= CmmnNoble[n].white&&p->bonus_blue >= CmmnNoble[n].blue&&p->bonus_green >= CmmnNoble[n].green&&p->bonus_red >= CmmnNoble[n].red&&p->bonus_black >= CmmnNoble[n].black)
	{
		CmmnNoble[n] = { -1,-1,-1,-1,-1 };
		p->points += 3;
		return TRUE;
	}
	else
	{
		printf("��û���ʸ�Ӵ��ù��塣���������룺");
		return FALSE;
	}
}

int selectNoble(Player *p)
{
	int flag = FALSE;
	char input[100];				//���������ַ�������
	flag = FALSE;
	while (flag == FALSE)		//�ж������Ƿ�Ϸ���������ΪTRUEʱ������ѭ��
	{
		pos(2, 23);
		gets_s(input);			//�������
		clearMsgBox();
		if (strlen(input) == 1)
		{
			switch (input[0])
			{
			case '1':
				flag = ifSelectNoble(p, 0);
				if (flag == TRUE)
					return 1;
				break;
			case '2':
				flag = ifSelectNoble(p, 1);
				if (flag == TRUE)
					return 2;
				break;
			case '3':
				flag = ifSelectNoble(p, 2);
				if (flag == TRUE)
					return 3;
				break;
			case '4':
				flag = ifSelectNoble(p, 3);
				if (flag == TRUE)
					return 4;
				break;
			case '5':
				flag = ifSelectNoble(p, 4);
				if (flag == TRUE)
					return 5;
				break;
			default:
				printf("���������������������룺");
				break;
			}
		}
		else
		{
			printf("���������������������룺");
		}
	}
}

int TakeNoble(Player *p)
{
	int i;
	int count = 0;
	int numOfThisNoble;
	Noble *thisNoble = NULL;
	for (i = 0; i <= numOfPlayer; i++)
	{
		if (CmmnNoble[i].white == -1)
			continue;
		else
		{
			if (p->bonus_white >= CmmnNoble[i].white&&p->bonus_blue >= CmmnNoble[i].blue&&p->bonus_green >= CmmnNoble[i].green&&p->bonus_red >= CmmnNoble[i].red&&p->bonus_black >= CmmnNoble[i].black)
			{
				count++;
				thisNoble = &CmmnNoble[i];
				numOfThisNoble = i + 1;
			}
		}
	}
	if (count == 1)
	{
		*thisNoble = { -1,-1,-1,-1,-1 };
		p->points += 3;
		printf("���ѻ�ӹ�������ã���������+3��\n");
		Sleep(1000);
		clearMsgBox();
		return numOfThisNoble;
	}
	else if (count > 1)
	{
		printf("����ǰ�ɽӴ���λ��������á������������Ӵ��Ĺ���֮��ţ�");
		pos(2, 23);
		numOfThisNoble = selectNoble(p);
		printf("���ѻ�ӹ�������ã���������+3��\n");
		Sleep(1000);
		clearMsgBox();
		return numOfThisNoble;
	}
	else return 0;
}