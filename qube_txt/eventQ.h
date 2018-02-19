#pragma once
/* event during the game.
* Create an enemy or crate that have some of the common features and part of their own
*/
class eventQ
{
	int typeE; //type of event 0-enemy 1-friend 2-box 3-empty room 4-event done
	int hpE; //endurance of the object
	int strE; //strength of the object (opponent)
	int chestHpE; //extra life (box)
	bool keyE; //does the object have a key?
	bool friendE; //if the object is friendly / open box (true) or hostile / closed

	//creating a box
	void createChest();
	//creating enemy/friend
	void createMob();

public:
	//getters
	bool getKey();
	int getEventType();

	//displays the text info about the event and accepts and displays the interaction key with the event
	void info(char);
	//performs actions related to the current event - to comprehend whether int or void and accepted arguments (maybe not necessary)
	int action(int);

	eventQ(int);
	eventQ(int, int); //determining the difficulty
	~eventQ();
};
