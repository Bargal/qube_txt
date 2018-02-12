#pragma once
#include <string>

/*
* A class describing the basic game cell at once with data on the status of the door, description of the cell, game parameters and its number.
* the ultimate masking automation of activities related to the creation of a room / area and the possibility of collision-free adding new functions
*/
class qube
{
	std::string infoQ; //text description of the box
	int hpQ; //injury or treatment (hp + hp-)
	int timeQ; //variable of rounds picked up by the box
	int beInsideQ; //counter for the number of stays in the box
	bool exitQ[4]{}; //exit table | 0-W | 1-D | 2-S | 3-A

public:

	qube();
	//main initiation of the location
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
