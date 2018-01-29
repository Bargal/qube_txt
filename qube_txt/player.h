#pragma once
/*
* a class describing the player's parameters and the current state of the game
* ultimately, the minimization of setters and getters and the introduction of more complex and comprehensive methods
* (withdrawal of part of the operation from the main program function)
*/
class Player
{
	int moveP;		//move marker
	int positionInOut[6];  //Start and end position table: 0-startX, 1-startY, 2-endX, 3-endY, 4 actX, 5 actY
	int timer;		//declaration of the number of rounds
	int hp;			//player health
	int mov;		//number of finite rounds
	int endgame;	//end of game marker
	bool hardMode;	//Beginner / expert game mode
	//setters private
	void setTimer(int);

public:
	//constructor (board size x, y)
	Player(int, int);
	//setting time and health depending on the difficulty of the game
	void hpTimeInit();
	//implementation of the player's movement
	int move();
	//end of the game
	int gameOver();

	// getters
	int getMoveP();
	int getStartX();
	int getStartY();
	int getEndX();
	int getEndY();
	int getActX();
	int getActY();
	int  getTimer();
	int  getHp();
	int  getMov();
	int  getEndgame();
	bool getHardMode();
	//setters
	void setMoveP(int);
	void setActY(int);
	void setActX(int);
	void setMov(int);
	void setHp(int);
	void setEndgame(int);
	void setHardMode(bool);

	~Player();
};
