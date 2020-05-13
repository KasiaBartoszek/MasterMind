#include "Level.h"

Level::Level()
{
	numberOfFields = 4;
	hints = new hint[numberOfFields];
	for (int i = 0; i < numberOfFields; i++) {
		hints[i] = NOTHING;
	}
}


Level::~Level()
{

	delete[] hints;
}

int Level::getNumberOfFields()
{
	return numberOfFields;
}

std::vector<std::string>  Level::getSolutionAttempt()
{
	return solutionAttempt;
}

hint * Level::getHints()
{
	return hints;
}

void Level::setNumberOfFields(int number)
{
	numberOfFields = number;
}

void Level::setSolutionAttempt(std::vector<std::string>  attempt)
{
	this->solutionAttempt = attempt;
}
