#include "stdafx.h"
#include "main.cpp"

void  defineQ(gdata *p_allData, qube **p_p_matrix, int xM, int yM)
{
	int  p = 1;			//numerator nazwy pokoju

	for (int i = 0; i < xM; i++)
		for (int j = 0; j < yM; j++)
		{
			p_p_matrix[i][j].qubeIni(p);								//inicjacja g³ówmna lokacji
			p++;

			if (i == 0) p_p_matrix[i][j].exitQ[0] = false;			//dla blokady w
			if (j == (yM - 1)) p_p_matrix[i][j].exitQ[1] = false;	//dla blokady d
			if (i == (xM - 1)) p_p_matrix[i][j].exitQ[2] = false;	//dla blokady s
			if (j == 0) p_p_matrix[i][j].exitQ[3] = false;			//dla blokady a
		}
	if (p_allData->hardMode) hardmode(p_allData, p_p_matrix, xM, yM);
}

void hardmode(gdata* p_allData, qube** p_p_matrix, int xM, int yM)
{
	for (int i = 1; i < (xM - 1); i++)
		for (int j = 1; j < (yM - 1); j++)
		{
			int tmp = (std::rand() % 4);
			p_p_matrix[i][j].exitQ[tmp] = false;
		}
}

void hpTimeInit(gdata* p_allData)
{
	if (p_allData->hardMode)p_allData->hp = 40;			//zdrowie gracza
	else p_allData->hp = 30;

	if (p_allData->hardMode)p_allData->timer = 150;		// deklaracja ilosci rund
	else p_allData->timer = 30;
}