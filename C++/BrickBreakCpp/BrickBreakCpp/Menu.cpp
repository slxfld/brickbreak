#include "Menu.h"
#include <iostream>

Menu::Menu(RessourceLoader *rl)
{
	Menu::rl = rl;
	std::cout << "<Menu> create\n";
	setupButtons(rl);
}

void Menu::setupButtons(RessourceLoader *rl)
{
	startButton.setTexture(rl->BUTTON_UP_tex);
	startButton.setPosition(sf::Vector2f(50, 30));

	scoreButton.setTexture(rl->BUTTON_UP_tex);
	scoreButton.setPosition(sf::Vector2f(50, 150));

	exitButton.setTexture(rl->BUTTON_UP_tex);
	exitButton.setPosition(sf::Vector2f(50, 200));
}

void Menu::input(sf::Event& event)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		buttonSelectIndex = (buttonSelectIndex + 1 > 3) ? 1 : buttonSelectIndex + 1;
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		buttonSelectIndex = (buttonSelectIndex - 1 <= 0) ? 3 : buttonSelectIndex - 1;
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
		switch (buttonSelectIndex)
		{
			case 1: startButton.setTexture(rl->BUTTON_DN_tex); enterGame = true; break;
			case 2: scoreButton.setTexture(rl->BUTTON_DN_tex); break;
			case 3: exitButton.setTexture(rl->BUTTON_DN_tex); break;
		}
}

void Menu::draw(sf::RenderWindow &window)
{
	sf::RectangleShape rect(sf::Vector2f(10, 10));
	rect.setPosition(sf::Vector2f(20, 40 + (buttonSelectIndex * 20)));
	window.draw(rect);

	window.draw(startButton);
	window.draw(scoreButton);
	window.draw(exitButton);
}

void Menu::update()
{

}