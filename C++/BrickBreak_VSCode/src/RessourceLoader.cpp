#include "RessourceLoader.hpp"

RessourceLoader::RessourceLoader()
{
	std::cout << "Ressource Loader init\n";
}

void RessourceLoader::load()
{
	const std::string path = "./png/";

	std::cout << "<Ressource Loader> Loading Files..\n";
	BRICK_1_G1_tex.loadFromFile(path + "brick01g1.png");
	BRICK_1_B1_tex.loadFromFile(path + "brick01b1.png");
	BRICK_1_GR1_tex.loadFromFile(path + "brick01gr1.png");
	BRICK_1_O1_tex.loadFromFile(path + "brick01o1.png");
	BRICK_1_R1_tex.loadFromFile(path + "brick01r1.png");
	BRICK_1_V1_tex.loadFromFile(path + "brick01v1.png");
	BRICK_1_Y1_tex.loadFromFile(path + "brick01y1.png");

	BUTTON_OPTIONS_tex.loadFromFile(path + "buttonOptions.png");
	BUTTON_EXIT_tex.loadFromFile(path + "buttonExit.png");
	BUTTON_START_tex.loadFromFile(path + "buttonStart.png");

	SELECT_tex.loadFromFile(path + "select.png");

	PAD_tex.loadFromFile(path + "pad2.png");
	BACKGROUND_tex.loadFromFile(path + "bg.png");
	BALL_tex.loadFromFile(path + "ball.png");
	LIFE_tex.loadFromFile(path + "life.png");

	font.loadFromFile("./data/EnterTheGrid2.ttf");

	BALL_SND.loadFromFile("./data/ball_snd.wav");
	UI_SND.loadFromFile("./data/ui_snd.wav");
	BUTTON_SND.loadFromFile("./data/button_snd.wav");
	BRICK_SND.loadFromFile("./data/brick_snd.wav");
	LEVEL_SND.loadFromFile("./data/next_level_snd.wav");
	GAMEOVER_SND.loadFromFile("./data/gameover_snd.wav");
	POWER_SND.loadFromFile("./data/power_snd.wav");
	LIFE_SND.loadFromFile("./data/life_snd.wav");

	std::cout << "<Ressource Loader> All Files Loaded!\n";
}