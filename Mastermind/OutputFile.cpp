#include "OutputFile.h"



OutputFile::OutputFile()
{
}


OutputFile::~OutputFile()
{
}

void OutputFile::saveRanking(std::string fileName, std::vector<RankingEntry> rankingList)
{
	std::ofstream ofs(fileName);
	if (ofs.good())
	{
		for (auto it = rankingList.begin(); it != rankingList.end(); it++)
		{
			ofs << (*it).getName() << "," << (*it).getTime() << "," << (*it).getScore() << std::endl;
		}
	}
	ofs.close();
}
