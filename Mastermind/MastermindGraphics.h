#pragma once
#include <SFML/Graphics.hpp>

class MastermindGraphics
{
public:
	MastermindGraphics();
	~MastermindGraphics();
	void renderWindow();
	std::vector <std::string> TestSolutionAttempt(int numberOfFields, sf::RenderWindow window, const sf::Vector2f greenCirclePos, const sf::Vector2f redCirclePos, const sf::Vector2f blueCirclePos, const sf::Vector2f yellowCirclePos);
};

