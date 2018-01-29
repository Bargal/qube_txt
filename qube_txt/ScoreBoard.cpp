#include "stdafx.h"
#include "ScoreBoard.h"
#include <fstream>;
#include <string>;
#include <iostream>;

ScoreBoard::ScoreBoard() : current(0), rank(0), filestatus(true)
{
	std::ifstream scoreFile("score.dat");
	if (!scoreFile.is_open()) filestatus = false;
}

ScoreBoard::~ScoreBoard()
{
}