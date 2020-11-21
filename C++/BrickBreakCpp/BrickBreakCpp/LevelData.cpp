#include "LevelData.h"
LevelData::LevelData()
{
	setDefault();
}

void LevelData::setDefault()
{
	lives = 3;
	score = 0;
	currentLevel = 1;
	combo = 0;
	combo_mult = 0;
	speed = 3;
}