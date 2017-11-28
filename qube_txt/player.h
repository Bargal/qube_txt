#pragma once
class player
{
public:
	int timer;		//deklaracja ilosci rund
	int hp;			//zdrowie gracza
	int mov;		//ilosc sko�czonych rund
	int startX;		//pozycja startowa
	int startY;		//pozycja startowa
	int endX;		//wyjscie
	int endY;		//wyjscie
	int endgame;	//znacznik ko�ca gry
	bool hardMode;	//tryb gry poczatkujacy/ekspert

	int x;			//aktualna wsp�rz�dna x
	int y;			//aktualna wsp�rz�dna Y
	
	player(int, int);
	//Wysy�anie warto�ci ostatnio wprowadzonego ruchu
	int moveP(); 
	//Wprowadzanie warto�ci ostatnio wprowadzonego ruchu
	void moveP(int);
	
	~player();

private:
	int move;		//oznacznik ruchu

};

