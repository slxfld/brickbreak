#ifndef _MENU_H_
#define _MENU_H_

#include <iostream>
#include "GameObject.h"
#include "RessourceLoader.h"
#pragma once
class Menu : public GameObject
{
	public:
	sf::Sprite background;
	sf::Sprite startButton;
	sf::Sprite scoreButton;
	sf::Sprite exitButton;

	int buttonSelectIndex = 1;

	Menu(RessourceLoader *rl);

	void input(sf::Event& event);
	void update();
	void draw(sf::RenderWindow &window);

	void setupButtons(RessourceLoader *rl);
};

#endif