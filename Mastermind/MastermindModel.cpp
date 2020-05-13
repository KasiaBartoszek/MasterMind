#include "MastermindModel.h"



MastermindModel::MastermindModel()
{
}


MastermindModel::~MastermindModel()
{
}

MastermindModel::MastermindModel(int numberOfLevels, std::vector<std::string> solution) : numberOfLevels(numberOfLevels), solution(solution)
{
	this->levels = new Level[numberOfLevels];
	InputFile inputFile;
	this->rankingList = inputFile.readRanking("ranking.txt");
}

bool MastermindModel::checkAttempt(Level &level, std::vector<std::string> solution)
{
	std::cout << std::endl;
	bool tab[4]; // tab[0] = red, tab[1] = green, tab[2] = blue, tab[3] = yellow
	for (int i = 0; i < 4; i++)
		tab[i] = false;

	for (int i = 0; i < solution.size(); i++)
	{
		for (int j = 0; j < level.getNumberOfFields(); j++)
		{
			if (!std::strcmp(level.getSolutionAttempt().at(j).c_str(), solution.at(i).c_str()))
			{
				if (i == j)
				{
					level.getHints()[i] = BLACK;
					std::cout << "B - jeden z kolorow zgadza sie z rozwiazaniem i jest na dobrej pozycji\n";
				}
				else
				{
					if (!std::strcmp(level.getSolutionAttempt().at(j).c_str(), "r") && tab[0] == false)
					{
						level.getHints()[i] = WHITE;
						std::cout << "W - jeden z kolorow zgadza sie z rozwiazaniem, ale jest na zlej pozycji\n";
					}
					else if (!std::strcmp(level.getSolutionAttempt().at(j).c_str(), "g") && tab[1] == false)
					{
						level.getHints()[i] = WHITE;
						std::cout << "W - jeden z kolorow zgadza sie z rozwiazaniem, ale jest na zlej pozycji\n";
					}
					else if (!std::strcmp(level.getSolutionAttempt().at(j).c_str(), "b") && tab[2] == false)
					{
						level.getHints()[i] = WHITE;
						std::cout << "W - jeden z kolorow zgadza sie z rozwiazaniem, ale jest na zlej pozycji\n";
					}
					else if (!std::strcmp(level.getSolutionAttempt().at(j).c_str(), "y") && tab[3] == false)
					{
						level.getHints()[i] = WHITE;
						std::cout << "W - jeden z kolorow zgadza sie z rozwiazaniem, ale jest na zlej pozycji\n";
					}
				}

				if (!std::strcmp(level.getSolutionAttempt().at(j).c_str(), "r"))
					tab[0] = true;
				else if (!std::strcmp(level.getSolutionAttempt().at(j).c_str(), "g"))
					tab[1] = true;
				else if (!std::strcmp(level.getSolutionAttempt().at(j).c_str(), "b"))
					tab[2] = true;
				else if (!std::strcmp(level.getSolutionAttempt().at(j).c_str(), "y"))
					tab[3] = true;
			}
		}
	}

	for (int i = 0; i < level.getNumberOfFields(); i++)
	{
		if (level.getHints()[i] != BLACK)
		{
			return false;
		}
	}
	return true;
}

Level* MastermindModel::getLevels()
{
	return levels;
}

int MastermindModel::getNumberOfLevels()
{
	return numberOfLevels;
}


void MastermindModel::saveRecord(double time, double score)
{
	std::string name;
	RankingEntry newRecord("", time, score);
	if (newRecord.getScore() > rankingList.at(rankingList.size() - 1).getScore())
	{
		std::cout << "\nProsze podac imie: ";
		std::cin >> name;
		newRecord.setName(name);
		rankingList.push_back(newRecord);
		std::sort(rankingList.begin(), rankingList.end());
	}
	OutputFile ob1;
	ob1.saveRanking("ranking.txt", rankingList);
}