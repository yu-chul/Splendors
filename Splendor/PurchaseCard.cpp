#include"PurchaseCard.h"

/******************************************************************************************************************

										PurchaseCard.cpp:

							实现“买牌操作函数”内部需要用到的函数：

							调用同名头文件

							不要在这里写变量声明

**************************************************************************************************************************/

//2.选中玩家输入的位置所指向的“玩家压牌区”上的牌的函数
void ChooseReservedCard(struct DevCard **cCard, struct Player &p, char *order)
{
	int i;
	char CardLocation;
	for (i = 0; *(order + i) != '\0'; i++)
	{

		if (*(order + i) >= 'a'&&*(order + i) <= 'z' || *(order + i) >= 'A'&&*(order + i) <= 'Z')
			CardLocation = *(order + i);
	}
	switch (CardLocation)
	{
	case 'e':*cCard = &p.devcard[0]; break;
	case 'f':*cCard = &p.devcard[1]; break;
	case 'g':*cCard = &p.devcard[2]; break;

	}
}



//4.将已选牌写进玩家数据的函数
void Purchase(struct Player &p, DevCard &cCard, Coins &coin)
{
	if (cCard.white > 0)		//白色对应
	{
		if (cCard.white > p.bonus_white + p.coin_white)						//白筹码不够
		{
			p.coin_gold -= cCard.white - (p.bonus_white + p.coin_white);		//就减黄金
			coin.gold += cCard.white - (p.bonus_white + p.coin_white);
			p.coin_total -= cCard.white - p.bonus_white;;
			coin.white += p.coin_white;
			p.coin_white = 0;														//并用掉所有白筹码（花了所有白筹码与需要的黄金）

		}
		else
			if (cCard.white < p.bonus_white) {}											//筹码够就什么都不做
			else
			{
				p.coin_white -= cCard.white - p.bonus_white;
				p.coin_total -= cCard.white - p.bonus_white;
				coin.white += cCard.white - p.bonus_white;
			}																			//够的话只减筹码
	}
	if (cCard.blue > 0)		//蓝色对应
	{
		if (cCard.blue > p.bonus_blue + p.coin_blue)							//蓝筹码不够
		{
			p.coin_gold -= cCard.blue - (p.bonus_blue + p.coin_blue);			//就减黄金
			coin.gold += cCard.blue - (p.bonus_blue + p.coin_blue);
			p.coin_total -= cCard.blue - p.bonus_blue;
			coin.blue += p.coin_blue;
			p.coin_blue = 0;														//并用掉所有蓝筹码（花了所有蓝筹码与需要的黄金）
		}
		else
			if (cCard.blue < p.bonus_blue) {}										//筹码够就什么都不做
			else
			{
				p.coin_blue -= cCard.blue - p.bonus_blue;
				p.coin_total -= cCard.blue - p.bonus_blue;
				coin.blue += cCard.blue - p.bonus_blue;
			}																			//够的话只减筹码
	}
	if (cCard.green > 0)		//绿色对应
	{
		if (cCard.green > p.bonus_green + p.coin_green)						//绿筹码不够
		{
			p.coin_gold -= cCard.green - (p.bonus_green + p.coin_green);		//就减黄金
			coin.gold += cCard.green - (p.bonus_green + p.coin_green);
			p.coin_total -= cCard.green - p.bonus_green;
			coin.green += p.coin_green;
			p.coin_green = 0;														//并用掉所有绿筹码（花了所有绿筹码与需要的黄金）
		}
		else
			if (cCard.green < p.bonus_green) {}										//筹码够就什么都不做
			else
			{
				p.coin_green -= cCard.green - p.bonus_green;
				p.coin_total -= cCard.green - p.bonus_green;
				coin.green += cCard.green - p.bonus_green;
			}																			//够的话只减筹码
	}
	if (cCard.red > 0)		//红色对应
	{
		if (cCard.red > p.bonus_red + p.coin_red)								//红筹码不够
		{
			p.coin_gold -= cCard.red - (p.bonus_red + p.coin_red);			//就减黄金
			coin.gold += cCard.red - (p.bonus_red + p.coin_red);
			p.coin_total -= cCard.red - p.bonus_red;
			coin.red += p.coin_red;
			p.coin_red = 0;															//并用掉所有红筹码（花了所有红筹码与需要的黄金）
		}
		else
			if (cCard.red < p.bonus_red) {}											//筹码够就什么都不做
			else
			{
				p.coin_red -= cCard.red - p.bonus_red;
				p.coin_total -= cCard.red - p.bonus_red;
				coin.red += cCard.red - p.bonus_red;
			}																			//够的话只减筹码
	}
	if (cCard.black > 0)		//黑色对应
	{
		if (cCard.black > p.bonus_black + p.coin_black)						//黑筹码不够
		{
			p.coin_gold -= cCard.black - (p.bonus_black + p.coin_black);		//就减黄金
			coin.gold += cCard.black - (p.bonus_black + p.coin_black);
			p.coin_total -= cCard.black - p.bonus_black;
			coin.black += p.coin_black;
			p.coin_black = 0;														//并用掉所有黑筹码（花了所有黑筹码与需要的黄金）
		}
		else
			if (cCard.black < p.bonus_black) {}										//筹码够就什么都不做
			else
			{
				p.coin_black -= cCard.black - p.bonus_black;
				p.coin_total -= cCard.black - p.bonus_black;
				coin.black += cCard.black - p.bonus_black;
			}																			//够的话只减筹码
	}

	//减掉对应筹码与黄金

	switch (cCard.bonus)
	{
	case (Color)1:
		p.bonus_white += 1;
		p.points += cCard.point; break;		//白色对应加声望
	case (Color)2:
		p.bonus_blue += 1;
		p.points += cCard.point; break;	//蓝色对应加声望
	case (Color)3:
		p.bonus_green += 1;
		p.points += cCard.point; break;	//绿色对应加声望
	case (Color)4:
		p.bonus_red += 1;
		p.points += cCard.point; break;	//红色对应加声望
	case (Color)5:
		p.bonus_black += 1;
		p.points += cCard.point; break;	//黑色对应加声望
	}
	//将牌代表的宝石加上，再加上声望


	cCard.bonus = (Color)-1;

	//将这个牌清空
}

//5.整理压牌区的牌的函数
void ArrangeReservedCard(struct Player &p)
{
	int i, j;
	for (i = 0; i < 2; i++)								//先循环找空
	{
		if (FindtheVoid(p.devcard[i]) == 0)
			for (j = i + 1; j < 3; j++)					//找到空后找后面有没有牌
			{
				if (FindtheVoid(p.devcard[j]) == 1)
				{
					p.devcard[i] = p.devcard[j];		//有牌的话将其补到前面的那个空位
					p.devcard[j].bonus = (Color)0;
					break;
				}
			}
	}
}

//选择买牌命令后的买牌操作（形参：玩家结构体变量名）
void PurchaseCard(struct Player &p)
{
	printf("请输入您欲购入的发展卡之坐标：");
	pos(2, 23);
	int i, number, letterABCD, letterEFG;
	int flag, Pflag, Rflag;
	char order[100];
	DevCard *ChosenCard = NULL;
	do
	{
		number = 0, letterABCD = 0, letterEFG = 0;
		flag = 0, Pflag = 0, Rflag = 0;
		pos(2, 23);
		gets_s(order, 100);
		clearMsgBox();
		for (i = 0; *(order + i) != '\0'; i++)
		{
			if (*(order + i) >= '1'&&*(order + i) <= '3')
				number += 1;
			if (*(order + i) >= 'a'&&*(order + i) <= 'd' || *(order + i) >= 'A'&&*(order + i) <= 'D')
				letterABCD += 1;
			if (*(order + i) >= 'e'&&*(order + i) <= 'g' || *(order + i) >= 'E'&&*(order + i) <= 'G')
				letterEFG += 1;
		}
		if (number == 1)
			if (letterABCD == 1)
				Pflag = 1;
		if (number == 0)
			if (letterEFG == 1)
				Rflag = 1;
		if (Pflag == 0 && Rflag == 0)
		{
			printf("您的输入有误，请重新输入：");
			pos(2, 23);
		}
		if (Pflag == 1)										//这个判断是要买桌面上的牌
		{
			ChooseCard(&ChosenCard, order);
			if (JudgeToBuy(p, *ChosenCard) == 1)
			{
				Purchase(p, *ChosenCard, coin);
				CardOutlineRefresh();
				clearMsgBox();
				PutCard();
				printf("您已成功购入发展卡。");
				Sleep(1000);
				clearMsgBox();
				flag = 1;
			}
			else
			{
				printf("您无法购入此发展卡，请重新输入：");
				pos(2, 23);
			}
		}
		if (Rflag == 1)										//这个判断是要买压牌区上的牌
		{
			ChooseReservedCard(&ChosenCard, p, order);
			if (FindtheVoid(*ChosenCard) == 1)
			{
				if (JudgeToBuy(p, *ChosenCard) == 1)
				{
					Purchase(p, *ChosenCard, coin);
					CardOutlineRefresh();
					clearMsgBox();
					ArrangeReservedCard(p);
					printf("您已成功购入发展卡。");
					Sleep(1000);
					clearMsgBox();
					flag = 1;
				}
				else
				{
					printf("您无法购入此发展卡，请重新输入：");
					pos(2, 23);
				}
			}
			else
			{
				printf("您指定的坐标无发展卡，请重新输入：");
				pos(2, 23);
			}
		}
	} while (flag == 0);
}