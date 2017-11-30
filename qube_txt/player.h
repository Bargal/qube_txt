#pragma once
/*
*klasa opisuj�ca parametry gracza i aktualnego stanu gry
*/
class player
{
	int move;		//oznacznik ruchu
	int positionInOut[6];  //tablica pozycji startowej i ko�cowej: 0-startX, 1-startY, 2-endX, 3-endY, 4 actX, 5 actY
	int timer;		//deklaracja ilosci rund
	int hp;			//zdrowie gracza
	int mov;		//ilosc sko�czonych rund
	int endgame;	//znacznik ko�ca gry
	bool hardMode;	//tryb gry poczatkujacy/ekspert

public:
	//konstruktor (rozmiar planszy x,y)
	player(int, int);

	// wprowadzanie i wysy�anie zmiennych w grze
	int getMoveP();
	int getStartX();
	int getStartY();
	int getEndX();
	int getEndY();
	int getActX();
	int getActY();
	int  getTimer();
	int  getHp();
	int  getMov();
	int  getEndgame();
	bool getHardMode();

	void setMoveP(int);
	void setActY(int);
	void setActX(int);
	void setTimer(int);
	void setHp(int);
	void setMov(int);
	void setEndgame(int);
	void setHardMode(bool);

	~player();
};
