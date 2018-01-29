#pragma once

/**
 * \brief
 */
class ScoreBoard
{
	int score[10]{ 0 };  //table of top 10 game scores
	int current; //the result of the current game
	int rank; //ranking of the current game
	bool filestatus; //file read status

public:
	ScoreBoard();
	~ScoreBoard();
};
