#include"PurchaseCard.h"

/******************************************************************************************************************

										PurchaseCard.cpp:

							ʵ�֡����Ʋ����������ڲ���Ҫ�õ��ĺ�����

							����ͬ��ͷ�ļ�

							��Ҫ������д��������

**************************************************************************************************************************/

//2.ѡ����������λ����ָ��ġ����ѹ�������ϵ��Ƶĺ���
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



//4.����ѡ��д��������ݵĺ���
void Purchase(struct Player &p, DevCard &cCard, Coins &coin)
{
	if (cCard.white > 0)		//��ɫ��Ӧ
	{
		if (cCard.white > p.bonus_white + p.coin_white)						//�׳��벻��
		{
			p.coin_gold -= cCard.white - (p.bonus_white + p.coin_white);		//�ͼ��ƽ�
			coin.gold += cCard.white - (p.bonus_white + p.coin_white);
			p.coin_total -= cCard.white - p.bonus_white;;
			coin.white += p.coin_white;
			p.coin_white = 0;														//���õ����а׳��루�������а׳�������Ҫ�Ļƽ�

		}
		else
			if (cCard.white < p.bonus_white) {}											//���빻��ʲô������
			else
			{
				p.coin_white -= cCard.white - p.bonus_white;
				p.coin_total -= cCard.white - p.bonus_white;
				coin.white += cCard.white - p.bonus_white;
			}																			//���Ļ�ֻ������
	}
	if (cCard.blue > 0)		//��ɫ��Ӧ
	{
		if (cCard.blue > p.bonus_blue + p.coin_blue)							//�����벻��
		{
			p.coin_gold -= cCard.blue - (p.bonus_blue + p.coin_blue);			//�ͼ��ƽ�
			coin.gold += cCard.blue - (p.bonus_blue + p.coin_blue);
			p.coin_total -= cCard.blue - p.bonus_blue;
			coin.blue += p.coin_blue;
			p.coin_blue = 0;														//���õ����������루������������������Ҫ�Ļƽ�
		}
		else
			if (cCard.blue < p.bonus_blue) {}										//���빻��ʲô������
			else
			{
				p.coin_blue -= cCard.blue - p.bonus_blue;
				p.coin_total -= cCard.blue - p.bonus_blue;
				coin.blue += cCard.blue - p.bonus_blue;
			}																			//���Ļ�ֻ������
	}
	if (cCard.green > 0)		//��ɫ��Ӧ
	{
		if (cCard.green > p.bonus_green + p.coin_green)						//�̳��벻��
		{
			p.coin_gold -= cCard.green - (p.bonus_green + p.coin_green);		//�ͼ��ƽ�
			coin.gold += cCard.green - (p.bonus_green + p.coin_green);
			p.coin_total -= cCard.green - p.bonus_green;
			coin.green += p.coin_green;
			p.coin_green = 0;														//���õ������̳��루���������̳�������Ҫ�Ļƽ�
		}
		else
			if (cCard.green < p.bonus_green) {}										//���빻��ʲô������
			else
			{
				p.coin_green -= cCard.green - p.bonus_green;
				p.coin_total -= cCard.green - p.bonus_green;
				coin.green += cCard.green - p.bonus_green;
			}																			//���Ļ�ֻ������
	}
	if (cCard.red > 0)		//��ɫ��Ӧ
	{
		if (cCard.red > p.bonus_red + p.coin_red)								//����벻��
		{
			p.coin_gold -= cCard.red - (p.bonus_red + p.coin_red);			//�ͼ��ƽ�
			coin.gold += cCard.red - (p.bonus_red + p.coin_red);
			p.coin_total -= cCard.red - p.bonus_red;
			coin.red += p.coin_red;
			p.coin_red = 0;															//���õ����к���루�������к��������Ҫ�Ļƽ�
		}
		else
			if (cCard.red < p.bonus_red) {}											//���빻��ʲô������
			else
			{
				p.coin_red -= cCard.red - p.bonus_red;
				p.coin_total -= cCard.red - p.bonus_red;
				coin.red += cCard.red - p.bonus_red;
			}																			//���Ļ�ֻ������
	}
	if (cCard.black > 0)		//��ɫ��Ӧ
	{
		if (cCard.black > p.bonus_black + p.coin_black)						//�ڳ��벻��
		{
			p.coin_gold -= cCard.black - (p.bonus_black + p.coin_black);		//�ͼ��ƽ�
			coin.gold += cCard.black - (p.bonus_black + p.coin_black);
			p.coin_total -= cCard.black - p.bonus_black;
			coin.black += p.coin_black;
			p.coin_black = 0;														//���õ����кڳ��루�������кڳ�������Ҫ�Ļƽ�
		}
		else
			if (cCard.black < p.bonus_black) {}										//���빻��ʲô������
			else
			{
				p.coin_black -= cCard.black - p.bonus_black;
				p.coin_total -= cCard.black - p.bonus_black;
				coin.black += cCard.black - p.bonus_black;
			}																			//���Ļ�ֻ������
	}

	//������Ӧ������ƽ�

	switch (cCard.bonus)
	{
	case (Color)1:
		p.bonus_white += 1;
		p.points += cCard.point; break;		//��ɫ��Ӧ������
	case (Color)2:
		p.bonus_blue += 1;
		p.points += cCard.point; break;	//��ɫ��Ӧ������
	case (Color)3:
		p.bonus_green += 1;
		p.points += cCard.point; break;	//��ɫ��Ӧ������
	case (Color)4:
		p.bonus_red += 1;
		p.points += cCard.point; break;	//��ɫ��Ӧ������
	case (Color)5:
		p.bonus_black += 1;
		p.points += cCard.point; break;	//��ɫ��Ӧ������
	}
	//���ƴ���ı�ʯ���ϣ��ټ�������


	cCard.bonus = (Color)-1;

	//����������
}

//5.����ѹ�������Ƶĺ���
void ArrangeReservedCard(struct Player &p)
{
	int i, j;
	for (i = 0; i < 2; i++)								//��ѭ���ҿ�
	{
		if (FindtheVoid(p.devcard[i]) == 0)
			for (j = i + 1; j < 3; j++)					//�ҵ��պ��Һ�����û����
			{
				if (FindtheVoid(p.devcard[j]) == 1)
				{
					p.devcard[i] = p.devcard[j];		//���ƵĻ����䲹��ǰ����Ǹ���λ
					p.devcard[j].bonus = (Color)0;
					break;
				}
			}
	}
}

//ѡ���������������Ʋ������βΣ���ҽṹ���������
void PurchaseCard(struct Player &p)
{
	printf("��������������ķ�չ��֮���꣺");
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
			printf("���������������������룺");
			pos(2, 23);
		}
		if (Pflag == 1)										//����ж���Ҫ�������ϵ���
		{
			ChooseCard(&ChosenCard, order);
			if (JudgeToBuy(p, *ChosenCard) == 1)
			{
				Purchase(p, *ChosenCard, coin);
				CardOutlineRefresh();
				clearMsgBox();
				PutCard();
				printf("���ѳɹ����뷢չ����");
				Sleep(1000);
				clearMsgBox();
				flag = 1;
			}
			else
			{
				printf("���޷�����˷�չ�������������룺");
				pos(2, 23);
			}
		}
		if (Rflag == 1)										//����ж���Ҫ��ѹ�����ϵ���
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
					printf("���ѳɹ����뷢չ����");
					Sleep(1000);
					clearMsgBox();
					flag = 1;
				}
				else
				{
					printf("���޷�����˷�չ�������������룺");
					pos(2, 23);
				}
			}
			else
			{
				printf("��ָ���������޷�չ�������������룺");
				pos(2, 23);
			}
		}
	} while (flag == 0);
}