#pragma once
#include <string>

/*
* Klasa opisujaca podstawowa komorke gry w raz z danymi o stanie drzwi, opisem komorki, parametrami gry i jej numerem.
* docelowo maskymalna automatyzacja czynnoœci zwi¹zanych z tworzeniem pomieszczenia/obszaru oraz mo¿liwoœc bezkolizyjnego dodawania nowych funkcji
*/
class qube
{
	std::string infoQ; //opis tekstowy boxa
	int hpQ; //obrazenia lub leczenie (hp+ hp-)
	int timeQ; //zmienna rund zabieranych przez box
	int beInsideQ; //licznik ilosci pobytow w boxie
	bool exitQ[4]; //tablica wyjsc | 0-W | 1-D | 2-S | 3-A

public:

	qube();
	//inicjacja g³ówmna lokacji
	void qubeIni(int);
	//getters
	std::string getInfoQ();
	int getHpQ();
	int getTimeQ();
	int getBeInsideQ();
	bool getExitQ(int);
	//setters
	void setBeInsideQ(int);
	void setExitQ(int, bool);

	~qube();
};
