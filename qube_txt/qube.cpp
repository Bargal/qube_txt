#include "stdafx.h"
#include "qube.h"
#include <iostream>

Qube::Qube() : hpQ(0), timeQ(0)
{
	beInsideQ = 1;
	exitQ[0] = true;
	exitQ[1] = true;
	exitQ[2] = true;
	exitQ[3] = true;
}

void Qube::qubeIni(int p) //main initiation of the location
{
	infoQ = "pokoj numer  "; //room description -in future maybe from a file
	infoQ += std::to_string(p);
	hpQ = (rand() % 5) - 2; //random determination of injuries or treatment in the +/- 2 range
	timeQ = (rand() % 4) + hpQ; // The safer it is, the faster time goes
}

std::string Qube::getInfoQ() { return infoQ; }
int Qube::getHpQ() { return hpQ; }
int Qube::getTimeQ() { return timeQ; }
int Qube::getBeInsideQ() { return beInsideQ; }
bool Qube::getExitQ(int x) { return exitQ[x]; }

void Qube::setBeInsideQ(int x) { beInsideQ = x; }
void Qube::setExitQ(int x, bool a) { exitQ[x] = a; }

Qube::~Qube()
{
}