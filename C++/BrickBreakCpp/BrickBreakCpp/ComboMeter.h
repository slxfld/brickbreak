#ifndef _GAMEOBJECT_H_
#define _GAMEOBJECT_H_
#include "GameObject.h"
#include "RessourceLoader.h"
#pragma once
class ComboMeter : public GameObject
{
	public:
	ComboMeter();
	ComboMeter(RessourceLoader &rl);
};
#endif
