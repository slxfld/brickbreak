#include "SFML/Graphics.hpp"
#pragma once
class GameObject
{
public:
	sf::Sprite sprite;

	GameObject();

	void setTexture(sf::Texture texture);

};

