#include "GameObject.h"
#include "RessourceLoader.h"
#pragma once
class Paddle : public GameObject
{
public:
	Paddle();
	Paddle(RessourceLoader &rl);
};

