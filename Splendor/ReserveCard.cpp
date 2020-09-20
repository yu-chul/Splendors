#include "ReserveCard.h"

/******************************************************************************************************************

										ReserveCard.cpp:

							实现“压牌操作函数”内部需要用到的函数：

							调用同名头文件

							不要在这里写变量声明

**************************************************************************************************************************/


//2.将已压牌放进玩家区域的函数
void Reserve(struct Player &p, DevCard &cCard, Coins &CommonCoins)
{
	int i;
	for (i = 0; i < 3; i++)
	{
		if (FindtheVoid(p.devcard[i]) == 0)				//先找空位，有空才有地方压过来牌	
		{
			if (CommonCoins.gold > 0)				//如果桌上有黄金
			{
				CommonCoins.gold -= 1;			//筹码区黄金减一
				p.coin_gold += 1;				//玩家区黄金加一
				p.coin_total += 1;
				p.devcard[i] = cCard;		//将牌压过来
				cCard.bonus = (Color)0;		//将桌面上对应牌清空
			}
			else									//如果桌上没有黄金
			{
				p.devcard[i] = cCard;		//只将牌压过来
				cCard.bonus = (Color)0;		//并将桌面上对应牌清空
			}
			break;										//压过牌后就结束遍历
		}
	}
	if (i == 3)
		printf("您的保留牌区已满，无法压牌。");			//遍历一圈没地方压？那你就压不了了~
}

//供外部使用的压牌接口
void ReserveCard(struct Player &p)						//选择买牌命令后的压牌操作（形参：玩家结构体变量名）
{
	int i, number = 0, letterABCD = 0;
	int flag = 0, Rflag = 0;
	char order[10];
	DevCard *ChosenCard = NULL;
	printf("请输入您欲保留的发展卡之编号：");
	do
	{
		pos(2, 23);
		gets_s(order, 10);
		clearMsgBox();
		for (i = 0; *(order + i) != '\0'; i++)
		{
			if (*(order + i) >= '1'&&*(order + i) <= '3')
				number += 1;
			if (*(order + i) >= 'a'&&*(order + i) <= 'd' || *(order + i) >= 'A'&&*(order + i) <= 'D')
				letterABCD += 1;
		}
		if (number == 1)
			if (letterABCD == 1)
				Rflag = 1;
		if (Rflag == 0)
			printf("您的输入有误，请重新输入：");
		if (Rflag == 1)
		{
			ChooseCard(&ChosenCard, order);
			if(ReserveAreaEmpty(p)==1)
			{
				Reserve(p, *ChosenCard, coin);
				PutCard();
				printf("您已成功保留一张发展卡。");
				Sleep(1000);
				clearMsgBox();
				flag = 1;
			}
			else
				printf("你的压牌区没空位了，只能拿筹码或买牌了哟~\n");
		}
	} while (flag == 0);
}