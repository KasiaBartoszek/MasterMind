#pragma once
#include "InputFile.h"
#include "MastermindModel.h"
#include "Level.h"
#include <ctime>
#include "MastermindGraphics.h"

class MastermindController
{
public:
	MastermindController();
	~MastermindController();
	void runMastermind(std::string solutionFileName, std::string rankingFileName);
	std::vector<std::string>  tmpTestSolutionAttempt(int numberOfFields);
	MastermindGraphics window;
};
