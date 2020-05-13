#pragma once
#include<string>
#include"RankingEntry.h"
#include<vector>	
#include <fstream>

class OutputFile
{
public:
	OutputFile();
	~OutputFile();

	void saveRanking(std::string fileName, std::vector<RankingEntry> rankingList);

};
