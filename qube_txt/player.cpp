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
int player::getStartX() { return positionInOut[0]; }
int player::getStartY() { return positionInOut[1]; }
int player::getEndX() { return positionInOut[2]; }
int player::getEndY() { return positionInOut[3]; }
int player::getActX() { return positionInOut[4]; }
int player::getActY() { return positionInOut[5]; }
int player::getTimer() { return timer; }
int player::getHp() { return hp; }
int player::getMov() { return mov; }
int player::getEndgame() { return endgame; }
bool player::getHardMode() { return hardMode; }

void player::setMoveP(int x) { move = x; }
void player::setActY(int x) { positionInOut[5] = x; }
void player::setActX(int x) { positionInOut[4] = x; }
void player::setTimer(int x) { timer = x; }
void player::setHp(int x) { hp = x; }
void player::setMov(int x) { mov = x; }
void player::setEndgame(int x) { endgame = x; }
void player::setHardMode(bool x) { hardMode = x; }

player::~player()
{
}