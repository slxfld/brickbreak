#ifndef _MENU_H_
#define _MENU_H_
#include <iostream>
#include "GameObject.hpp"
#include "RessourceLoader.hpp"
#include "State.hpp"
#pragma once
class Menu : public State
{
	public:
	sf::Sprite startButton;
	sf::Sprite scoreButton;
	sf::Sprite optionsButton;
	sf::Sprite exitButton;
	sf::Sprite selecter;

	int buttonTime[3];

	int buttonSelectIndex = 1;
	bool enterGame = false;

	Menu(RessourceLoader *rl);

	void input(sf::Event& event, sf::RenderWindow &window);
	void pressButton(int index);
	void update();
	void draw(sf::RenderWindow& window);
	void setupButtons(RessourceLoader *rl);
};

#endif