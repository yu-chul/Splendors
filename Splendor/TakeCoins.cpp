#include "TakeCoins.h"
#include "UIRefresh.h"

#define TRUE 1
#define FALSE 0

int giveCoins(Player *p, char input[], int n)
{
	int i;
	int copyWhite, copyBlue, copyGreen, copyRed, copyBlack;
	int countWhite, countBlue, countGreen, countRed, countBlack;
	copyWhite = p->coin_white, copyBlue = p->coin_blue, copyGreen = p->coin_green, copyRed = p->coin_red, copyBlack = p->coin_black;	//玩家筹码个数复制
	countWhite = 0, countBlue = 0, countGreen = 0, countRed = 0, countBlack = 0;					//待交换筹码计数
	for (i = 0; i < n; i++)
	{
		switch (input[i])
		{
		case 'a':
			if (copyWhite == 0)
			{
				printf("您没有足够的宝石，请重新输入：\n");
				return FALSE;
			}
			copyWhite--;
			countWhite++;
			break;
		case 'b':
			if (copyBlue == 0)
			{
				printf("您没有足够的宝石，请重新输入：\n");
				return FALSE;
			}
			copyBlue--;
			countBlue++;
			break;
		case 'c':
			if (copyGreen == 0)
			{
				printf("您没有足够的宝石，请重新输入：\n");
				return FALSE;
			}
			copyGreen--;
			countGreen++;
			break;
		case 'd':
			if (copyRed == 0)
			{
				printf("您没有足够的宝石，请重新输入：\n");
				return FALSE;
			}
			copyRed--;
			countRed++;
			break;
		case 'e':
			if (copyBlack == 0)
			{
				printf("您没有足够的宝石，请重新输入：\n");
				return FALSE;
			}
			copyBlack--;
			countBlack++;
			break;
		default:
			printf("您的输入有误，请重新输入：\n");
			return FALSE;
			break;
		}
	}
	coin.white = coin.white + countWhite;
	coin.blue = coin.blue + countBlue;
	coin.green = coin.green + countGreen;
	coin.red = coin.red + countRed;
	coin.black = coin.black + countBlack;	//加上相应数量筹码池筹码
	p->coin_white = p->coin_white - countWhite;
	p->coin_blue = p->coin_blue - countBlue;
	p->coin_green = p->coin_green - countGreen;
	p->coin_red = p->coin_red - countRed;
	p->coin_black = p->coin_black - countBlack;
	p->coin_total = p->coin_total - countWhite - countBlue - countGreen - countRed - countBlack; //减去相应数量玩家筹码，并结算到玩家总筹码数中
	return TRUE;
}

int getCoins(Player *p, char input[], int n)	//对输入字串进行匹配并交换筹码
{
	int i;
	int copyWhite, copyBlue, copyGreen, copyRed, copyBlack;
	int countWhite, countBlue, countGreen, countRed, countBlack;
	copyWhite = coin.white, copyBlue = coin.blue, copyGreen = coin.green, copyRed = coin.red, copyBlack = coin.black;	//宝石池筹码个数复制
	countWhite = 0, countBlue = 0, countGreen = 0, countRed = 0, countBlack = 0;					//待交换筹码计数
	if (n == 2)
	{
		switch (input[0])
		{
		case 'a':
			if (copyWhite < 4)
			{
				printf("宝石池宝石不足，请重新输入：\n");
				return FALSE;
			}
			copyWhite -= 2;
			countWhite += 2;
			break;
		case 'b':
			if (copyBlue < 4)
			{
				printf("宝石池宝石不足，请重新输入：\n");
				return FALSE;
			}
			copyBlue -= 2;
			countBlue += 2;
			break;
		case 'c':
			if (copyGreen < 4)
			{
				printf("宝石池宝石不足，请重新输入：\n");
				return FALSE;
			}
			copyGreen -= 2;
			countGreen += 2;
			break;
		case 'd':
			if (copyRed == 0 || (n == 2 && copyRed < 4))
			{
				printf("宝石池宝石不足，请重新输入：\n");
				return FALSE;
			}
			copyRed -= 2;
			countRed += 2;
			break;
		case 'e':
			if (copyBlack == 0 || (n == 2 && copyBlack < 4))
			{
				printf("宝石池宝石不足，请重新输入：\n");
				return FALSE;
			}
			copyBlack -= 2;
			countBlack += 2;
			break;
		default:
			printf("您的输入有误，请重新输入：\n");
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
					printf("宝石池宝石不足，请重新输入：\n");
					return FALSE;
				}
				copyWhite--;
				countWhite++;
				break;
			case 'b':
				if (copyBlue == 0)
				{
					printf("宝石池宝石不足，请重新输入：\n");
					return FALSE;
				}
				copyBlue--;
				countBlue++;
				break;
			case 'c':
				if (copyGreen == 0)
				{
					printf("宝石池宝石不足，请重新输入：\n");
					return FALSE;
				}
				copyGreen--;
				countGreen++;
				break;
			case 'd':
				if (copyRed == 0)
				{
					printf("宝石池宝石不足，请重新输入：\n");
					return FALSE;
				}
				copyRed--;
				countRed++;
				break;
			case 'e':
				if (copyBlack == 0)
				{
					printf("宝石池宝石不足，请重新输入：\n");
					return FALSE;
				}
				copyBlack--;
				countBlack++;
				break;
			default:
				printf("您的输入有误，请重新输入：\n");
				return FALSE;
				break;
			}
		}
	}
	coin.white = coin.white - countWhite;
	coin.blue = coin.blue - countBlue;
	coin.green = coin.green - countGreen;
	coin.red = coin.red - countRed;
	coin.black = coin.black - countBlack;	//扣去相应数量筹码池筹码
	p->coin_white = p->coin_white + countWhite;
	p->coin_blue = p->coin_blue + countBlue;
	p->coin_green = p->coin_green + countGreen;
	p->coin_red = p->coin_red + countRed;
	p->coin_black = p->coin_black + countBlack;
	p->coin_total = p->coin_total + countWhite + countBlue + countGreen + countRed + countBlack; //加上相应数量玩家筹码，并结算到玩家总筹码数中
	return TRUE;
}

void takeCoins(Player *p)
{
	printf("请输入您欲一次性拿取的宝石：");
	pos(2, 23);
	int flag = FALSE;
	char input[100];				//定义输入字符串变量
	flag = FALSE;
	while (flag == FALSE)		//判断输入是否合法，当旗帜为TRUE时，跳出循环
	{
		pos(2, 23);
		gets_s(input);			//侦测输入
		clearMsgBox();
		if ((strlen(input) == 3 && input[0] != input[1] && input[0] != input[2] && input[1] != input[2] ) || (strlen(input) == 2 && input[0] == input[1]))
			flag = getCoins(p, input, int(strlen(input)));
		else
		{
			printf("您的输入有误，请重新输入：\n");
			flag = FALSE;
		}
	}
	printf("您已成功拿取宝石。");
	Sleep(1000);
	for (int i = 0; i < numOfPlayer; i++)
		playerefresh(i);
	coinrefresh();
	clearMsgBox();
	if (p->coin_total > 10)	//若玩家筹码数量超出限制（10个）
	{
		flag = FALSE;
		printf("您所持有的宝石数量已超过10个，\n");
		pos(2, 23);
		printf("请输入需一次性退回的%d个宝石：\n", p->coin_total - 10);
		while (flag == FALSE)
		{
			pos(2, 24);
			gets_s(input);		//侦测输入
			clearMsgBox();
			if (strlen(input) == p->coin_total - 10)
				flag = giveCoins(p, input, int(strlen(input)));
			else
			{
				printf("您的输入有误，请重新输入：\n");
				flag = FALSE;
			}
		}
		printf("您已成功退回宝石。");
		Sleep(1000);
		clearMsgBox();
	}
}