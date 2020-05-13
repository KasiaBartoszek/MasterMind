#include "MastermindGraphics.h"



MastermindGraphics::MastermindGraphics()
{
}


MastermindGraphics::~MastermindGraphics()
{
}

void MastermindGraphics::renderWindow()
{
	sf::RenderWindow window(sf::VideoMode(600, 700), "MasterMind");

	sf::RectangleShape rectangle(sf::Vector2f(300, 700));
	rectangle.setPosition(0, 0);
	rectangle.setFillColor(sf::Color::Blue);

	sf::RectangleShape rectangle1(sf::Vector2f(230, 100));
	rectangle1.setPosition(35, 10);
	rectangle1.setFillColor(sf::Color::Magenta);

	sf::RectangleShape rectangle2(sf::Vector2f(230, 100));
	rectangle2.setPosition(350, 390);
	rectangle2.setFillColor(sf::Color::Magenta);

	sf::CircleShape redCircle(20.f);
	redCircle.setPosition(370, 420);
	redCircle.setFillColor(sf::Color::Red);

	sf::CircleShape greenCircle(20.f);
	greenCircle.setPosition(420, 420);
	greenCircle.setFillColor(sf::Color::Green);

	sf::CircleShape blueCircle(20.f);
	blueCircle.setPosition(470, 420);
	blueCircle.setFillColor(sf::Color::Blue);

	sf::CircleShape yellowCircle(20.f);
	yellowCircle.setPosition(520, 420);
	yellowCircle.setFillColor(sf::Color::Yellow);

	sf::CircleShape whiteCircle(20.f);

	const sf::Vector2f yellowCirclePos = yellowCircle.getPosition();
	const sf::Vector2f redCirclePos = redCircle.getPosition();
	const sf::Vector2f blueCirclePos = blueCircle.getPosition();
	const sf::Vector2f greenCirclePos = greenCircle.getPosition();

	auto mousePositionFloat = static_cast<sf::Vector2f>(sf::Mouse::getPosition(window));
	std::vector<std::string> solutionAttempt;


	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(rectangle);
		window.draw(rectangle1);
		window.draw(rectangle2);
		window.draw(yellowCircle);
		window.draw(redCircle);
		window.draw(blueCircle);
		window.draw(greenCircle);
		
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				whiteCircle.setPosition(i * 70 + 25, j * 70 + 130);
				whiteCircle.setFillColor(sf::Color::White);
				window.draw(whiteCircle);
			}
		}

		window.display();

		sf::Event click;

		while (window.pollEvent(click))
		{
			if (click.type == sf::Event::MouseButtonPressed)
				for (int i = 0; i < 10; i++)
				{
					{
						if (blueCirclePos == mousePositionFloat)
						{
							solutionAttempt.push_back("b");
						}
						else if (yellowCirclePos == mousePositionFloat)
						{
							solutionAttempt.push_back("y");
						}
						else if (greenCirclePos == mousePositionFloat)
						{
							solutionAttempt.push_back("g");
						}
						else if (redCirclePos == mousePositionFloat)
						{
							solutionAttempt.push_back("r");
						}
					}
				}
		}
	}
}

/*std::vector<std::string> MastermindGraphics::TestSolutionAttempt(int numberOfFields, sf::RenderWindow window, const sf::Vector2f greenCirclePos, const sf::Vector2f redCirclePos, const sf::Vector2f blueCirclePos, const sf::Vector2f yellowCirclePos)
{
	sf::Event click;
	std::vector<std::string> solutionAttempt;

	auto mousePositionFloat = static_cast<sf::Vector2f>(sf::Mouse::getPosition(window));
	int j = 0;
	for (int i = 0; i < numberOfFields; i++)
	{
		if (click.type == sf::Event::MouseButtonPressed)
		{
			if (blueCirclePos == mousePositionFloat)
				solutionAttempt.push_back("b");
			else if (yellowCirclePos == mousePositionFloat)
				solutionAttempt.push_back("y");
			else if (greenCirclePos == mousePositionFloat)
				solutionAttempt.push_back("g");
			else if (redCirclePos == mousePositionFloat)
				solutionAttempt.push_back("r");
		}
	}

	return solutionAttempt;
}
*/