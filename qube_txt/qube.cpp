#include "stdafx.h"
#include "qube.h"

qube::qube() : hpQ(0), timeQ(0)
{
	beInsideQ = 1;
	exitQ[0] = true;
	exitQ[1] = true;
	exitQ[2] = true;
	exitQ[3] = true;
}

void qube::qubeIni(int p) //main initiation of the location
{
	infoQ = "pokoj numer  "; //room description
	infoQ += std::to_string(p);
	hpQ = (rand() % 5) - 2; //random determination of injuries or treatment in the +/- 2 range
	timeQ = (rand() % 4) + hpQ; // Then safer it is, then faster time goes
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