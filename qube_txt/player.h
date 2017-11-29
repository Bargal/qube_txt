#pragma once
/*
*klasa opisuj�ca parametry gracza i aktualnego stanu gry
*/
class player
{
	int move;		//oznacznik ruchu
	int positionInOut[6];  //tablica pozycji startowej i ko�cowej: 0-startX, 1-startY, 2-endX, 3-endY, 4 actX, 5 actY

public:
	int timer;		//deklaracja ilosci rund
	int hp;			//zdrowie gracza
	int mov;		//ilosc sko�czonych rund
	int endgame;	//znacznik ko�ca gry
	bool hardMode;	//tryb gry poczatkujacy/ekspert

	//int x;			//aktualna wsp�rz�dna x
	//int y;			//aktualna wsp�rz�dna Y

	//konstruktor (rozmiar planszy x,y)
	player(int, int);

	// operacje na zmiennych obiektu

//Wysy�anie warto�ci ostatnio wprowadzonego ruchu
	int getMoveP();
	//Wprowadzanie warto�ci ostatnio wprowadzonego ruchu
	void setMoveP(int);

	// wprowadzanie i wysy�anie warto�ci tablicy pozycji w grze

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
