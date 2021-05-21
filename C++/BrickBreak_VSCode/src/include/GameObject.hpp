#include "SFML/Graphics.hpp"
#include "Access.hpp"
#pragma once
class GameObject
{
	public:
	sf::Sprite sprite;
	bool delete_me = false;

	GameObject();

	virtual void setTexture(sf::Texture texture);
	virtual void draw(sf::RenderWindow& window);
	virtual void update();
};

