#pragma once
/*
*klasa opisuj¹ca parametry gracza i aktualnego stanu gry
*/
class player
{
	int move;		//oznacznik ruchu
	int positionInOut[6];  //tablica pozycji startowej i koñcowej: 0-startX, 1-startY, 2-endX, 3-endY, 4 actX, 5 actY

public:
	int timer;		//deklaracja ilosci rund
	int hp;			//zdrowie gracza
	int mov;		//ilosc skoñczonych rund
	int endgame;	//znacznik koñca gry
	bool hardMode;	//tryb gry poczatkujacy/ekspert

	//int x;			//aktualna wspó³rzêdna x
	//int y;			//aktualna wspó³rzêdna Y

	//konstruktor (rozmiar planszy x,y)
	player(int, int);

	// operacje na zmiennych obiektu

//Wysy³anie wartoœci ostatnio wprowadzonego ruchu
	int getMoveP();
	//Wprowadzanie wartoœci ostatnio wprowadzonego ruchu
	void setMoveP(int);

	// wprowadzanie i wysy³anie wartoœci tablicy pozycji w grze

	int getStartX();
	int getStartY();
	int getEndX();
	int getEndY();
	int getActX();
	void setActX(int);
	int getActY();
	void setActY(int);

	~player();
};
