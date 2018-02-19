#include "stdafx.h"
#include "eventQ.h"
#include <iostream>

bool eventQ::getKey() { return keyE; }
int eventQ::getEventType() { return typeE; }

void eventQ::createChest()
{
}

void eventQ::createMob()
{
}

void eventQ::info(char)  //at this moment for test use only
{
	std::cout << "W tym pokoju ";
	if (typeE == 0)  std::cout << "znajduje sie przeciwnik " << std::endl;
	else if (typeE == 1)  std::cout << "znajduje sie przyjaciel " << std::endl;
	else if (typeE == 2)  std::cout << "znajduje sie skrzynia " << std::endl;
	else if (typeE == 3)  std::cout << "jest pusto " << std::endl;
	else if (typeE == 4)  std::cout << "ju¿ wszystko zrobi³eœ " << std::endl;
}

int eventQ::action(int)
{
	return 0;
}

eventQ::eventQ(int event) : hpE(0), strE(0), chestHpE(0), keyE(false)
{
	if (event == -1)
	{
		const int r = 3; //probability of a friendly event 1 = never 2 = 50% 3 = 30% .....)
		typeE = (rand() % 3); // drawing of the event type
		if (typeE == 1) friendE = true; //friendE setting to true when a friend
		else friendE = (rand() % r);
		//friendE setting randomly for other cases (scaled probability by changing the r parameter by brutally substituting the random number with the bool variable)
	}
	else typeE = event;
}

eventQ::eventQ(int event, const int r) : hpE(0), strE(0), chestHpE(0), keyE(false)
{
	//identical to the static constructor with the addition of the "difficulties" selection
	if (event == -1)
	{
		typeE = (rand() % 3);
		if (typeE == 1) friendE = true;
		else friendE = (rand() % r);
	}
	else typeE = event;
}

eventQ::~eventQ()
= default;