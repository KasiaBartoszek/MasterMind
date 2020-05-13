#pragma once
#include <fstream>
#include <vector>
#include <string>
#include <regex>
#include "WrongFileContentException.h"
#include "RankingEntry.h"
#include "FileNotFoundException.h"

class InputFile
{
public:
	InputFile();
	~InputFile();
	std::vector <std::string> readColors(std::string fileName);
	std::vector <RankingEntry> readRanking(std::string fileName);
};

