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

void eventQ::create()
{
}

void eventQ::info(char)
{
}

int eventQ::action(int)
{
	return 0;
}

eventQ::eventQ()
{
	int r = 3; //prawdopodobienstwo wystapienia eventu przyjaznego 1 = nigdy 2= 50% 3= 30%.....)
	typeE = (rand() % 3);  //losowanie rodzaju eventu
	if (typeE == 1) friendE = true; //ustawienie friendE na true gdy przyjaciel 
	else friendE = (rand() % r); //ustawienie friendE losowo dla innych przypadków (skalowane prawdopodobieñstwo przez zmianê parametru r przez brutalne podstawienie liczby losowej do zmiennej bool)
}

eventQ::~eventQ()
{
}