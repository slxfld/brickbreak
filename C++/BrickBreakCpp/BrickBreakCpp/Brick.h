#include <SFML/Graphics.hpp>
#include "GameObject.h"

#pragma once
class Brick: public GameObject
{
public:
	Brick();
	Brick(sf::Texture texture);
};

