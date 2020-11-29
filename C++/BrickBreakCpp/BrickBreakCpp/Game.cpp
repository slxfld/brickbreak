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
	else if (state == MENU)
		menuState.input(event);
}

void Game::update()
{
	if (menuState.enterGame)
	{
		menuState.enterGame = false;
		changeState(LEVEL);
		levelState.selectSpeed = true;
		levelState.speedText.setPosition(sf::Vector2f(300, 400));
		levelState.speedText.setString("Select Speed: " + std::to_string(levelState.ball->speed));
		levelState.leveldata.setDefault();
	}
	if (levelState.leveldata.gameover == true) {
		changeState(MENU);
		levelState.isRunning = false;
	}

	if (state == LEVEL)
		levelState.update();
	else if (state == MENU)
		menuState.update();
}

void Game::draw(sf::RenderWindow& window)
{
	if (state == LEVEL)
		levelState.draw(window);
	else if (state == MENU)
		menuState.draw(window);
}

void Game::changeState(GAME_STATE state)
{
	Game::state = state;
}
