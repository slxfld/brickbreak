#include "Game.hpp"

Game::Game()
{
	changeState(MENU);
}

void Game::input(sf::Event& event)
{
	if (state == LEVEL)
		levelState.input(event);
	else if (state == MENU)
		menuState.input(event);
}

void Game::update()
{
	if (menuState.enterGame)
	{
		menuState.enterGame = false;
		levelState.gameover.reset();
		changeState(LEVEL);
		levelState.selectingSpeed = true;
		levelState.speedText.setPosition(sf::Vector2f(300, 400));
		levelState.speedText.setString("Select Speed: " + std::to_string(levelState.ball.speed));
		levelState.leveldata.setDefault();
	}
	if (levelState.leveldata.gameover == true) {
		changeState(MENU);
		levelState.isRunning = false;
	}
	
	switch(state)
	{
		case LEVEL:
			levelState.update();
		break;
		case MENU:
			menuState.update();
		break;
	}
}

void Game::draw()
{
	if (state == LEVEL)
		levelState.draw();
	else if (state == MENU)
		menuState.draw();
}

void Game::changeState(GAME_STATE state)
{
	Game::state = state;
}
