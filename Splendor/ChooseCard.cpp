#include "ChooseCard.h"


/*============================将玩家的输入对应到桌面置牌区中=================================*/
void ChooseCard(struct DevCard **cCard, char *order)
{
	int i;
	char CardLevel;
	char CardLocation;
	for (i = 0; *(order + i) != '\0'; i++)
	{
		if (*(order + i) >= '0'&&*(order + i) <= '9')
			CardLevel = *(order + i);
		else if (*(order + i) >= 'a'&&*(order + i) <= 'z' || *(order + i) >= 'A'&&*(order + i) <= 'Z')
			CardLocation = *(order + i);
	}

	switch (CardLevel)
	{
	case '1':
		switch (CardLocation)
		{
		case 'A':*cCard = &CmmnCard1[0]; break;
		case 'B':*cCard = &CmmnCard1[1]; break;
		case 'C':*cCard = &CmmnCard1[2]; break;
		case 'D':*cCard = &CmmnCard1[3]; break;
		case 'a':*cCard = &CmmnCard1[0]; break;
		case 'b':*cCard = &CmmnCard1[1]; break;
		case 'c':*cCard = &CmmnCard1[2]; break;
		case 'd':*cCard = &CmmnCard1[3]; break;
		}break;
	case '2':
		switch (CardLocation)
		{
		case 'A':*cCard = &CmmnCard2[0]; break;
		case 'B':*cCard = &CmmnCard2[1]; break;
		case 'C':*cCard = &CmmnCard2[2]; break;
		case 'D':*cCard = &CmmnCard2[3]; break;
		case 'a':*cCard = &CmmnCard2[0]; break;
		case 'b':*cCard = &CmmnCard2[1]; break;
		case 'c':*cCard = &CmmnCard2[2]; break;
		case 'd':*cCard = &CmmnCard2[3]; break;
		}break;
	case '3':
		switch (CardLocation)
		{
		case 'A':*cCard = &CmmnCard3[0]; break;
		case 'B':*cCard = &CmmnCard3[1]; break;
		case 'C':*cCard = &CmmnCard3[2]; break;
		case 'D':*cCard = &CmmnCard3[3]; break;
		case 'a':*cCard = &CmmnCard3[0]; break;
		case 'b':*cCard = &CmmnCard3[1]; break;
		case 'c':*cCard = &CmmnCard3[2]; break;
		case 'd':*cCard = &CmmnCard3[3]; break;
		}break;
	}
}