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
	BRICK_1_GR1_tex.loadFromFile(path + "brick01b1.png");
	BRICK_1_O1_tex.loadFromFile(path + "brick01o1.png");
	BRICK_1_R1_tex.loadFromFile(path + "brick01r1.png");
	BRICK_1_V1_tex.loadFromFile(path + "brick01v1.png");
	BRICK_1_Y1_tex.loadFromFile(path + "brick01y1.png");

	BUTTON_DN_tex.loadFromFile(path + "buttondn.png");
	BUTTON_UP_tex.loadFromFile(path + "buttonup.png");

	BUTTON_PLAY_DN_tex.loadFromFile(path + "buttonPLAYdn.png");
	BUTTON_PLAY_UP_tex.loadFromFile(path + "buttonPLAYup.png");

	BUTTON_OPTIONS_DN_tex.loadFromFile(path + "buttonOPTIONSdn.png");
	BUTTON_OPTIONS_UP_tex.loadFromFile(path + "buttonOPTIONSup.png");

	BUTTON_EXIT_DN_tex.loadFromFile(path + "buttonEXITdn.png");
	BUTTON_EXIT_UP_tex.loadFromFile(path + "buttonEXITup.png");

	SELECT_tex.loadFromFile(path + "select.png");

	PAD_tex.loadFromFile(path + "pad2.png");
	BACKGROUND_tex.loadFromFile(path + "bg.png");
	BALL_tex.loadFromFile(path + "ball.png");
	LIFE_tex.loadFromFile(path + "life.png");

	font.loadFromFile("./data/EnterTheGrid2.ttf");

	std::cout << "<Ressource Loader> All Files Loaded!\n";
}