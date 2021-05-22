#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include "Access.hpp"
#pragma once
class GameObject
{
	public:
	sf::Sprite sprite;
	sf::Sound sound;
	bool delete_me = false;

	GameObject();

	virtual void setTexture(sf::Texture texture);
	virtual void draw();
	virtual void update();
};

