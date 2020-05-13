#pragma once
#include <string>
#include<vector>
enum hint { NOTHING, BLACK, WHITE };

class Level
{
	int numberOfFields;
	std::vector<std::string> solutionAttempt;
	hint* hints;
public:
	Level();
	~Level();
	int getNumberOfFields();
	std::vector<std::string>  getSolutionAttempt();
	hint * getHints();
	void setNumberOfFields(int number);
	void setSolutionAttempt(std::vector<std::string>  attempt);
};

