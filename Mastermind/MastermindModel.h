#pragma once
#include "Level.h"
#include <vector>
#include <string>
#include "RankingEntry.h"
#include "InputFile.h"
#include "MastermindGraphics.h"
#include "OutputFile.h"

class MastermindModel
{
	Level* levels;
	std::vector <std::string> solution;
	std::vector<RankingEntry> rankingList;
	int numberOfLevels;
	MastermindGraphics graphics;

public:
	MastermindModel();
	~MastermindModel();
	MastermindModel(int numberOfLevels, std::vector <std::string> solution);
	bool checkAttempt(Level&, std::vector <std::string> solution);
	void saveRecord(double time, double score);
	Level* getLevels();
	int getNumberOfLevels();
};

