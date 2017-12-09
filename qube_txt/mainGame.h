#pragma once
#include"qube.h"
#include "player.h"
class mainGame
{
	int xMain, yMain;
	int end = 0; // !=0 - koniec petli pomocniczej
	qube** p_p_matrix;
	player* p_allData;

public:
	mainGame(qube *[], player, int, int);
	~mainGame();
	int startGame();
	int startGame(player* p_allData, qube** p_p_matrix);
	void defineQ(player * p_allData, qube ** p_p_matrix, int xM, int yM);
	void hardmode(player * p_allData, qube ** p_p_matrix, int xM, int yM);
	int main(player * p_allData, qube ** p_p_matrix);
	void opisQ(player * p_allData, qube ** p_p_matrix);
	int menuQ(player * p_allData, qube ** p_p_matrix);
};
