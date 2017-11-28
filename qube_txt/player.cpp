#include "stdafx.h"
#include "player.h"
#include <cstdlib>


player::player(int xM, int yM)
{
	mov = 0;				//ilosc skoñczonych rund
	int rndX = (xM / 3);
	int rndY = (yM / 3);

	startX = (std::rand() % rndX);				//pozycja startowa
	startY = (std::rand() % rndY);				//pozycja startowa
	endX = (std::rand() % rndX) + (rndX * 2);	//wyjscie
	endY = (std::rand() % rndY) + (rndY * 2);	//wyjscie
	endgame = 0;								//znacznik koñca gry
	x = startX;
	y = startY;
}

int player::moveP()
{
	return move;
}

void player::moveP(int x)
{
	move = x;
}


player::~player()
{
}
