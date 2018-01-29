#include "stdafx.h"
#include "ScoreBoard.h"
#include <fstream>;
#include <string>;
#include <iostream>;

ScoreBoard::ScoreBoard() : filestatus(true)
{
	std::ifstream scoreFile("score.dat");
	if (!scoreFile.is_open()) filestatus = false;
	else
	{
		for (int i = 0; i < 10; i++)
			scoreFile >> score[i];

		//sorting table of scores
	}
}

ScoreBoard::~ScoreBoard()
{
	std::ofstream scoreFile("score.dat");
	if (!scoreFile.is_open()) filestatus = false;
	else
	{
		for (int i = 0; i < 10; i++)
			scoreFile << score[i];
	}
}

void ScoreBoard::showScoreBoard(const int current)
{
	int position = 1;
	for (int i = 0; i < 10; i++)
	{
		std::cout << "Miejsce " << i + 1 << " - " << score[i] << "  punkty" << std::endl;

		if (score[i] > current) position++;

		std::cout << "Twoj wynik " << current << " zapewnia ci " << position << " miejsce" << std::endl;

		score[9] = current;
	}
}