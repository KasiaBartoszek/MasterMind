#include "InputFile.h"



InputFile::InputFile()
{
}


InputFile::~InputFile()
{
}

std::vector <std::string> InputFile::readColors(std::string fileName)
{
	std::ifstream ifs(fileName);
	std::vector <std::string> colors;
	int numberOfColors = 4;

	if (ifs.good())
	{
		std::string line, color;
		getline(ifs, line);

		std::regex pattern("[\^,rgby]");
		if (regex_search(line, pattern))
		{
			throw WrongFileContentException();
		}

		std::string tmpStr = line;
		for (int i = 0; i < numberOfColors; i++)
		{
			int commaPosition = line.find(',');
			color = tmpStr.substr(0, commaPosition);
			colors.push_back(color);
			if (i != numberOfColors - 1) {
				tmpStr = tmpStr.substr(commaPosition + 1);
			}
		}

	}

	else
	{
		throw FileNotFoundException();
	}

	ifs.close();

	return colors;

}

std::vector<RankingEntry> InputFile::readRanking(std::string fileName)
{
	std::ifstream ifs(fileName);
	std::vector<RankingEntry> ranking;
	if (ifs.good())
	{
		const int numberOfColumns = 3;
		std::string line;
		getline(ifs, line);

		while (!(ifs.eof()))
		{
			std::string tmpStr = line;
			std::string tmpData[numberOfColumns];

			for (int i = 0; i < numberOfColumns; i++)
			{
				int commaPosition = tmpStr.find(',');
				tmpData[i] = tmpStr.substr(0, commaPosition);

				if (i != numberOfColumns - 1)
				{
					tmpStr = tmpStr.substr(commaPosition + 1);
				}
			}
			getline(ifs, line);

			RankingEntry ob(tmpData[0], std::atoi(tmpData[1].c_str()), std::atoi(tmpData[2].c_str()));
			ranking.push_back(ob);
		}
	}

	ifs.close();
	std::sort(ranking.begin(),ranking.end());
	return ranking;
}
