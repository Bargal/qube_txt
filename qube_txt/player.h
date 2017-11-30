#pragma once
/*
*klasa opisuj¹ca parametry gracza i aktualnego stanu gry
*/
class player
{
	int move;		//oznacznik ruchu
	int positionInOut[6];  //tablica pozycji startowej i koñcowej: 0-startX, 1-startY, 2-endX, 3-endY, 4 actX, 5 actY
	int timer;		//deklaracja ilosci rund
	int hp;			//zdrowie gracza
	int mov;		//ilosc skoñczonych rund
	int endgame;	//znacznik koñca gry
	bool hardMode;	//tryb gry poczatkujacy/ekspert

public:
	//konstruktor (rozmiar planszy x,y)
	player(int, int);

	// wprowadzanie i wysy³anie zmiennych w grze
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
