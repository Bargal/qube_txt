#include "stdafx.h"
#include <iostream>
#include <string>
#include "main.cpp"

void txtMain()
{
	system("cls");

	std::cout << "Witam w qube txt" << std::endl;
	std::cout << "\nzaraz wejdziesz do losowego boxu " << std::endl;
	std::cout << "twoim zadaniem bedzie wydostanie sie na zewnatrz" << std::endl;
	std::cout << "w tym celu uzyj klawiszy WSAD :" << std::endl;
	std::cout << "\n W - polnoc\n E - poludnie\n A - zachod\n D - wschod" << std::endl;
	std::cout << "spokojnie - nie musisz tego zapamietac - bedzie to podawane podczas gry :)" << std::endl;
	std::cout << "\nNa poczatek masz 10 punktow zycia.\nCzesc pokojow zadaje obrazena a odpoczynek w czesci pokojow leczy rany" << std::endl;
	std::cout << "odpoczywasz uzywajac klawisza Q" << std::endl;
	std::cout << "masz okreslona ilosc jednostek czasu a kazdy pokoj zabiera pewna ilosc czasu na ture" << std::endl;
	std::cout << "\nzycze milej zabawy, nacisnij dowolny klawisz aby zaczac." << std::endl;
	std::cout << "koncowy wynik zalezy od czasu przejscia i pozostalgo zdrowia" << std::endl;
	std::cout << "\n\nwybierz trudnosc gry: 1 - latwa 2- trudna - uwaga, gra moze byc sporadycznie nie mozliwa do ukonczenia " << std::endl;
}

void txtInside(std::string in, std::string out)
{
	system("cls");
	std::cout << "\n\n\n\nZaraz wejdziesz do gry!!!" << std::endl;
	std::cout << "\nzaczniesz w miejscu oznaczonym jako " << in << std::endl;
	std::cout << "wyjscie znajduje sie w pokoju oznaczonym jako " << out << std::endl;
	std::cout << "\nzapamietaj to, bo od teraz podawany bedzie tylko numer pokoju w ktorym aktualnie jestes!" << std::endl;
	std::cout << "\n\nWspinasz sie po drabince do pomieszczenia od ktorego zaczniesz gre,\ncelem jest dotrzec jak najszybciej do pomieszczenia z taka sama klapa w podlodze i wyjscie" << std::endl;
	std::cout << "\n\nNacisnij dowolny klawisz" << std::endl;
}

void graphQ(gdata *p_allData, qube **p_p_matrix)
{
	if (p_p_matrix[p_allData->x][p_allData->y].exitQ[0]) std::cout << "  _|____*   *____|_  " << std::endl;
	else std::cout << "  _|____*___*____|_  " << std::endl;
	std::cout << "   |             |   " << std::endl;
	std::cout << "   |             |   " << std::endl;
	std::cout << "   *             *   " << std::endl;
	if ((p_p_matrix[p_allData->x][p_allData->y].exitQ[1] && (p_p_matrix[p_allData->x][p_allData->y].exitQ[3]))) std::cout << "                     " << std::endl;
	else if (p_p_matrix[p_allData->x][p_allData->y].exitQ[3]) std::cout << "                 |   " << std::endl;
	else std::cout << "   |                 " << std::endl;
	std::cout << "   *             *   " << std::endl;
	std::cout << "   |             |   " << std::endl;
	std::cout << "   |             |   " << std::endl;
	if (p_p_matrix[p_allData->x][p_allData->y].exitQ[2]) std::cout << "  _|____     ____|_  " << std::endl;
	else std::cout << "  _|____ ___ ____|_  " << std::endl;
	std::cout << "   |    *   *    |   " << std::endl;

	//if (p_allData->x == p_allData->startX && p_allData->y == p_allData->startY) std::cout << "\nw podloze widzisz klape przez ktora sie tu dostales";
	//if (p_allData->x == p_allData->endX && p_allData->y == p_allData->endY) std::cout << "\n w podlodze widzisz nieznana klape, czyzby upragnione wyjscie??";
}