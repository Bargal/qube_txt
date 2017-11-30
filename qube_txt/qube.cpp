#include "stdafx.h"
#include "qube.h"
#include <iostream>

qube::qube()
{
	beInsideQ = 1;
	exitQ[0] = true;
	exitQ[1] = true;
	exitQ[2] = true;
	exitQ[3] = true;
}

void qube::qubeIni(int p)						//inicjacja g³ówmna lokacji
{
	infoQ = "pokoj numer  ";					//opis pokoju - moze z pliku
	infoQ += std::to_string(p); p++;			//numer pokoju
	hpQ = (std::rand() % 5) - 2;				//losowe okreslenie obrazeñ lub leczenia w zakresie +/-2
	timeQ = (std::rand() % 4) + hpQ;			//Im bezpieczniej, tym czas szybciej idzie
}

std::string qube::getInfoQ() { return infoQ; }
int qube::getHpQ() { return hpQ; }
int qube::getTimeQ() { return timeQ; }
int qube::getBeInsideQ() { return beInsideQ; }
bool qube::getExitQ(int x) { return exitQ[x]; }

void qube::setBeInsideQ(int x) { beInsideQ = x; }
void qube::setExitQ(int x, bool a) { exitQ[x] = a; }

qube::~qube()
{
}