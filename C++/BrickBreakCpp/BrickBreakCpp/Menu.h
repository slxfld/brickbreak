#include <iostream>
#include "GameObject.h"
#include "RessourceLoader.h"
#pragma once
class Menu : public GameObject
{
public:

	sf::Sprite background;

	Menu(RessourceLoader &rl);

	void input(sf::Event& event);
	void update();
	void draw(sf::RenderWindow &window);
};

