#include "SFML/Graphics.hpp"
#pragma once
class GameObject
{
public:
	sf::Sprite sprite;

	GameObject();
	GameObject(sf::Texture texture);

	void setTexture(sf::Texture texture);
	virtual void update();
	virtual void draw();
};

