#include "RunGame.h"

//游戏界面初始化
void init()
{
	/****************初始化遊戲信息*****************/
	CmmnCard1[0].bonus = (Color)0;
	CmmnCard1[1].bonus = (Color)0;
	CmmnCard1[2].bonus = (Color)0;
	CmmnCard1[3].bonus = (Color)0;
	CmmnCard2[0].bonus = (Color)0;
	CmmnCard2[1].bonus = (Color)0;
	CmmnCard2[2].bonus = (Color)0;
	CmmnCard2[3].bonus = (Color)0;
	CmmnCard3[0].bonus = (Color)0;
	CmmnCard3[1].bonus = (Color)0;
	CmmnCard3[2].bonus = (Color)0;
	CmmnCard3[3].bonus = (Color)0;
	player[0] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,{(Color)0,0,0,0,0,0} };
	player[1] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,{(Color)0,0,0,0,0,0} };
	player[2] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,{(Color)0,0,0,0,0,0} };
	player[3] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,{(Color)0,0,0,0,0,0} };
	/**************初始化遊戲信息結束***************/
	system("cls");
	system("mode con cols=100 lines=30");
	pos(0, 0);	printf("╔═════════════════════════════════════════════════════════════════════════════════════════════════╗");
	for (int i = 1; i < 29; i++)
	{
		pos(0, i);
		printf("║");
		pos(98, i);
		printf("║");
		if ((i <= 4 && i >= 1) || (i <= 9 && i >= 6) || (i <= 14 && i >= 11) || (i <= 19 && i >= 16))
		{
			pos(76, i);
			printf("┃");
		}
	}
	pos(0, 29); printf("╚═════════════════════════════════════════════════════════════════════════════════════════════════╝");
	for (int i = 1; i < 98; i++)
	{
		pos(i, 21);		printf("━");
	}
	for (int i = 77; i < 98; i++)
	{
		pos(i, 20);		printf("━");
		pos(i, 15);		printf("-");
		pos(i, 10);		printf("-");
		pos(i, 5);		printf("-");
	}
	pos(76, 20);	printf("┗");	pos(76, 20);	printf("┗");
	pos(76, 15);	printf("┠");	pos(76, 15);	printf("┠");
	pos(76, 10);	printf("┠");	pos(76, 10);	printf("┠");
	pos(76, 5);		printf("┠");	pos(76, 5);		printf("┠");
	pos(6, 2);	printf("三级卡堆"); pos(6, 3);	printf("馀张：");
	pos(6, 7);	printf("二级卡堆"); pos(6, 8);	printf("馀张：");
	pos(6, 12);	printf("一级卡堆"); pos(6, 13);	printf("馀张：");
	pos(60, 3); printf("3"); pos(60, 8); printf("2"); pos(60, 13); printf("1");
	CardOutlineRefresh();
	//pos(23,)
	pos(6, 17); col(15); printf("a."); pos(24, 17); col(9); printf("b."); pos(42, 17);	col(10); printf("c.");
	col(7);	pos(8, 18); printf("钻　石"); pos(26, 18); printf("蓝宝石"); pos(44, 18); printf("绿宝石");
	pos(6, 19); col(12); printf("d."); col(8); pos(24, 19); printf("e."); pos(42, 19); col(6); printf("f.");
	col(7);	pos(8, 20); printf("红宝石");	pos(26, 20);  printf("玛　瑙"); pos(44, 20); printf("黄　金");
	pos(23, 16); printf("A"); pos(33, 16); printf("B"); pos(43, 16); printf("C"); pos(53, 16); printf("D");
	col(7); //pos(63, 19); printf("●0●0●0");
	pos(2, 22);
}

//游戏人数选择界面
void numberchoose()
{
	char input[100];
	while (1)
	{
		system("cls");
		system("mode con cols=100 lines=30");
		pos(42, 6);		printf("【1】二人游戏");
		pos(42, 10);	printf("【2】三人游戏");
		pos(42, 14);	printf("【3】四人游戏");
		pos(42, 18);	printf("【4】读取存档");
		pos(40, 22);	printf("【5】返回标题界面");
		pos(0, 25);
		printf("请根据序号选择您要进行的操作：");
		pos(0, 26);
		gets_s(input);
		if (strlen(input) == 1)
		{
			numOfPlayer = atoi(input) + 1;
			switch (numOfPlayer - 1)
			{
			case 1:

			case 2:

			case 3:
				rungame();
				break;
			case 4:
				rungameFromData();
				break;
			case 5:
				return;
			}
		}
	}
}

//游戏结束界面
void endgame(int n)
{
	system("cls");
	system("mode con cols=100 lines=30");
	pos(22, 6);			printf("  .g8\"\"\"bgd        db       `7MMM.     ,MMF'` 7MM\"\"\"YMM  ");		Sleep(500);
	pos(22, 7);			printf(".dP'     `M       ;MM:        MMMb    dPMM     MM    `7  ");		Sleep(500);
	pos(22, 8);			printf("dM'       `      ,V^MM.       M YM   ,M MM     MM   d  "); Sleep(500);
	pos(22, 9);			printf("MM              ,M  `MM       M  Mb  M' MM     MMmmMM  "); Sleep(500);
	pos(22, 10);		printf("MM.    `7MMF'   AbmmmqMA      M  YM.P'  MM     MM   Y  ,"); Sleep(500);
	pos(22, 11);		printf("`Mb.     MM    A'     VML     M  `YM'   MM     MM     ,M "); Sleep(500);
	pos(22, 12);		printf("  `\"bmmmdPY .AMA.    .AMMA. .JML. `'  .JMML. .JMMmmmmMMM "); Sleep(500);


	pos(22, 17);			printf("      .g8\"\"8q.`7MMF'   `7MF'`7MM\"\"\"YMM  `7MM\"\"\"Mq.  "); Sleep(500);
	pos(22, 18);			printf("    .dP'    `YM.`MA     ,V    MM    `7    MM   `MM. "); Sleep(500);
	pos(22, 19);			printf("    dM'      `MM VM:   ,V     MM   d      MM   ,M9  "); Sleep(500);
	pos(22, 20);			printf("    MM        MM  MM.  M'     MMmmMM      MMmmdM9 "); Sleep(500);
	pos(22, 21);			printf("    MM.      ,MP  `MM A'      MM   Y  ,   MM  YM."); Sleep(500);
	pos(22, 22);			printf("    `Mb.    ,dP'   :MM;       MM     ,M   MM   `Mb."); Sleep(500);
	pos(22, 23);			printf("      `\"bmmd\"'      VF      .JMMmmmmMMM .JMML. .JMM."); Sleep(500);
	system("cls");
	system("mode con cols=100 lines=30");
	int temp;
	Player p[4];
	Player q;
	p[0] = player[0];
	p[1] = player[1];
	p[2] = player[2];
	p[3] = player[3];
	int a[4] = { 1,2,3,4 };
	for (int j = 0; j < 4; j++)
	{
		for (int i = 0; i < 3 - j; i++)
		{
			if (p[i].points > p[i + 1].points)
			{
				q = p[i];
				p[i] = p[i + 1];
				p[i + 1] = q;
				temp = a[i];
				a[i] = a[i + 1];
				a[i + 1] = temp;
			}
		}
	}
	int x = 0, y = 0;
	x = p[2].bonus_black + p[2].bonus_blue + p[2].bonus_green + p[2].bonus_red + p[2].bonus_white;
	y = p[3].bonus_black + p[3].bonus_blue + p[3].bonus_green + p[3].bonus_red + p[3].bonus_white;
	if (p[3].points == p[4].points)
	{
		if (x < y)
		{
			q = p[2];
			p[2] = p[3];
			p[3] = q;
			temp = a[2];
			a[2] = a[3];
			a[3] = temp;
		}
	}
	pos(0, 0);	printf("╔═════════════════════════════════════════════════════════════════════════════════════════════════╗");
	for (int i = 1; i < 29; i++)
	{
		pos(0, i);
		printf("║");
		pos(98, i);
		printf("║");
	}
	pos(0, 29); printf("╚═════════════════════════════════════════════════════════════════════════════════════════════════╝");
	pos(2, 1);		printf("MMP\"\"MM\"\"YMM `7MM              `7MMF'     A     `7MF'db         ");
	pos(2, 2);		printf("P'   MM   `7   MM                `MA     ,MA     ,V       ");
	pos(2, 3);		printf("     MM        MMpMMMb.  .gP\"Ya   VM : , VVM : , V `7MM  `7MMpMMMb.  `7MMpMMMb.  .gP\"Ya `7Mb,od8");
	pos(2, 4);		printf("     MM        MM    MM ,M'   Yb   MM.  M' MM.  M'   MM    MM    MM    MM    MM ,M'   Yb  MM' \"'");
	pos(2, 5);		printf("     MM        MM    MM 8M\"\"\"\"\"\"   `MM A'  `MM A'    MM    MM    MM    MM    MM 8M\"\"\"\"\"\"  MM");
	pos(2, 6);		printf("     MM        MM    MM YM.    ,    :MM;    :MM;     MM    MM    MM    MM    MM YM.    ,  MM ");
	pos(2, 7);		printf("   .JMML.    .JMML  JMML.`Mbmmd'     VF      VF    .JMML..JMML  JMML..JMML  JMML.`Mbmmd'.JMML. ");

	pos(2, 9);		printf("           db              `7MM\"\"\"Mq.`7MM                          ");
	pos(2, 10);		printf("                             MM   `MM. MM                            ");
	pos(2, 11);		printf("         `7MM  ,pP\"Ybd       MM   ,M9  MM   ,6\"Yb.`7M'   `MF'.gP\"Ya `7Mb,od8");
	pos(2, 12);		printf("           MM  8I   `\"       MMmmdM9   MM  8)   MM  VA,   V, M'   Yb  MM' \"'");
	pos(2, 13);		printf("           MM  `YMMMa.       MM        MM   ,pm9MM   VA ,V  8M\"\"\"\"\"\"  MM");
	pos(2, 14);		printf("           MM  L.   I8       MM        MM  8M   MM    VVV   YM.    ,  MM ");
	pos(2, 15);		printf("         .JMML.M9mmmP'     .JMML.    .JMML.`Moo9^Yo.  ,V     `Mbmmd'.JMML.");
	pos(2, 16);		printf("                                                     ,V                       ");
	pos(2, 17);		printf("                                                  OOb\"                     ");
	switch (a[3])
	{
	case 1:
	{
		pos(82, 10);	printf("  __,");
		pos(82, 11);	printf("`7MM");
		pos(82, 12);	printf("  MM");
		pos(82, 13);	printf("  MM");
		pos(82, 14);	printf("  MM");
		pos(82, 15);	printf(".JMML");
	}break;
	case 2:
	{
		pos(80, 11);	printf("   pd*\"*b.");
		pos(80, 12);	printf("  (O)   j8 ");
		pos(80, 13);	printf("    ,;j9 ");
		pos(80, 14);	printf("  ,-='   ");
		pos(80, 15);	printf(" Ammmmmmm  ");
	}break;
	case 3:
	{
		pos(80, 11);	printf(" pd\"\"b. ");
		pos(80, 12);	printf("(O)  `8b ");
		pos(80, 13);	printf("     ,89 ");
		pos(80, 14);	printf("   \"\"Yb. ");
		pos(80, 15);	printf("      88  ");
		pos(80, 16);	printf("(O)  .M'");
		pos(80, 17);	printf(" bmmmd' ");
	}break;
	case 4:
	{
		pos(80, 11);	printf("      ,AM ");
		pos(80, 12);	printf("     AVMM   ");
		pos(80, 13);	printf("   ,W' MM   ");
		pos(80, 14);	printf(" ,W'   MM    ");
		pos(80, 15);	printf(" AmmmmmMMmm   ");
		pos(80, 16);	printf("       MM   ");
		pos(80, 17);	printf("       MM    ");
	}break;
	}
	pos(40, 19); printf("其最终得分为：%d", p[3].points);		pos(56, 19); printf("分");
	for (int i = 2; i >= 4 - n; i--)
	{
		pos(34, 25 - i * 2); printf("第%d名：Player%d", 4 - i, a[i]);	pos(52, 25 - i * 2); printf("其最终得分为：%d", p[i].points);
	}
	pos(40, 28);
	system("pause");
	return;
}

//从头进行游戏
void rungame()
{
	init();
	ShuffleAll();			//洗牌（所有牌堆）
	CardsInStack();			//牌堆入棧
	PutCard();				//從牌堆中放牌
	PutNoble(numOfPlayer);	//根据玩家人数放入贵族
	switch (numOfPlayer)
	{
	case 2:
		coin = { 4,4,4,4,4,5 }; break;
	case 3:
		coin = { 5,5,5,5,5,5 }; break;
	case 4:
		coin = { 7,7,7,7,7,5 }; break;
	}
	coinrefresh();
	for (int i = 0; i < numOfPlayer; i++)//玩家界面初始化刷新
	{
		player[i] = { 0 };
		player[i].devcard[0].bonus = (Color)-1;
		player[i].devcard[1].bonus = (Color)-1;
		player[i].devcard[2].bonus = (Color)-1;
		int x1 = 78, x2 = 89;
		int y = 1;
		pos(x1, y + i * 5);	printf("Player"); pos(x2, y + i * 5);	 printf("声望分:");
		pos(x1, y + 1 + i * 5); col(15); printf("●"); col(7); printf("×"); pos(x2, y + 1 + i * 5); col(9); printf("●"); col(7); printf("×");
		pos(x1, y + 2 + i * 5); col(10); printf("●"); col(7); printf("×"); pos(x2, y + 2 + i * 5); col(12); printf("●"); col(7); printf("×");
		pos(x1, y + 3 + i * 5); col(8); printf("●"); col(7); printf("×"); pos(x2, y + 3 + i * 5); col(6); printf("●"); col(7); printf("×");
		playerefresh(i);
	}
	noblefresh1(numOfPlayer);
	pos(2, 22); printf("%d", numOfPlayer);
	//玩家游戏流程
	for (int i = 1; ; i++)
	{
		if (turn(i) == 1)
			return;
		if (player[0].points >= 15 || player[1].points >= 15 || player[2].points >= 15 || player[3].points >= 15)
		{
			while (i != numOfPlayer)
			{
				i++;
				turn(i);
			}
			endgame(numOfPlayer);
		}
		if (i == numOfPlayer)
			i = 0;
	}
}

//从存档进行游戏
void rungameFromData()
{
	init();					//初始化桌面
	int nowPlayer;
	nowPlayer = LoadGame();				//读裆
	coinrefresh();			//刷新桌面筹码显示
	for (int i = 0; i < numOfPlayer; i++)//玩家界面初始化刷新
	{
		int x1 = 78, x2 = 89;
		int y = 1;
		pos(x1, y + i * 5);	printf("Player"); pos(x2, y + i * 5);	 printf("声望分:");
		pos(x1, y + 1 + i * 5); col(15); printf("●"); col(7); printf("×"); pos(x2, y + 1 + i * 5); col(9); printf("●"); col(7); printf("×");
		pos(x1, y + 2 + i * 5); col(10); printf("●"); col(7); printf("×"); pos(x2, y + 2 + i * 5); col(12); printf("●"); col(7); printf("×");
		pos(x1, y + 3 + i * 5); col(8); printf("●"); col(7); printf("×"); pos(x2, y + 3 + i * 5); col(6); printf("●"); col(7); printf("×");
		playerefresh(i);
	}
	for (int i = 0; i < 4; i++)
	{
		card1refresh(&CmmnCard1[i], i);
		card2refresh(&CmmnCard2[i], i);
		card3refresh(&CmmnCard3[i], i);
	}
	noblefresh1(numOfPlayer);		//刷新桌面贵族显示
	if (Noble1byWho != -1)
		noblefresh2(Noble1byWho, 1);
	if (Noble2byWho != -1)
		noblefresh2(Noble2byWho, 2);
	if (Noble3byWho != -1)
		noblefresh2(Noble3byWho, 3);
	if (Noble4byWho != -1)
		noblefresh2(Noble4byWho, 4);
	if (Noble5byWho != -1)
		noblefresh2(Noble5byWho, 5);//刷新贵族被拿取的信息
	pos(2, 22); printf("%d", numOfPlayer);
	//玩家游戏流程
	for (int i = 1; ; i++)
	{
		if (nowPlayer != -1)
		{
			i = nowPlayer;
			nowPlayer = -1;
		}
		if (turn(i) == 1)
			return;
		if (player[0].points >= 15 || player[1].points >= 15 || player[2].points >= 15 || player[3].points >= 15)
		{
			while (i != numOfPlayer)
			{
				i++;
				turn(i);
			}
			endgame(numOfPlayer);
		}
		if (i == numOfPlayer)
			i = 0;
	}
}

//游戏回合
int turn(int n)
{
	regionrefresh(n-1);
	int flag = FALSE;
	char input[100];				//定义输入字符串变量
	while (flag == FALSE)		//判断输入是否合法，当旗帜为TRUE时，跳出循环
	{
		pos(2, 22); col(7);
		printf("Player%d请选择需要进行的操作：", n);
		if (PopCommend_TakeCoins(player[n - 1]) == 0)
			col(8);
		pos(2, 23); printf("【1】拿取宝石"); col(7);
		if (PopCommend_PurchaseCard(player[n - 1]) == 0)
			col(8);
		pos(2, 24); printf("【2】购买发展卡"); col(7);
		if (ReserveAreaEmpty(player[n - 1]) == 0)
			col(8);
		pos(2, 25); printf("【3】保留发展卡"); col(7);
		pos(2, 26); printf("【4】保存游戏存档");
		pos(2, 27); printf("【5】返回上一级");
		pos(2, 28);
		gets_s(input);			//侦测输入
		clearMsgBox();
		if (strlen(input) == 1)
		{
			switch (input[0])
			{
			case '1':
				if (PopCommend_TakeCoins(player[n - 1]) == 0)
				{
					printf("桌面宝石不足！");
					Sleep(1000);
					clearMsgBox();
				}
				else
				{
					takeCoins(&player[n - 1]);
					coinrefresh();
					flag = TRUE;
				}
				break;
			case '2':
				if (PopCommend_PurchaseCard(player[n - 1]) == 0)
				{
					printf("您目前无可购入的发展卡！");
					Sleep(1000);
					clearMsgBox();
				}
				else
				{
					HighlightPurchasableCard(player[n - 1]);
					PurchaseCard(player[n - 1]);
					coinrefresh();
					flag = TRUE;
				}
				break;
			case '3':
				if (ReserveAreaEmpty(player[n - 1]) == 0)
				{
					printf("您的保留牌区已满！");
					Sleep(1000);
					clearMsgBox();
				}
				else
				{
					ReserveCard(player[n - 1]);
					coinrefresh();
					flag = TRUE;
				}
				break;
			case '4':
				if (SaveGame(n) == 0)
				{
					printf("游戏已保存。路径位于：");
					pos(2, 23);
					printf("..\\SaveData\\savedata.dat");
					Sleep(2000);
					clearMsgBox();
				}
				else
				{
					printf("游戏保存失败！");
					Sleep(1000);
					clearMsgBox();
				}
				break;
			case '5':
				return 1;
				break;
			default:
				printf("您的输入有误，请重新输入：");
				pos(2, 23);
				break;
			}
		}
		else
		{
			printf("您的输入有误，请重新输入：");
			pos(2, 23);
		}
	}
	int numOfTakenNoble = TakeNoble(&player[n - 1]);
	if (numOfTakenNoble >= 1 && numOfTakenNoble <= 5)
	{
		noblefresh2(n, numOfTakenNoble);	//贵族
		switch (numOfTakenNoble)
		{
		case 1:
			Noble1byWho = n;
			break;
		case 2:
			Noble2byWho = n;
			break;
		case 3:
			Noble3byWho = n;
			break;
		case 4:
			Noble4byWho = n;
			break;
		case 5:
			Noble5byWho = n;
			break;
		default:
			break;
		}
	}
	for (int x = 2; x < 98; x++)	//清空消息框及当前玩家压牌区
		for (int y = 22; y < 29; y++)
		{
			pos(x, y); printf(" ");
		}
	playerefresh(n - 1);
	return 0;
}

/*pos(20, 2); printf("◆"); pos(25, 2); printf("3");
pos(20, 3); printf("●3"); pos(24, 3); printf("●3");
pos(20, 4); printf("●3"); pos(24, 4); printf("●3");*/
