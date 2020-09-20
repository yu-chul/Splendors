#include "TakeNoble.h"

#define TRUE 1
#define FALSE 0

int ifSelectNoble(Player *p, int n)
{
	if (CmmnNoble[n].white == -1)
	{
		printf("您的输入有误，请重新输入：");
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
		printf("您没有资格接待该贵族。请重新输入：");
		return FALSE;
	}
}

int selectNoble(Player *p)
{
	int flag = FALSE;
	char input[100];				//定义输入字符串变量
	flag = FALSE;
	while (flag == FALSE)		//判断输入是否合法，当旗帜为TRUE时，跳出循环
	{
		pos(2, 23);
		gets_s(input);			//侦测输入
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
				printf("您的输入有误，请重新输入：");
				break;
			}
		}
		else
		{
			printf("您的输入有误，请重新输入：");
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
		printf("您已获接贵族的来访，声望点数+3。\n");
		Sleep(1000);
		clearMsgBox();
		return numOfThisNoble;
	}
	else if (count > 1)
	{
		printf("您当前可接待多位贵族的来访。请输入您欲接待的贵族之编号：");
		pos(2, 23);
		numOfThisNoble = selectNoble(p);
		printf("您已获接贵族的来访，声望点数+3。\n");
		Sleep(1000);
		clearMsgBox();
		return numOfThisNoble;
	}
	else return 0;
}