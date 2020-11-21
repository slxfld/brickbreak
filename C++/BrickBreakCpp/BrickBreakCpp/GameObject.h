#include "SFML/Graphics.hpp"
#include "RessourceLoader.h"
#pragma once
class GameObject
{
	public:
	sf::Sprite sprite;
	RessourceLoader* rl;

	GameObject();

	void setTexture(sf::Texture texture);

};

