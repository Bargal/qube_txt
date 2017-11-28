// Qube - prosta gra tekstowa.
#include "stdafx.h"
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <conio.h>
#include "qube.h"
#include "comm_txt.h"
#include "initialize.h"

struct gdata				//struktura zmiennych gry
{
	int timer;		//deklaracja ilosci rund
	int hp;			//zdrowie gracza
	int mov;		//ilosc skończonych rund
	int startX;		//pozycja startowa
	int startY;		//pozycja startowa
	int endX;		//wyjscie
	int endY;		//wyjscie
	int endgame;	//znacznik końca gry
	bool hardMode;	//tryb gry poczatkujacy/ekspert
	int moveI;		//oznacznik ruchu
	int x;			//aktualna współrzędna x
	int y;			//aktualna współrzędna Y
};

// prototypy funkcji

//glowny modul gry
int	mainGame(gdata *p_allData, qube **p_p_matrix);

//analiza ruchu
int	move(gdata *p_allData, qube **p_p_matrix);

//opis pomieszczenia po wejscu
void opisQ(gdata *p_allData, qube **p_p_matrix);

//blok poruszania sie
int	menuQ(gdata *p_allData, qube **p_p_matrix);

//rozliczenie końcowe gry
int	gameOver(gdata *p_allData, qube **p_p_matrix);

int main()
{
	srand(time(NULL));
	int xM = 10;			// deklaracja rozmiaru gry
	int yM = xM;			// deklaracja rozmiaru gry
	int end = 0; // !=0 - koniec petli pomocniczej

	do		//petla pomocnicza
	{
		qube **p_p_matrix = new qube*[xM];		//tblica struktur boxow wraz z inicjacja
		for (int i = 0; i < yM; i++)
		{
			p_p_matrix[i] = new qube[yM];
		}
		gdata *p_allData = new gdata;	// struktura danych głównych

		p_allData->mov = 0;				//ilosc skończonych rund
		int rndX = (xM / 3);
		int rndY = (yM / 3);

		p_allData->startX = (std::rand() % rndX);				//pozycja startowa
		p_allData->startY = (std::rand() % rndY);				//pozycja startowa
		p_allData->endX = (std::rand() % rndX) + (rndX * 2);	//wyjscie
		p_allData->endY = (std::rand() % rndY) + (rndY * 2);	//wyjscie
		p_allData->endgame = 0;									//znacznik końca gry

		txtMain();						//wyswietlanie tekstu powitalnego

		int tmp;
		do
		{
			tmp = 0;
			char tempMode;
			tempMode = _getch();
			if (tempMode == '1')p_allData->hardMode = false;
			else if (tempMode == '2')p_allData->hardMode = true;
			else tmp = 1;
		} while (tmp == 1);

		hpTimeInit(p_allData);										  //inicjacja HP i Time
		defineQ(p_allData, p_p_matrix, xM, yM);							  //uzupełnianie danych
		if (p_allData->hardMode) hardmode(p_allData, p_p_matrix, xM, yM); //realizacja wysokiej trudnosci gry
		p_allData->endgame = mainGame(p_allData, p_p_matrix);			  //pętla główna gry
		end = gameOver(p_allData, p_p_matrix);							  //koniec gry
			 // czyszczenie pamieci na koniec rozgrywki lub koniec gry
		for (int i = 0; i < yM; i++)
		{
			delete[] p_p_matrix[i];
		}
		delete[] p_p_matrix;
		delete p_allData;
	} while (end == 0);
	return 0;
}

int mainGame(gdata *p_allData, qube **p_p_matrix)
{
	p_allData->x = p_allData->startX;
	p_allData->y = p_allData->startY;
	p_allData->endgame = 0;	//znacznik końca gry 0-gramy | 1-zdrowie | 2-ucieczka | 3-wygrana! | 4-koniec czasu
	int door = 5;			//znacznik pokonanych ostatnio drzwi (odwrotny wdsa) 5 - pierwsze wejscie
	p_allData->moveI = 9;		//oznaczenie wyboru gracza 0-w |1-d |2-s |3-a |4-a |5-rest |6- exit | 9 - wartosc startowa

	txtInside(p_p_matrix[p_allData->x][p_allData->y].infoQ, p_p_matrix[p_allData->endX][p_allData->endY].infoQ); //wyswietlanie tekstu wejsciowego na plansze

	_getch();

	do					//głowna pętla gry
	{
		system("cls");

		p_allData->hp += p_p_matrix[p_allData->x][p_allData->y].hpQ;  //zmiana HP gracza w nowym pokoju
		if (p_allData->hp <= 0) return 1;
		p_allData->mov += p_p_matrix[p_allData->x][p_allData->y].timeQ;  //zmiana rundy gracza w nowym pokoju
		if (p_allData->mov >= p_allData->timer) return 4;

		std::cout << "    HP  " << p_allData->hp << "   zakonczone rundy  " << p_allData->mov << "    Pozostalo czasu  " << p_allData->timer - p_allData->mov << std::endl << std::endl;

		opisQ(p_allData, p_p_matrix);
		p_allData->moveI = menuQ(p_allData, p_p_matrix);
		p_allData->endgame = move(p_allData, p_p_matrix);
	} while (p_allData->endgame == 0);

	return p_allData->endgame;
}

void opisQ(gdata *p_allData, qube **p_p_matrix)
{
	using std::cin;
	using std::cout;
	using std::endl;

	cout << "wchodzisz do pomieszczenia przez ";
	if (p_allData->moveI == 9) cout << "klape w podlodze " << endl;
	if (p_allData->moveI == 0) cout << "poludniowe drzwi " << endl;
	if (p_allData->moveI == 1) cout << "zachodnie drzwi " << endl;
	if (p_allData->moveI == 2) cout << "polnocne drzwi " << endl;
	if (p_allData->moveI == 3) cout << "wschodnie drzwi " << endl;

	if (p_allData->moveI == 0 && p_p_matrix[p_allData->x][p_allData->y].exitQ[2] == false) cout << "Drzwi za toba zatrzaskuja sie" << endl;
	if (p_allData->moveI == 1 && p_p_matrix[p_allData->x][p_allData->y].exitQ[3] == false) cout << "Drzwi za toba zatrzaskuja sie" << endl;
	if (p_allData->moveI == 2 && p_p_matrix[p_allData->x][p_allData->y].exitQ[0] == false) cout << "Drzwi za toba zatrzaskuja sie" << endl;
	if (p_allData->moveI == 3 && p_p_matrix[p_allData->x][p_allData->y].exitQ[1] == false) cout << "Drzwi za toba zatrzaskuja sie" << endl;

	cout << "\nw jednolicie bialym pokoju widzisz tylko na kazdej scianie napis \n\n    \"" << p_p_matrix[p_allData->x][p_allData->y].infoQ << "\"" << endl;
	cout << "\no ile pamietasz jestes w tym pokoju po raz " << p_p_matrix[p_allData->x][p_allData->y].beInsideQ << endl;
	p_p_matrix[p_allData->x][p_allData->y].beInsideQ++;     //dodanie liczby odwiedzin w pokoju
	cout << "\nwychodza z tad drzwi na ";
	if (p_p_matrix[p_allData->x][p_allData->y].exitQ[0]) cout << "polnoc ";
	if (p_p_matrix[p_allData->x][p_allData->y].exitQ[1]) cout << "wschod ";
	if (p_p_matrix[p_allData->x][p_allData->y].exitQ[2]) cout << "poludnie ";
	if (p_p_matrix[p_allData->x][p_allData->y].exitQ[3]) cout << "zachod ";
	if (p_allData->x == p_allData->startX && p_allData->y == p_allData->startY) cout << "\nw podloze widzisz klape przez ktora sie tu dostales" << endl;
	if (p_allData->x == p_allData->endX && p_allData->y == p_allData->endY)cout << "\n w podlodze widzisz nieznana klape, czyzby upragnione wyjscie??" << endl;
	graphQ(p_allData, p_p_matrix);
	cout << "\nJednoczesnie czujesz ze w pokoju panuje ";
	if (p_p_matrix[p_allData->x][p_allData->y].hpQ == 0) cout << "neutralna atmosfera " << endl;
	if (p_p_matrix[p_allData->x][p_allData->y].hpQ > 0) cout << "przyjazna atmosfera i orzymujesz " << p_p_matrix[p_allData->x][p_allData->y].hpQ << " HP" << endl;
	if (p_p_matrix[p_allData->x][p_allData->y].hpQ < 0) cout << "szkodliwa atmosfera i orzymujesz " << p_p_matrix[p_allData->x][p_allData->y].hpQ << " HP" << endl;
	cout << "\nPobyt w tym pokoju kosztuje " << p_p_matrix[p_allData->x][p_allData->y].timeQ << " rund" << endl;
}

int menuQ(gdata *p_allData, qube **p_p_matrix)
{
	std::cout << std::endl;
	std::cout << "nacisnij E zeby odpoczac w pokoju jedna runde;  R - zrezygnuj i wyjdz z \n" << std::endl;
	if (p_p_matrix[p_allData->x][p_allData->y].exitQ[0])  std::cout << "nacisnij W zeby isc na polnoc" << std::endl;
	if (p_p_matrix[p_allData->x][p_allData->y].exitQ[1])  std::cout << "nacisnij D zeby isc na wschod" << std::endl;
	if (p_p_matrix[p_allData->x][p_allData->y].exitQ[2])  std::cout << "nacisnij S zeby isc na poludie" << std::endl;
	if (p_p_matrix[p_allData->x][p_allData->y].exitQ[3])  std::cout << "nacisnij A zeby isc na zachod" << std::endl;
	if (p_allData->x == p_allData->endX && p_allData->y == p_allData->endY)  std::cout << "\n\a\a****** nacisnij Q zeby skorzystac z klapy w podlodze *****" << std::endl;

	int tst = 0;
	char moveC;						//znak z klawiatury
	p_allData->moveI = 9;			//oznaczenie wyboru gracza 0-w |1-d |2-s |3-a |4-a |5-rest |6- exit

	do
	{
		tst = 0;
		moveC = _getch();			//pobieranie znaku z klawiatury

		if ((moveC == 'w' || moveC == 'W') && p_p_matrix[p_allData->x][p_allData->y].exitQ[0]) p_allData->moveI = 0;
		else if ((moveC == 'd' || moveC == 'D') && p_p_matrix[p_allData->x][p_allData->y].exitQ[1]) p_allData->moveI = 1;
		else if ((moveC == 's' || moveC == 'S') && p_p_matrix[p_allData->x][p_allData->y].exitQ[2]) p_allData->moveI = 2;
		else if ((moveC == 'a' || moveC == 'A') && p_p_matrix[p_allData->x][p_allData->y].exitQ[3]) p_allData->moveI = 3;
		else if ((moveC == 'q' || moveC == 'Q') && (p_allData->x == p_allData->endX && p_allData->y == p_allData->endY)) p_allData->moveI = 4;
		else if (moveC == 'e' || moveC == 'E') p_allData->moveI = 5;
		else if (moveC == 'r' || moveC == 'R') p_allData->moveI = 6;
		else tst = 1;
	} while (tst == 1);
	return p_allData->moveI;
}

int move(gdata *p_allData, qube **p_p_matrix)
{
	switch (p_allData->moveI)
	{
	case 0: p_allData->x--; break;
	case 1: p_allData->y++; break;
	case 2: p_allData->x++; break;
	case 3: p_allData->y--; break;
	case 4: return 3;
	case 5: return 0;
	case 6: return 2;
	default: menuQ(p_allData, p_p_matrix);
	}
	return 0;
}

int gameOver(gdata *p_allData, qube **p_p_matrix)
{
	using std::cout;
	using std::endl;

	system("cls");
	cout << "    HP  " << p_allData->hp << "   zakonczone rundy  " << p_allData->mov << "    Pozostalo czasu  " << p_allData->timer - p_allData->mov << endl << endl;
	if (p_allData->endgame == 1) cout << "\nNiestety twoje zdrowie spadlo do zera... umarles :) ";
	if (p_allData->endgame == 2) cout << "\nUciekasz wyjsciem bezpieczenstwa przed zakonczeniem zadania.";
	if (p_allData->endgame == 4) cout << "\nNiestety koniec czasu - przegrales.";
	if (p_allData->endgame == 3)
	{
		cout << "\n\nGRATULACJE udalo ci sie wygrac !!!!";
		cout << "\nuzyskales " << p_allData->hp / 2 + (p_allData->timer - p_allData->mov) << " punktow" << endl;
	}
	cout << "\nKoniec gry nacisnij Q\nponowna gra nacisnij E" << endl;
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