
#include "LevelData.hpp"
LevelData::LevelData()
{
	setDefault();
	highscore = 0;
}

void LevelData::setDefault()
{
	lives = 3;
	score = 0;
	currentLevel = 0;
	gameover = false;
}