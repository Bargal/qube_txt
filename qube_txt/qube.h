#pragma once
#include <string>
/*
*Klasa opisujaca podstawowa komorke gry w raz z danymi o stanie drzwi, opisem komorki, parametrami gry i jej numerem.
*/
class qube				
{
public:
	std::string infoQ;	//opis tekstowy boxa
	int hpQ;			//obrazenia lub leczenie (hp+ hp-)
	bool exitQ[4];		//tablica wyjsc | 0-W | 1-D | 2-S | 3-A
	int timeQ;			//zmienna rund zabieranych przez box
	int beInsideQ;		//licznik ilosci pobytow w boxie

	void qube::qubeIni(int p);			//inicjacja g³ówmna lokacji

	qube::qube();

	~qube();
};
