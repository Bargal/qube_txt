#include "stdafx.h"
#include "player.h"
#include <cstdlib>

player::player(int xM, int yM)
{
	mov = 0;				//ilosc skoñczonych rund
	int rndX = (xM / 3);
	int rndY = (yM / 3);

	positionInOut[0] = (std::rand() % rndX);				//pozycja startowa
	positionInOut[1] = (std::rand() % rndY);				//pozycja startowa
	positionInOut[2] = (std::rand() % rndX) + (rndX * 2);	//wyjscie
	positionInOut[3] = (std::rand() % rndY) + (rndY * 2);	//wyjscie
	endgame = 0;								//znacznik koñca gry
	positionInOut[4] = positionInOut[0];
	positionInOut[5] = positionInOut[1];
}

int player::getMoveP() { return move; }
void player::setMoveP(int x) { move = x; }

int player::getStartX() { return positionInOut[0]; }
void player::setStartX(int x) { positionInOut[0] = x; }

int player::getStartY() { return positionInOut[1]; }
void player::setStartY(int x) { positionInOut[1] = x; }

int player::getEndX() { return positionInOut[2]; }
void player::setEndX(int x) { positionInOut[2] = x; }

int player::getEndY() { return positionInOut[3]; }
void player::setEndY(int x) { positionInOut[3] = x; }

int player::getActX() { return positionInOut[4]; }
void player::setActX(int x) { positionInOut[4] = x; }

int player::getActY() { return positionInOut[5]; }
void player::setActY(int x) { positionInOut[5] = x; }

player::~player()
{
}