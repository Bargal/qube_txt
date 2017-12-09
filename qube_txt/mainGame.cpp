#include "stdafx.h"
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <conio.h>
#include "mainGame.h"

mainGame::mainGame(qube *p_p_q[], player p_A, int xM, int yM)
{
	xMain = xM;
	yMain = yM;
	qube **p_p_matrix = p_p_q;
	player* p_allData = &p_A;
}

mainGame::~mainGame()
{
	for (int i = 0; i < yMain; i++)
	{
		delete[] p_p_matrix[i];
	}
	delete[] p_p_matrix;
	delete p_allData;
}

int mainGame::startGame()
{
	return startGame(p_allData, p_p_matrix);
}

int mainGame::startGame(player* p_allData, qube** p_p_matrix)
{
	system("cls");
	std::cout << "Witam w qube txt" << std::endl;
	std::cout << "\nzaraz wejdziesz do losowego boxu " << std::endl;
	std::cout << "twoim zadaniem bedzie wydostanie sie na zewnatrz" << std::endl;
	std::cout << "w tym celu uzyj klawiszy WSAD :" << std::endl;
	std::cout << "\n W - polnoc\n E - poludnie\n A - zachod\n D - wschod" << std::endl;
	std::cout << "spokojnie - nie musisz tego zapamietac - bedzie to podawane podczas gry :)" << std::endl;
	std::cout <<
		"\nNa poczatek masz 10 punktow zycia.\nCzesc pokojow zadaje obrazena a odpoczynek w czesci pokojow leczy rany" << std
		::endl;
	std::cout << "odpoczywasz uzywajac klawisza Q" << std::endl;
	std::cout << "masz okreslona ilosc jednostek czasu a kazdy pokoj zabiera pewna ilosc czasu na ture" << std::endl;
	std::cout << "\nzycze milej zabawy, nacisnij dowolny klawisz aby zaczac." << std::endl;
	std::cout << "koncowy wynik zalezy od czasu przejscia i pozostalgo zdrowia" << std::endl;
	std::cout <<
		"\n\nwybierz trudnosc gry: 1 - latwa 2- trudna - uwaga, gra moze byc sporadycznie nie mozliwa do ukonczenia " << std::
		endl;

	int tmp;
	do
	{
		tmp = 0;
		char tempMode = _getch();
		if (tempMode == '1')p_allData->setHardMode(false);
		else if (tempMode == '2')p_allData->setHardMode(true);
		else tmp = 1;
	} while (tmp == 1);

	p_allData->hpTimeInit(); //inicjacja HP i Time
	defineQ(p_allData, p_p_matrix, xMain, yMain); //uzupe³nianie danych
	if (p_allData->getHardMode()) hardmode(p_allData, p_p_matrix, xMain, yMain); //realizacja wysokiej trudnosci gry
	p_allData->setEndgame(main(p_allData, p_p_matrix)); //pêtla g³ówna gry
	end = p_allData->gameOver(); //koniec gry
	return end; //powrót do main()
}

void mainGame::defineQ(player* p_allData, qube** p_p_matrix, int xM, int yM)
{
	int p = 1; //numerator nazwy pokoju

	for (int i = 0; i < xM; i++)
		for (int j = 0; j < yM; j++)
		{
			p_p_matrix[i][j].qubeIni(p); //inicjacja g³ówmna lokacji
			p++;
			//blokada drzwi zewnêtrznych
			if (i == 0) p_p_matrix[i][j].setExitQ(0, false); //dla blokady w
			if (j == (yM - 1)) p_p_matrix[i][j].setExitQ(1, false); //dla blokady d
			if (i == (xM - 1)) p_p_matrix[i][j].setExitQ(2, false); //dla blokady s
			if (j == 0) p_p_matrix[i][j].setExitQ(3, false); //dla blokady a
		}
	if (p_allData->getHardMode()) hardmode(p_allData, p_p_matrix, xM, yM);
}

void mainGame::hardmode(player* p_allData, qube** p_p_matrix, int xM, int yM)
//zamykamy jedne losowe drzwi w ka¿dym pokoju, poza pokojami skrajnymi
{
	for (int i = 1; i < (xM - 1); i++)
		for (int j = 1; j < (yM - 1); j++)
		{
			int tmp = (rand() % 4);
			p_p_matrix[i][j].setExitQ(tmp, false);
		}
}

int mainGame::main(player* p_allData, qube** p_p_matrix)
{
	p_allData->setEndgame(0);//znacznik koñca gry 0-gramy | 1-zdrowie | 2-ucieczka | 3-wygrana! | 4-koniec czasu |9-b³¹d wczytywania
	p_allData->setMoveP(9); //oznaczenie wyboru gracza 0-w |1-d |2-s |3-a |4-a |5-rest |6- exit | 9 - wartosc startowa

	system("cls");
	std::cout << "\n\n\n\nZaraz wejdziesz do gry!!!" << std::endl;
	std::cout << "\nzaczniesz w miejscu oznaczonym jako " << p_p_matrix[p_allData->getActX()][p_allData->getActY()].
		getInfoQ() << std::endl;
	std::cout << "wyjscie znajduje sie w pokoju oznaczonym jako " << p_p_matrix[p_allData->getEndX()][p_allData->getEndY()]
		.getInfoQ() << std::endl;
	std::cout << "\nzapamietaj to, bo od teraz podawany bedzie tylko numer pokoju w ktorym aktualnie jestes!" << std::endl;
	std::cout << "\n\nWspinasz sie po drabince do pomieszczenia od ktorego zaczniesz gre," << std::endl;
	std::cout << "celem jest dotrzec jak najszybciej do pomieszczenia z taka sama klapa w podlodze i wyjscie" << std::endl;
	std::cout << "\n\nNacisnij dowolny klawisz" << std::endl;
	_getch();

	//eventQ meet;   //inicjacja skrzynki/potwora
	do //g³owna pêtla gry
	{
		system("cls");
		int tempHp = p_allData->getHp();
		p_allData->setHp(tempHp += p_p_matrix[p_allData->getActX()][p_allData->getActY()].getHpQ());
		//zmiana HP gracza w nowym pokoju
		if (p_allData->getHp() <= 0) return 1;
		int tmpMov = p_allData->getMov();
		p_allData->setMov(tmpMov += p_p_matrix[p_allData->getActX()][p_allData->getActY()].getTimeQ());
		//zmiana rundy gracza w nowym pokoju
		if (p_allData->getMov() >= p_allData->getTimer()) return 4;

		std::cout << "    HP  " << p_allData->getHp()
			<< "   zakonczone rundy  " << p_allData->getMov()
			<< "    Pozostalo czasu  " << p_allData->getTimer() - p_allData->getMov() << std::endl << std::endl;

		opisQ(p_allData, p_p_matrix);
		p_allData->setMoveP(menuQ(p_allData, p_p_matrix));
		p_allData->setEndgame(p_allData->move());
	} while (p_allData->getEndgame() == 0);
	return p_allData->getEndgame();
}

void mainGame::opisQ(player* p_allData, qube** p_p_matrix)
{
	std::cout << "wchodzisz do pomieszczenia przez ";
	if (p_allData->getMoveP() == 9) std::cout << "klape w podlodze " << std::endl;
	if (p_allData->getMoveP() == 0) std::cout << "poludniowe drzwi " << std::endl;
	if (p_allData->getMoveP() == 1) std::cout << "zachodnie drzwi " << std::endl;
	if (p_allData->getMoveP() == 2) std::cout << "polnocne drzwi " << std::endl;
	if (p_allData->getMoveP() == 3) std::cout << "wschodnie drzwi " << std::endl;

	if (p_allData->getMoveP() == 0 && p_p_matrix[p_allData->getActX()][p_allData->getActY()].getExitQ(2) == false) std::
		cout << "Drzwi za toba zatrzaskuja sie" << std::endl;
	if (p_allData->getMoveP() == 1 && p_p_matrix[p_allData->getActX()][p_allData->getActY()].getExitQ(3) == false) std::
		cout << "Drzwi za toba zatrzaskuja sie" << std::endl;
	if (p_allData->getMoveP() == 2 && p_p_matrix[p_allData->getActX()][p_allData->getActY()].getExitQ(0) == false) std::
		cout << "Drzwi za toba zatrzaskuja sie" << std::endl;
	if (p_allData->getMoveP() == 3 && p_p_matrix[p_allData->getActX()][p_allData->getActY()].getExitQ(1) == false) std::
		cout << "Drzwi za toba zatrzaskuja sie" << std::endl;

	std::cout << "\nw jednolicie bialym pokoju widzisz tylko na kazdej scianie napis \n\n    \""
		<< p_p_matrix[p_allData->getActX()][p_allData->getActY()].getInfoQ() << "\"" << std::endl;
	std::cout << "\no ile pamietasz jestes w tym pokoju po raz " << p_p_matrix[p_allData->getActX()][p_allData->getActY()].
		getBeInsideQ();
	int tmpIn = p_p_matrix[p_allData->getActX()][p_allData->getActY()].getBeInsideQ(); //robocze beInside
	p_p_matrix[p_allData->getActX()][p_allData->getActY()].setBeInsideQ(++tmpIn); //dodanie liczby odwiedzin w pokoju
	std::cout << "\n\nwychodza z tad drzwi na ";
	if (p_p_matrix[p_allData->getActX()][p_allData->getActY()].getExitQ(0)) std::cout << "polnoc ";
	if (p_p_matrix[p_allData->getActX()][p_allData->getActY()].getExitQ(1)) std::cout << "wschod ";
	if (p_p_matrix[p_allData->getActX()][p_allData->getActY()].getExitQ(2)) std::cout << "poludnie ";
	if (p_p_matrix[p_allData->getActX()][p_allData->getActY()].getExitQ(3)) std::cout << "zachod ";
	if (p_allData->getActX() == p_allData->getStartX() && p_allData->getActY() == p_allData->getStartY())
		std::cout
		<< "\nw podloze widzisz klape przez ktora sie tu dostales" << std::endl;
	if (p_allData->getActX() == p_allData->getEndX() && p_allData->getActY() == p_allData->getEndY())
		std::cout
		<< "\n w podlodze widzisz nieznana klape, czyzby upragnione wyjscie??" << std::endl;
	std::cout << std::endl;
	//grafika tekstowa pokazujaca pokój wraz z stanem drzwi
	if (p_p_matrix[p_allData->getActX()][p_allData->getActY()].getExitQ(0)) std::cout << "  _|____*   *____|_  " << std::
		endl;
	else std::cout << "  _|____*___*____|_  " << std::endl;
	std::cout << "   |             |   " << std::endl;
	std::cout << "   |             |   " << std::endl;
	std::cout << "   *             *   " << std::endl;
	if ((p_p_matrix[p_allData->getActX()][p_allData->getActY()].getExitQ(1) && (p_p_matrix[p_allData->getActX()][p_allData
		->getActY()].getExitQ(3))))
		std::cout << "                     " << std::endl;
	if ((p_p_matrix[p_allData->getActX()][p_allData->getActY()].getExitQ(3)) && !(p_p_matrix[p_allData->getActX()][
		p_allData->getActY()].getExitQ(1)))
		std::cout << "                 |   " << std::endl;
		if ((p_p_matrix[p_allData->getActX()][p_allData->getActY()].getExitQ(1)) && !(p_p_matrix[p_allData->getActX()][
			p_allData->getActY()].getExitQ(3)))
			std::cout << "   |                 " << std::endl;
			if (!(p_p_matrix[p_allData->getActX()][p_allData->getActY()].getExitQ(1)) && !(p_p_matrix[p_allData->getActX()][
				p_allData->getActY()].getExitQ(3)))
				std::cout << "   |             |  " << std::endl;
				std::cout << "   *             *   " << std::endl;
				std::cout << "   |             |   " << std::endl;
				std::cout << "   |             |   " << std::endl;
				if (p_p_matrix[p_allData->getActX()][p_allData->getActY()].getExitQ(2)) std::cout << "  _|____     ____|_  " << std::
					endl;
				else std::cout << "  _|____ ___ ____|_  " << std::endl;
				std::cout << "   |    *   *    |   " << std::endl;
				//meet.create()  //stworzenie eventu (potwór lub skrzynka)
				//meet.info()   //opis wydarzeñ w pokoju
				std::cout << "\nJednoczesnie czujesz ze w pokoju panuje ";
				if (p_p_matrix[p_allData->getActX()][p_allData->getActY()].getHpQ() == 0) std::cout << "neutralna atmosfera " << std::
					endl;
				if (p_p_matrix[p_allData->getActX()][p_allData->getActY()].getHpQ() > 0)
					std::cout << "przyjazna atmosfera i orzymujesz "
					<< p_p_matrix[p_allData->getActX()][p_allData->getActY()].getHpQ() << " HP" << std::endl;
				if (p_p_matrix[p_allData->getActX()][p_allData->getActY()].getHpQ() < 0)
					std::cout << "szkodliwa atmosfera i orzymujesz "
					<< p_p_matrix[p_allData->getActX()][p_allData->getActY()].getHpQ() << " HP" << std::endl;
				std::cout << "\nPobyt w tym pokoju kosztuje " << p_p_matrix[p_allData->getActX()][p_allData->getActY()].getTimeQ() <<
					" rund" << std::endl;
				//meet.action() //wywo³anie kontrakcji z eventem
}

int mainGame::menuQ(player* p_allData, qube** p_p_matrix) //dodaæ u¿ycie klucza u¿yæ void meet.getKey()
{
	std::cout << std::endl;
	std::cout << "nacisnij E zeby odpoczac w pokoju jedna runde;  R - zrezygnuj i wyjdz z \n" << std::endl;
	if (p_p_matrix[p_allData->getActX()][p_allData->getActY()].getExitQ(0)) std::cout << "nacisnij W zeby isc na polnoc" <<
		std::endl;
	if (p_p_matrix[p_allData->getActX()][p_allData->getActY()].getExitQ(1)) std::cout << "nacisnij D zeby isc na wschod" <<
		std::endl;
	if (p_p_matrix[p_allData->getActX()][p_allData->getActY()].getExitQ(2)) std::cout << "nacisnij S zeby isc na poludie"
		<< std::endl;
	if (p_p_matrix[p_allData->getActX()][p_allData->getActY()].getExitQ(3)) std::cout << "nacisnij A zeby isc na zachod" <<
		std::endl;
	if (p_allData->getActX() == p_allData->getEndX() && p_allData->getActY() == p_allData->getEndY())
		std::cout
		<< "\n\a\a****** nacisnij Q zeby skorzystac z klapy w podlodze *****" << std::endl;

	int tst;
	p_allData->setMoveP(9); //oznaczenie wyboru gracza 0-w |1-d |2-s |3-a |4-a |5-rest |6- exit

	do
	{
		tst = 0;
		char moveC = _getch(); //pobieranie znaku z klawiatury

		if ((moveC == 'w' || moveC == 'W') && p_p_matrix[p_allData->getActX()][p_allData->getActY()].getExitQ(0)) p_allData->
			setMoveP(0);
		else if ((moveC == 'd' || moveC == 'D') && p_p_matrix[p_allData->getActX()][p_allData->getActY()].getExitQ(1))
			p_allData->setMoveP(1);
		else if ((moveC == 's' || moveC == 'S') && p_p_matrix[p_allData->getActX()][p_allData->getActY()].getExitQ(2))
			p_allData->setMoveP(2);
		else if ((moveC == 'a' || moveC == 'A') && p_p_matrix[p_allData->getActX()][p_allData->getActY()].getExitQ(3))
			p_allData->setMoveP(3);
		else if ((moveC == 'q' || moveC == 'Q') && (p_allData->getActX() == p_allData->getEndX() && p_allData->getActY() ==
			p_allData->getEndY())) p_allData->setMoveP(4);
		else if (moveC == 'e' || moveC == 'E') p_allData->setMoveP(5);
		else if (moveC == 'r' || moveC == 'R') p_allData->setMoveP(6);
		else tst = 1;
	} while (tst == 1);
	return p_allData->getMoveP();
}