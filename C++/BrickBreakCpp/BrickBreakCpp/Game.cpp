#include "Game.h"

Game::Game(RessourceLoader* rl) : levelState(rl), menuState(rl)
{
	activeState.rl = rl;
	changeState(MENU);
}

void Game::input(sf::Event& event, sf::RenderWindow& window)
{
	if (state == LEVEL)
		levelState.input(event, window);
	if (state == MENU)
		menuState.input(event);
}

void Game::update()
{
	if (menuState.enterGame)
	{
		menuState.enterGame = false;
		state = LEVEL;
		levelState.selectSpeed = true;
		levelState.speedText.setPosition(sf::Vector2f(300, 400));
		levelState.speedText.setString("Select Speed: " + std::to_string(levelState.leveldata.speed));
		levelState.leveldata.setDefault();
	}
	if (levelState.leveldata.gameover == true) {
		state = MENU;
		levelState.running = false;
	}

	if (state == LEVEL)
		levelState.update();
	if (state == MENU)
		menuState.update();
}

void Game::draw(sf::RenderWindow& window)
{
	if (state == LEVEL)
		levelState.draw(window);
	if (state == MENU)
		menuState.draw(window);
}

void Game::changeState(GAME_STATE state)
{
	
}
