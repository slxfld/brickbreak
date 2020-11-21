#include <SFML/Graphics.hpp>
#include "GameObject.h"
#include "RessourceLoader.h"
#pragma once
class Brick: public GameObject
{
public:
	Brick();
	Brick(int value, RessourceLoader& rl);
};

