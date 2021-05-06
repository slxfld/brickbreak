#include "SFML/Graphics.hpp"
#include "RessourceLoader.hpp"
#pragma once
class GameObject
{
	public:
	sf::Sprite sprite;
	RessourceLoader* rl;

	GameObject();

	virtual void setTexture(sf::Texture texture);
	virtual void draw(sf::RenderWindow& window);
	virtual void update();
};

