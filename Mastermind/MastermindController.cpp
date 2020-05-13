#include "MastermindController.h"



MastermindController::MastermindController()
{
}


MastermindController::~MastermindController()
{
}

void MastermindController::runMastermind(std::string solutionFileName, std::string rankingFileName)
{
	//window.renderWindow();
	InputFile input;
	int nubmerOfLevels = 10;
	std::vector <std::string> solution = input.readColors(solutionFileName);
	MastermindModel mastermindModel(nubmerOfLevels, solution);
	clock_t begin = clock();

	std::cout << "------------- MasterMind -------------" << std::endl << std::endl <<
		"Prosze wybrac dowolna kombinacje czterech kolorow sposrod: " << std::endl <<
		"<r> - red (czerwony)\n<g> - green (zielony)\n<b> - blue (niebieski)\n<y> - yellow (zolty)\n";

	for (int i = 0; i < mastermindModel.getNumberOfLevels(); i++)
	{
		std::cout << "\nProsze podac rozwiazanie: \n";
		std::vector<std::string>  attempt = tmpTestSolutionAttempt(4);
		mastermindModel.getLevels()[i].setSolutionAttempt(attempt);

		if (mastermindModel.checkAttempt(mastermindModel.getLevels()[i], solution))
		{
			clock_t end = clock();
			double time = double(end - begin) / CLOCKS_PER_SEC;
			double score = 200698 / time / ++i;
			mastermindModel.saveRecord(time, score);
			std::cout << "\nWygrana na poziomie: " << i << std::endl;
			for (int j = 0; j < solution.size(); j++) std::cout << mastermindModel.getLevels()[i].getHints()[j] << " ";
			break;
		}
	}
}

std::vector<std::string>  MastermindController::tmpTestSolutionAttempt(int numberOfFields)
{
	std::vector<std::string> solutionAttempt;
	for (int i = 0; i < numberOfFields; i++)
	{
		std::string tmp;
		std::cin >> tmp;
		solutionAttempt.push_back(tmp);
	}

	return solutionAttempt;
}
