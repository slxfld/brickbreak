#include "Menu.h"
#include <iostream>

Menu::Menu(RessourceLoader &rl)
{
	std::cout << "<Menu> create\n";
	background.setTexture(rl.BACKGROUND_tex);
}

void Menu::input(sf::Event& event)
{

}

void Menu::draw(sf::RenderWindow &window)
{
	window.draw(background);
}

void Menu::update()
{

}