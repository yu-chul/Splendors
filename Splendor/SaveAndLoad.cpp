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
		fwrite(ss1, sizeof(SqStack1), 1, data);//������ջ
		fwrite(ss2, sizeof(SqStack2), 1, data);
		fwrite(ss3, sizeof(SqStack3), 1, data);
		fwrite(CmmnCard1, sizeof(struct DevCard), 4, data);//���������
		fwrite(CmmnCard2, sizeof(struct DevCard), 4, data);
		fwrite(CmmnCard3, sizeof(struct DevCard), 4, data);
		fwrite(CmmnNoble, sizeof(struct Noble), 5, data);//�������
		fwrite(&coin, sizeof(struct Coins), 1, data);//�������
		fwrite(player, sizeof(struct Player), 4, data);//���
		fprintf(data, "%4d", Noble1byWho);
		fprintf(data, "%4d", Noble2byWho);
		fprintf(data, "%4d", Noble3byWho);
		fprintf(data, "%4d", Noble4byWho);
		fprintf(data, "%4d", Noble5byWho);//��¼���屻��ȡ����Ϣ
		fprintf(data, "%4d", numOfPlayer);//�������
		fprintf(data, "%4d", i);//���ֵ��������
		fclose(data);
		return 0;
	}
}

int LoadGame()//��ȡ�ú���
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
		fread(ss1, sizeof(SqStack1), 1, data);//������ջ
		fread(ss2, sizeof(SqStack2), 1, data);
		fread(ss3, sizeof(SqStack3), 1, data);
		fread(CmmnCard1, sizeof(struct DevCard), 4, data);//���������
		fread(CmmnCard2, sizeof(struct DevCard), 4, data);
		fread(CmmnCard3, sizeof(struct DevCard), 4, data);
		fread(CmmnNoble, sizeof(struct Noble), 5, data);//�������
		fread(&coin, sizeof(struct Coins), 1, data);//�������
		fread(player, sizeof(struct Player), 4, data);//���
		fscanf_s(data, "%4d", &Noble1byWho);
		fscanf_s(data, "%4d", &Noble2byWho);
		fscanf_s(data, "%4d", &Noble3byWho);
		fscanf_s(data, "%4d", &Noble4byWho);
		fscanf_s(data, "%4d", &Noble5byWho);//��¼���屻��ȡ����Ϣ
		fscanf_s(data, "%4d", &numOfPlayer);//�������
		fscanf_s(data, "%4d", &i);//���ֵ��������
		fclose(data);
		return i;
	}
}