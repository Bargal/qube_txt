#include "stdafx.h"
#include "eventQ.h"
#include <iostream>

bool eventQ::getKey() { return keyE; }

void eventQ::createChest()
{
}

void eventQ::createMob()
{
}

void eventQ::create(const int r)
{

}

void eventQ::info(char)
{

}

int eventQ::action(int)
{
	return 0;
}

eventQ::eventQ() : hpE(0), siE(0), chestHpE(0), keyE(false)
{
	const int r = 3; //probability of a friendly event 1 = never 2 = 50% 3 = 30% .....)
	typeE = (rand() % 3); // drawing of the event type
	if (typeE == 1) friendE = true; //friendE setting to true when a friend
	else friendE = (rand() % r);
	//friendE setting randomly for other cases (scaled probability by changing the r parameter by brutally substituting the random number with the bool variable)
}

eventQ::eventQ(const int r) : hpE(0), siE(0), chestHpE(0), keyE(false)
{
	//identical to the static constructor with the addition of the "difficulties" selection
	typeE = (rand() % 3);
	if (typeE == 1) friendE = true;
	else friendE = (rand() % r);
}

eventQ::~eventQ()
{
}