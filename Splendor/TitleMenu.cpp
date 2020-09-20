#include "TitleMenu.h"

//游戏主界面初始化
void initgame()
{
	system("cls");
	system("mode con cols=100 lines=30");
	pos(7, 4); printf("■■■　■　■　　■　■■■　■■　■■■　　　　　　■　　　　　■■■■■■■■■■");
	pos(7, 5); printf("　■　　■　■　　■　　■　　■　　■　■　■■■■■■■■■■　　　　　■");
	pos(7, 6); printf("　■　　■■■■■■　　■　■■■■　■　　■　　　　　　　　■　　　　　■");
	pos(7, 7); printf("■■■　■　　■　　　■■■■　■　■　■　　　　　　　　　　　　　　　■");
	pos(7, 8); printf("　■　　■■■■■■　　■　　■　■　　　　　■■■■■■■■　　　　■■■■■■■");
	pos(7, 9); printf("　■　■■　　■　　　　■　■　　■　■　　　　　　　■　　　　　　■■　　　　　■");
	pos(7, 10); printf("　■■　■■■■■■　　■■■■■■■■■　　■■■■■■■■　　■　■　　　　　■");
	pos(7, 11); printf("■■　　■　　■　　　■■　　　　■　　　　　　　　　■　■　　　　　■　　　　　■");
	pos(7, 12); printf("　　　　■　　■　　　　　　　■　■　■　　　　　　　■　　■　　　　■■■■■■■");
	pos(7, 13); printf("　　　　■■■■■■　　　　■　　■　　■　■■■■■■■■■■　　　■　　　　　■");
	pos(42, 18); printf("【1】开始游戏");
	pos(42, 20); printf("【2】游戏说明");
	pos(42, 22); printf("【3】开发团队");
	pos(42, 24); printf("【4】退    出");
	pos(0, 26);
}

//游戏说明界面
void gamexplain()
{
	system("cls");
	system("mode con cols=100 lines=30");
	int i, n = 0;

	pos(0, 25);
	printf("请输入1来返回主界面：");
	scanf_s("%d", &i);
	while (i != 1)
	{
		if (n == 1)
			printf("请输入正确的数字，否则将自动退回:");
		else	printf("请输入1来返回主界面：");
		scanf_s("%d", &i);
		n++;
		if (n == 2)
			i = 1;
	}
	return;
}

//游戏说明界面操作
void gamedeveloper()
{
	system("cls");
	system("mode con cols=100 lines=30");
	int i, n = 0;
	pos(0, 25);
	printf("请输入1来返回主界面：");
	scanf_s("%d", &i);
	while (i != 1)
	{
		if (n == 1)
			printf("请输入正确的数字，否则将自动退回:");
		else	printf("请输入1来返回主界面：");
		scanf_s("%d", &i);
		n++;
		if (n == 2)
			i = 1;
	}
	TitleMenu();
}

void TitleMenu()
{
	char a[100];
	while (1)
	{
		system("cls");
		initgame();
		pos(0, 26);
		printf("请根据序号选择您要进行的操作：");
		a[0] = '\0';
		pos(0, 27);
		gets_s(a);
		if (strlen(a) == 1)
		{
			switch (a[0])
			{
			case '1':
				numberchoose();
				break;
			case '2':
				GameIntro();
				break;
			case '3':
				gamedeveloper();
				break;
			case '4':
				exit(0);
				break;
			default:
				pos(0, 26);
				printf("您的输入有误，请重新输入！    ");
				Sleep(1000);
				break;
			}
		}
		else
		{
			pos(0, 26);
			printf("您的输入有误，请重新输入！      ");
			Sleep(1000);
		}
	}
}

