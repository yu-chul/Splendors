#include "SaveAndLoad.h"

int SaveGame(int i)
{
	FILE *data;
	errno_t error;
	error = fopen_s(&data,"..\\SaveData\\savedata.dat", "wb+");
	if (error != 0)
		return 1;
	else
	{
		fwrite(ss1, sizeof(SqStack1), 1, data);//桌面牌栈
		fwrite(ss2, sizeof(SqStack2), 1, data);
		fwrite(ss3, sizeof(SqStack3), 1, data);
		fwrite(CmmnCard1, sizeof(struct DevCard), 4, data);//桌面放牌区
		fwrite(CmmnCard2, sizeof(struct DevCard), 4, data);
		fwrite(CmmnCard3, sizeof(struct DevCard), 4, data);
		fwrite(CmmnNoble, sizeof(struct Noble), 5, data);//桌面贵族
		fwrite(&coin, sizeof(struct Coins), 1, data);//桌面贵族
		fwrite(player, sizeof(struct Player), 4, data);//玩家
		fprintf(data, "%4d", Noble1byWho);
		fprintf(data, "%4d", Noble2byWho);
		fprintf(data, "%4d", Noble3byWho);
		fprintf(data, "%4d", Noble4byWho);
		fprintf(data, "%4d", Noble5byWho);//记录贵族被拿取的信息
		fprintf(data, "%4d", numOfPlayer);//玩家人数
		fprintf(data, "%4d", i);//该轮到这名玩家
		fclose(data);
		return 0;
	}
}

int LoadGame()//读取用函数
{
	int i;
	FILE *data;
	errno_t error;
	error = fopen_s(&data, "..\\SaveData\\savedata.dat", "rb+");
	if (error != 0)
		return -1;
	else
	{
		rewind(data);
		fread(ss1, sizeof(SqStack1), 1, data);//桌面牌栈
		fread(ss2, sizeof(SqStack2), 1, data);
		fread(ss3, sizeof(SqStack3), 1, data);
		fread(CmmnCard1, sizeof(struct DevCard), 4, data);//桌面放牌区
		fread(CmmnCard2, sizeof(struct DevCard), 4, data);
		fread(CmmnCard3, sizeof(struct DevCard), 4, data);
		fread(CmmnNoble, sizeof(struct Noble), 5, data);//桌面贵族
		fread(&coin, sizeof(struct Coins), 1, data);//桌面筹码
		fread(player, sizeof(struct Player), 4, data);//玩家
		fscanf_s(data, "%4d", &Noble1byWho);
		fscanf_s(data, "%4d", &Noble2byWho);
		fscanf_s(data, "%4d", &Noble3byWho);
		fscanf_s(data, "%4d", &Noble4byWho);
		fscanf_s(data, "%4d", &Noble5byWho);//记录贵族被拿取的信息
		fscanf_s(data, "%4d", &numOfPlayer);//玩家人数
		fscanf_s(data, "%4d", &i);//该轮到这名玩家
		fclose(data);
		return i;
	}
}