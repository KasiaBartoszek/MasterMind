#include <SFML/Graphics.hpp>
#include <Windows.h>
#include <iostream>
#include "InputFile.h"
#include "OutputFile.h"
#include "MastermindController.h"

int main()
{
	MastermindController mastermindController;
	mastermindController.runMastermind("kolory.txt", "ranking.txt");

	system("pause");
	return 0;
}