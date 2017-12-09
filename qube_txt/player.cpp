#include "stdafx.h"
#include "player.h"
#include <cstdlib>
#include <iostream>
#include <conio.h>

player::player(int xM, int yM)
{
	mov = 0;				//ilosc sko�czonych rund
	int rndX = (xM / 3);
	int rndY = (yM / 3);

	positionInOut[0] = (std::rand() % rndX);				//pozycja startowa
	positionInOut[1] = (std::rand() % rndY);				//pozycja startowa
	positionInOut[2] = (std::rand() % rndX) + (rndX * 2);	//wyjscie
	positionInOut[3] = (std::rand() % rndY) + (rndY * 2);	//wyjscie
	endgame = 0;								//znacznik ko�ca gry
	positionInOut[4] = positionInOut[0];
	positionInOut[5] = positionInOut[1];
}

void player::hpTimeInit()
{
	if (getHardMode())setHp(40);			//zdrowie gracza
	else setHp(30);

	if (getHardMode())setTimer(150);		// deklaracja ilosci rund
	else setTimer(30);
}
int player::gameOver()
{
	system("cls");
	std::cout << "    HP  " << getHp() << "   zakonczone rundy  " << getMov() << "    Pozostalo czasu  "
		<< getTimer() - getMov() << std::endl << std::endl;
	if (getEndgame() == 1) std::cout << "\nNiestety twoje zdrowie spadlo do zera... umarles :) ";
	if (getEndgame() == 2) std::cout << "\nUciekasz wyjsciem bezpieczenstwa przed zakonczeniem zadania.";
	if (getEndgame() == 4) std::cout << "\nNiestety koniec czasu - przegrales.";
	if (getEndgame() == 3)
	{
		std::cout << "\n\nGRATULACJE udalo ci sie wygrac !!!!";
		std::cout << "\nuzyskales " << getHp() / 2 + (getTimer() - getMov()) << " punktow" << std::endl;
	}
	std::cout << "\nKoniec gry nacisnij Q\nponowna gra nacisnij E" << std::endl;
	int tst = 0;
	do
	{
		char a = 0;
		a = _getch();
		if (a == 'e' || a == 'E')return 0;
		else if (a == 'q' || a == 'Q')return 1;
		else tst = 1;
	} while (tst == 1);
	return 1;
}
int player::move()
{
	int x = getActX();
	int y = getActY();

	if (getMoveP() == 0) { --x; setActX(x); }
	else if (getMoveP() == 1) { ++y; setActY(y); }
	else if (getMoveP() == 2) { ++x; setActX(x); }
	else if (getMoveP() == 3) { --y; setActY(y); }
	else if (getMoveP() == 4) return 3;
	else if (getMoveP() == 5) return 0;
	else if (getMoveP() == 6) return 2;
	else return 9;
}

int player::getMoveP() { return moveP; }
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

void player::setMoveP(int x) { moveP = x; }
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