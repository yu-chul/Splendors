#include "UIRefresh.h"

//玩家信息刷新
void playerefresh(int n)
{
	pos(84, 1 + n * 5); printf("%d", n + 1); pos(96, 1 + n * 5); printf("%d", player[n].points);
	pos(82, 2 + n * 5); printf("%d", player[n].coin_white); pos(93, 2 + n * 5); printf("%d", player[n].coin_blue);
	pos(82, 3 + n * 5); printf("%d", player[n].coin_green); pos(93, 3 + n * 5); printf("%d", player[n].coin_red);
	pos(82, 4 + n * 5); printf("%d", player[n].coin_black); pos(93, 4 + n * 5); printf("%d", player[n].coin_gold);
	if (player[n].bonus_white != 0)
	{
		pos(84, 2 + n * 5); printf("+%d", player[n].bonus_white);
	}
	if (player[n].bonus_green != 0)	
	{
		pos(84, 3 + n * 5); printf("+%d", player[n].bonus_green);
	}
	if (player[n].bonus_black != 0)
	{
		pos(84, 4 + n * 5); printf("+%d", player[n].bonus_black);
	}
	if (player[n].bonus_blue != 0)
	{
		pos(95, 2 + n * 5); printf("+%d", player[n].bonus_blue);
	}
	if (player[n].bonus_red != 0)
	{
		pos(95, 3 + n * 5); printf("+%d", player[n].bonus_red);
	}
	pos(2, 22);
}

//桌面一级牌刷新
void card1refresh(DevCard *p, int n)
{
	int x, y;
	y = 12;
	switch (n)
	{
	case 0:x = 20; break;
	case 1:x = 30; break;
	case 2:x = 40; break;
	case 3:x = 50; break;
	}
	for (int a = x; a < x + 7; a++)
		for (int b = y; b < y + 3; b++)
		{
			pos(a, b); printf(" ");
		}
	switch (p->bonus)
	{
	case 1:pos(x, y); col(15); printf("◆"); col(7); break;
	case 2:pos(x, y); col(9); printf("◆"); col(7); break;
	case 3:pos(x, y); col(10); printf("◆"); col(7); break;
	case 4:pos(x, y); col(12); printf("◆"); col(7); break;
	case 5:pos(x, y); col(8); printf("◆"); col(7); break;
	}
	if (p->point != 0)
	{
		pos(x + 6, y); printf("%d", p->point);
	}
	int color[4] = { 0 };
	int pay[4] = { 0 };
	int i = 0;
	if (p->white != 0)
	{
		color[i] = 15;
		pay[i] = p->white;
		i++;
	}
	if (p->blue != 0)
	{
		color[i] = 9;
		pay[i] = p->blue;
		i++;
	}
	if (p->green != 0)
	{
		color[i] = 10;
		pay[i] = p->green;
		i++;
	}
	if (p->red != 0)
	{
		color[i] = 12;
		pay[i] = p->red;
		i++;
	}
	if (p->black != 0)
	{
		color[i] = 8;
		pay[i] = p->black;
		i++;
	}
	for (int j = 0; j < 2; j++)
	{
		if (color[j] != 0)
		{
			pos(x, y + 1 + j); col(color[j]); printf("●"); col(7); printf("%d", pay[j]);
		}
	}
	for (int j = 2; j < i; j++)
	{
		pos(x + 4, y + 1 + j - 2); col(color[j]); printf("●"); col(7); printf("%d", pay[j]);
	}
	pos(12, 13);
	printf("%2d", ss1->top + 1);		//一級卡堆剩餘卡牌刷新
	if (p->bonus == -1 && ss1->top == -1)
	{
		for (int i = 0; i < 10; i++)
			for (int j = 0; j < 5; j++)
			{
				pos(x - 2 + i, y - 1 + j); printf(" ");
			}
	}
	pos(2, 22);
}
//桌面二级牌刷新
void card2refresh(DevCard *p, int n)
{
	int x, y;
	y = 7;
	switch (n)
	{
	case 0:x = 20; break;
	case 1:x = 30; break;
	case 2:x = 40; break;
	case 3:x = 50; break;
	}
	for (int a = x; a < x + 7; a++)
		for (int b = y; b < y + 3; b++)
		{
			pos(a, b); printf(" ");
		}
	switch (p->bonus)
	{
	case 1:pos(x, y); col(15); printf("◆"); col(7); break;
	case 2:pos(x, y); col(9); printf("◆"); col(7); break;
	case 3:pos(x, y); col(10); printf("◆"); col(7); break;
	case 4:pos(x, y); col(12); printf("◆"); col(7); break;
	case 5:pos(x, y); col(8); printf("◆"); col(7); break;
	}
	if (p->point != 0)
	{
		pos(x + 6, y); printf("%d", p->point);
	}
	int color[4] = { 0 };
	int pay[4] = { 0 };
	int i = 0;
	if (p->white != 0)
	{
		color[i] = 15;
		pay[i] = p->white;
		i++;
	}
	if (p->blue != 0)
	{
		color[i] = 9;
		pay[i] = p->blue;
		i++;
	}
	if (p->green != 0)
	{
		color[i] = 10;
		pay[i] = p->green;
		i++;
	}
	if (p->red != 0)
	{
		color[i] = 12;
		pay[i] = p->red;
		i++;
	}
	if (p->black != 0)
	{
		color[i] = 8;
		pay[i] = p->black;
		i++;
	}
	for (int j = 0; j < 2; j++)
	{
		if (color[j] != 0)
		{
			pos(x, y + 1 + j); col(color[j]); printf("●"); col(7); printf("%d", pay[j]);
		}
	}
	for (int j = 2; j < i; j++)
	{
		pos(x + 4, y + 1 + j - 2); col(color[j]); printf("●"); col(7); printf("%d", pay[j]);
	}
	pos(12, 8);
	printf("%2d", ss2->top + 1);		//二級卡堆剩餘卡牌刷新
	if (p->bonus == -1 && ss2->top == -1)
	{
		for (int i = 0; i < 10; i++)
			for (int j = 0; j < 5; j++)
			{
				pos(x - 2 + i, y - 1 + j); printf(" ");
			}
	}
	pos(2, 22);
}
//桌面三级牌刷新
void card3refresh(DevCard *p, int n)
{
	int x, y;
	y = 2;
	switch (n)
	{
	case 0:x = 20; break;
	case 1:x = 30; break;
	case 2:x = 40; break;
	case 3:x = 50; break;
	}
	for (int a = x; a < x + 7; a++)
		for (int b = y; b < y + 3; b++)
		{
			pos(a, b); printf(" ");
		}
	switch (p->bonus)
	{
	case 1:pos(x, y); col(15); printf("◆"); col(7); break;
	case 2:pos(x, y); col(9); printf("◆"); col(7); break;
	case 3:pos(x, y); col(10); printf("◆"); col(7); break;
	case 4:pos(x, y); col(12); printf("◆"); col(7); break;
	case 5:pos(x, y); col(8); printf("◆"); col(7); break;
	}
	if (p->point != 0)
	{
		pos(x + 6, y); printf("%d", p->point);
	}
	int color[4] = { 0 };
	int pay[4] = { 0 };
	int i = 0;
	if (p->white != 0)
	{
		color[i] = 15;
		pay[i] = p->white;
		i++;
	}
	if (p->blue != 0)
	{
		color[i] = 9;
		pay[i] = p->blue;
		i++;
	}
	if (p->green != 0)
	{
		color[i] = 10;
		pay[i] = p->green;
		i++;
	}
	if (p->red != 0)
	{
		color[i] = 12;
		pay[i] = p->red;
		i++;
	}
	if (p->black != 0)
	{
		color[i] = 8;
		pay[i] = p->black;
		i++;
	}
	for (int j = 0; j < 2; j++)
	{
		if (color[j] != 0)
		{
			pos(x, y + 1 + j); col(color[j]); printf("●"); col(7); printf("%d", pay[j]);
		}
	}
	for (int j = 2; j < i; j++)
	{
		pos(x + 4, y + 1 + j - 2); col(color[j]); printf("●"); col(7); printf("%d", pay[j]);
	}
	pos(12, 3);
	printf("%2d", ss3->top + 1);		//三級卡堆剩餘卡牌刷新
	if (p->bonus == -1 && ss3->top == -1)
	{
		for (int i = 0; i < 10; i++)
			for (int j = 0; j < 5; j++)
			{
				pos(x - 2 + i, y - 1 + j); printf(" ");
			}
	}
	pos(2, 22);
}

//筹码刷新
void coinrefresh()
{
	int i;
	//白色
	for (int x = 8; x < 23; x++)
	{
		pos(x, 17); printf(" ");
	}
	for (i = 0; i < coin.white; i++)
	{
		col(15); pos(8 + i * 2, 17); printf("●");
	}
	//蓝色
	for (int x = 26; x < 41; x++)
	{
		pos(x, 17); printf(" ");
	}
	for (i = 0; i < coin.blue; i++)
	{
		col(9); pos(26 + i * 2, 17); printf("●");
	}
	//绿色
	for (int x = 44; x < 59; x++)
	{
		pos(x, 17); printf(" ");
	}
	for (i = 0; i < coin.green; i++)
	{
		col(10); pos(44 + i * 2, 17); printf("●");
	}
	//红色
	for (int x = 8; x < 23; x++)
	{
		pos(x, 19); printf(" ");
	}
	for (i = 0; i < coin.red; i++)
	{
		
		col(12); pos(8 + i * 2, 19); printf("●");
	}
	//黑色
	for (int x = 26; x < 41; x++)
	{
		pos(x, 19); printf(" ");
	}
	for (i = 0; i < coin.black; i++)
	{
		col(8); pos(26 + i * 2, 19); printf("●");
	}
	//黄金
	for (int x = 44; x < 59; x++)
	{
		pos(x, 19); printf(" ");
	}
	for (i = 0; i < coin.gold; i++)
	{
		col(6); pos(44 + i * 2, 19); printf("●");
	}
	pos(2, 22); col(7);
}
//押牌区刷新
int regionrefresh(int n)
{
	int a = 0;
	for (int i = 0; i < 3; i++)
	{
		if (player[n].devcard[i].bonus != -1)//(Color)
			a++;
	}
	pos(64, 22); printf("Player"); printf("%d", n + 1); printf("的保留牌区：");
	if (a == 0)
	{
		return 0;
	}
	else
	{
		int x1[3] = { 64,75,86 };
		int y = 23;
		for (int i = 0; i < a; i++)	//桌面卡牌
		{
			pos(x1[i], y);			printf("┌");
			pos(x1[i] + 9, y);		printf("┐");
			pos(x1[i], y + 4);		printf("└");
			pos(x1[i] + 9, y + 4);	printf("┘");
		}
		for (int i = 0; i < a; i++)
			for (int j = 0; j < 7; j++)
			{
				pos(x1[i] + 1 + j, y);			printf("─");
				pos(x1[i] + 1 + j, y + 4);		printf("─");
			}
		for (int i = 0; i < a; i++)
			for (int j = 0; j < 3; j++)
			{
				pos(x1[i], y + j + 1);				printf("│");
				pos(x1[i] + 9, y + j + 1);			printf("│");
			}
		switch (a)
		{
		case 0:break;
		case 1:pos(69, 28); printf("E"); break;
		case 2:pos(69, 28); printf("E"); pos(80, 28); printf("F"); break;
		case 3:pos(69, 28); printf("E"); pos(80, 28); printf("F"); pos(91, 28); printf("G"); break;
		default:
			break;
		}
		for (int i = 0; i < a; i++)
		{
			switch (player[n].devcard[i].bonus)
			{
			case 1:pos(x1[i] + 2, y + 1); col(15);	printf("◆");			break;
			case 2:pos(x1[i] + 2, y + 1); col(9);	printf("◆");	col(7); break;
			case 3:pos(x1[i] + 2, y + 1); col(10);	printf("◆");	col(7); break;
			case 4:pos(x1[i] + 2, y + 1); col(12);	printf("◆");	col(7); break;
			case 5:pos(x1[i] + 2, y + 1); col(8);	printf("◆");	col(7); break;
			}
			if (player[n].devcard[i].point != 0)
			{
				pos(x1[i] + 8, y + 1); printf("%d", player[n].devcard[i].point);
			}
			int color[4] = { 0 };
			int pay[4] = { 0 };
			int x = 0;
			if (player[n].devcard[i].white != 0)
			{
				color[x] = 15;
				pay[x] = player[n].devcard[i].white;
				x++;
			}
			if (player[n].devcard[i].blue != 0)
			{
				color[x] = 9;
				pay[x] = player[n].devcard[i].blue;
				x++;
			}
			if (player[n].devcard[i].green != 0)
			{
				color[x] = 10;
				pay[x] = player[n].devcard[i].green;
				x++;
			}
			if (player[n].devcard[i].red != 0)
			{
				color[x] = 12;
				pay[x] = player[n].devcard[i].red;
				x++;
			}
			if (player[n].devcard[i].black != 0)
			{
				color[x] = 8;
				pay[x] = player[n].devcard[i].black;
				x++;
			}
			for (int j = 0; j < 2; j++)
			{
				if (color[j] != 0)
				{
					pos(x1[i] + 2, y + 2 + j); col(color[j]); printf("●"); col(7); printf("%d", pay[j]);
				}
			}
			for (int j = 2; j < 4; j++)
			{
				if (color[j] != 0)
				{
					pos(x1[i] + 6, y + 2 + j - 2); col(color[j]); printf("●"); col(7); printf("%d", pay[j]);
				}
			}
		}
	}
	pos(2, 22); col(7);
	return 1;
}
/*
pos(66, 24); printf("◆");	pos(72, 24); printf("3");
pos(66, 25); printf("◆3");	pos(70, 25); printf("◆3");
pos(66, 26); printf("◆3");	pos(70, 26); printf("◆3");
*/

//贵族初始刷新
void noblefresh1(int n)
{
	n += 1;
	int y2[5] = { 1,5,9,13,17 };
	for (int i = 0; i < n; i++)	//贵族
	{
		pos(62, y2[i]);			 printf("┌");
		pos(62, y2[i] + 3);		 printf("└");
		pos(72, y2[i]);			 printf("┐");
		pos(72, y2[i] + 3);		 printf("┘");
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < 3; j++)
			for (int k = 1; k <= 8; k++)
				for (int k = 1; k <= 8; k++)
				{
					pos(62 + k, y2[i]);					printf("─");
					pos(62 + k, y2[i] + 3);				printf("─");
				}
	for (int j = 0; j < n; j++)
		for (int k = 1; k <= 2; k++)
		{
			pos(62, y2[j] + k);		printf("│");
			pos(72, y2[j] + k);		printf("│");
		}
	for (int i = 0; i < n; i++)
	{
		pos(74, 2 + i * 4); printf("%d", i + 1);
	}
	for (int i = 0; i < n; i++)
	{
		int x = 0, y = 0;
		pos(64, y2[i] + 1);		printf("+3");
		int color1[5] = { 0 };
		int color2[5] = { 0 };
		if (CmmnNoble[i].white != 0)
			x++;
		if (CmmnNoble[i].blue != 0)
			x++;
		if (CmmnNoble[i].green != 0)
			x++;
		if (CmmnNoble[i].red != 0)
			x++;
		if (CmmnNoble[i].black != 0)
			x++;
		switch (x)
		{
		case 2:
		{
			if (CmmnNoble[i].white != 0)
			{
				color1[y] = 15;
				y++;
			}
			if (CmmnNoble[i].blue != 0)
			{
				color1[y] = 9;
				y++;
			}
			if (CmmnNoble[i].green != 0)
			{
				color1[y] = 10;
				y++;
			}
			if (CmmnNoble[i].red != 0)
			{
				color1[y] = 12;
				y++;
			}
			if (CmmnNoble[i].black != 0)
			{
				color1[y] = 8;
				y++;
			}
			pos(64, y2[i] + 2); col(color1[0]); printf("■"); col(7); printf("4");
			pos(69, y2[i] + 2); col(color1[1]); printf("■"); col(7); printf("4");
		}
		break;
		case 3:
		{
			if (CmmnNoble[i].white != 0)
			{
				color2[y] = 15;
				y++;
			}
			if (CmmnNoble[i].blue != 0)
			{
				color2[y] = 9;
				y++;
			}
			if (CmmnNoble[i].green != 0)
			{
				color2[y] = 10;
				y++;
			}
			if (CmmnNoble[i].red != 0)
			{
				color2[y] = 12;
				y++;
			}
			if (CmmnNoble[i].black != 0)
			{
				color2[y] = 8;
				y++;
			}
			pos(64, y2[i] + 2); col(color2[0]); printf("■"); col(7); printf("3");
			pos(69, y2[i] + 1); col(color2[1]); printf("■"); col(7); printf("3");
			pos(69, y2[i] + 2); col(color2[2]); printf("■"); col(7); printf("3");
		}
		break;
		default:
			break;
		}
	}
	pos(2, 22); col(7);
}


//贵族获得刷新
void noblefresh2(int n, int y)
{
	//n为玩家数，y为贵族标号
	int y1;
	switch (y)
	{
	case 1:y1 = 1;	break;
	case 2:y1 = 5;	break;
	case 3:y1 = 9;	break;
	case 4:y1 = 13;	break;
	case 5:y1 = 17; break;
	}
	for (int x = 62; x < 73; x++)
		for (int a = y1; a < y1 + 4; a++)
		{
			pos(x, a); printf(" ");
		}
	pos(63, y1 + 1); printf("该贵族问访");
	pos(63, y1 + 2); printf(" Player%d", n);
	pos(2, 22); col(7);
}

void HighlightPurchasableCard(struct Player &p)	//高亮可买牌
{
	int i;
	int x;
	int a = 0;
	for (i = 0; i < 4; i++)				//看玩家能否买桌面上的牌
	{
		if (JudgeToBuy(p, CmmnCard1[i]) == 1)
		{
			col(14);
			switch (i)
			{
			case 0:x = 18; break;
			case 1:x = 28; break;
			case 2:x = 38; break;
			case 3:x = 48; break;
			}
			pos(x, 11);			printf("┌");
			pos(x + 9, 11);		printf("┐");
			pos(x, 15);			printf("└");
			pos(x + 9, 15);		printf("┘");
			for (int k = 1; k <= 8; k++)
			{
				pos(x + k, 11);		printf("─");
				pos(x + k, 15);		printf("─");
			}
			for (int k = 1; k <= 3; k++)
			{
				pos(x, 11 + k);			printf("│");
				pos(x + 9, 11 + k);		printf("│");
			}
		}
		if (JudgeToBuy(p, CmmnCard2[i]) == 1)
		{
			col(14);
			switch (i)
			{
			case 0:x = 18; break;
			case 1:x = 28; break;
			case 2:x = 38; break;
			case 3:x = 48; break;
			}
			pos(x, 6);			printf("┌");
			pos(x + 9, 6);		printf("┐");
			pos(x, 10);		printf("└");
			pos(x + 9, 10);	printf("┘");
			for (int k = 1; k <= 8; k++)
			{
				pos(x + k, 6);			printf("─");
				pos(x + k, 10);		printf("─");
			}
			for (int k = 1; k <= 3; k++)
			{
				pos(x, 6 + k);			printf("│");
				pos(x + 9, 6 + k);		printf("│");
			}
		}
		if (JudgeToBuy(p, CmmnCard3[i]) == 1)
		{
			col(14);
			switch (i)
			{
			case 0:x = 18; break;
			case 1:x = 28; break;
			case 2:x = 38; break;
			case 3:x = 48; break;
			}
			pos(x, 1);			printf("┌");
			pos(x + 9, 1);		printf("┐");
			pos(x, 5);		printf("└");
			pos(x + 9, 5);	printf("┘");
			for (int k = 1; k <= 8; k++)
			{
				pos(x + k, 1);			printf("─");
				pos(x + k, 5);		printf("─");
			}
			for (int k = 1; k <= 3; k++)
			{
				pos(x, 1 + k);			printf("│");
				pos(x + 9, 1 + k);		printf("│");
			}
		}
	}
	for (int j = 0; j < 3; j++)
		{
			if (p.devcard->bonus != (Color)-1)
				a++;
		}
	if (a != 0)
	{
		for (i = 0; i < a; i++)
			if (JudgeToBuy(p, p.devcard[i]) == 1)
			{
				col(14);
				switch (i)
				{
				case 0:x = 64; break;
				case 1:x = 75; break;
				case 2:x = 86; break;
				}
				for (int j = 0; j < 8; j++)
				{
					pos(x + 1 + j, 23);		printf("─");
					pos(x + 1 + j, 27);		printf("─");
				}
				for (int j = 0; j < 3; j++)
				{
					pos(x, 23 + j + 1);				printf("│");
					pos(x + 9, 23 + j + 1);			printf("│");
				}
				pos(x, 23);			printf("┌");
				pos(x + 9, 23);		printf("┐");
				pos(x, 27);			printf("└");
				pos(x + 9, 27);		printf("┘");
			}
	}
	pos(2, 22); col(7);
}

//清空消息框
void clearMsgBox()
{
	for (int x = 2;x < 50; x++)
		for (int y = 22; y < 29; y++)
		{
			pos(x, y); printf(" ");
		}
	pos(2, 22);
}

//刷新桌面置牌区牌外框
void CardOutlineRefresh()
{
	int x[4] = { 18,28,38,48 };		//62
	int y1[3] = { 1,6,11 };
	for (int i = 0; i < 4; i++)	//桌面卡牌
		for (int j = 0; j < 3; j++)
		{
			pos(x[i], y1[j]);			printf("┌");
			pos(x[i] + 9, y1[j]);		printf("┐");
			pos(x[i], y1[j] + 4);		printf("└");
			pos(x[i] + 9, y1[j] + 4);	printf("┘");
		}
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 3; j++)
			for (int k = 1; k <= 8; k++)
			{
				pos(x[i] + k, y1[j]);			printf("─");
				pos(x[i] + k, y1[j] + 4);		printf("─");
			}
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 3; j++)
			for (int k = 1; k <= 3; k++)
			{
				pos(x[i], y1[j] + k);			printf("│");
				pos(x[i] + 9, y1[j] + k);		printf("│");
			}
}