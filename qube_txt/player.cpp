#include "stdafx.h"
#include "player.h"
#include <cstdlib>
#include <iostream>
#include <conio.h>

Player::Player(int xM, int yM) : moveP(0), timer(0), hp(0), hardMode(false)
{
	mov = 0; //number of finite rounds
	int rndX = (xM / 3);
	int rndY = (yM / 3);

	positionInOut[0] = (std::rand() % rndX); //starting position
	positionInOut[1] = (std::rand() % rndY); //starting position
	positionInOut[2] = (std::rand() % rndX) + (rndX * 2); //exit position
	positionInOut[3] = (std::rand() % rndY) + (rndY * 2); //exit position
	endgame = 0; //end of game marker
	positionInOut[4] = positionInOut[0];
	positionInOut[5] = positionInOut[1];
}

void Player::hpTimeInit()
{
	if (getHardMode())setHp(40);			//player health
	else setHp(30);

	if (getHardMode())setTimer(150);		// declaration of the number of rounds
	else setTimer(30);
}
int Player::gameOver()
{
	system("cls");
	std::cout << "    HP  " << getHp() << "   zakonczone rundy  " << getMov() << "    Pozostalo czasu  "
		<< getTimer() - getMov() << std::endl << std::endl;
	if (getEndgame() == 1) std::cout << "\nNiestety twoje zdrowie spadlo do zera... umarles :) " << std::endl;
	if (getEndgame() == 2) std::cout << "\nUciekasz wyjsciem bezpieczenstwa przed zakonczeniem zadania." << std::endl;
	if (getEndgame() == 4) std::cout << "\nNiestety koniec czasu - przegrales." << std::endl;
	if (getEndgame() == 3)
	{
		std::cout << "\n\nGRATULACJE udalo ci sie wygrac !!!!";
		std::cout << "\nuzyskales " << getHp() / 2 + (getTimer() - getMov()) << " punktow" << std::endl;
	}
	std::cout << "\nKoniec gry nacisnij Q\nponowna gra nacisnij E" << std::endl;
	int tst;
	do
	{
		char a = _getch();
		if (a == 'e' || a == 'E')return 0;
		else if (a == 'q' || a == 'Q')return 1;
		else tst = 1;
	} while (tst == 1);
	return 1;
}
int Player::move()
{
	auto x = getActX();
	auto y = getActY();

	if (getMoveP() == 0) { --x; setActX(x); }
	else if (getMoveP() == 1) { ++y; setActY(y); }
	else if (getMoveP() == 2) { ++x; setActX(x); }
	else if (getMoveP() == 3) { --y; setActY(y); }
	else if (getMoveP() == 4) return 3;
	else if (getMoveP() == 5) return 0;
	else if (getMoveP() == 6) return 2;
	else return 9;
	return 0;
}

int Player::getMoveP() { return moveP; }
int Player::getStartX() { return positionInOut[0]; }
int Player::getStartY() { return positionInOut[1]; }
int Player::getEndX() { return positionInOut[2]; }
int Player::getEndY() { return positionInOut[3]; }
int Player::getActX() { return positionInOut[4]; }
int Player::getActY() { return positionInOut[5]; }
int Player::getTimer() { return timer; }
int Player::getHp() { return hp; }
int Player::getMov() { return mov; }
int Player::getEndgame() { return endgame; }
bool Player::getHardMode() { return hardMode; }

void Player::setMoveP(int x) { moveP = x; }
void Player::setActY(int x) { positionInOut[5] = x; }
void Player::setActX(int x) { positionInOut[4] = x; }
void Player::setTimer(int x) { timer = x; }
void Player::setHp(int x) { hp = x; }
void Player::setMov(int x) { mov = x; }
void Player::setEndgame(int x) { endgame = x; }
void Player::setHardMode(bool x) { hardMode = x; }

Player::~Player()
{
}