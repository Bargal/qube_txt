#pragma once
class player
{
public:
	int timer;		//deklaracja ilosci rund
	int hp;			//zdrowie gracza
	int mov;		//ilosc skoñczonych rund
	int startX;		//pozycja startowa
	int startY;		//pozycja startowa
	int endX;		//wyjscie
	int endY;		//wyjscie
	int endgame;	//znacznik koñca gry
	bool hardMode;	//tryb gry poczatkujacy/ekspert

	int x;			//aktualna wspó³rzêdna x
	int y;			//aktualna wspó³rzêdna Y
	
	player(int, int);
	//Wysy³anie wartoœci ostatnio wprowadzonego ruchu
	int moveP(); 
	//Wprowadzanie wartoœci ostatnio wprowadzonego ruchu
	void moveP(int);
	
	~player();

private:
	int move;		//oznacznik ruchu

};

