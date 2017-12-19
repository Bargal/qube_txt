#pragma once
/* event during the game.
* Create an enemy or crate that have some of the common features and part of their own
* (learning how to classify and make friends)
*/
class eventQ
{
	int typeE; //type of event 0-enemy 1-friend 2-box
	int hpE; //endurance of the object
	int siE; //strength of the object (opponent)
	int chestHpE; //extra life (box)
	bool keyE; //does the object have a key?
	bool friendE; //if the object is friendly / open box (true) or hostile / closed

	//creating a box
	void createChest();
	//creating enemy/friend
	void createMob();

public:
	//getter of keyE variable
	bool getKey();
	//creates a new random event
	void create(int);
	//displays the text info about the event and accepts and displays the interaction key with the event
	void info(char);
	//performs actions related to the current event - to comprehend whether int or void and accepted arguments (maybe not necessary)
	int action(int);

	eventQ();
	eventQ(int); //determining the difficulty
	~eventQ();
};
