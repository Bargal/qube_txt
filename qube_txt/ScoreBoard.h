#pragma once

/*
 * current it is actual game score.
 */
class score_board
{
	int score[10]{}; //table of top 10 game scores
	bool filestatus; //file read status

public:
	score_board();
	~score_board();
	//show score board on screen and add on end of score table
	void showScoreBoard(int);
};
