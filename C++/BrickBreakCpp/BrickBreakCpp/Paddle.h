#ifndef _PADDLE_H_
#define _PADDLE_H_

#include "GameObject.h"

#pragma once
class Paddle : public GameObject
{
	public:

	Paddle(RessourceLoader *rl);

	void draw();
	void update();
	void setDefault();
};
#endif