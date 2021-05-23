#include "Gameover.hpp"

GameOver::GameOver()
{    
    GameOverText.setColor(sf::Color(255,255,255,0));
    GameOverText.setFont(Access::rl->font);
    GameOverText.setString("GAME OVER");
    GameOverText.setPosition(230,200);

    highscoreText.setColor(sf::Color(255,255,255,0));
    highscoreText.setFont(Access::rl->font);
    highscoreText.setPosition(230,300);

    scoreText.setColor(sf::Color(255,255,255,0));
    scoreText.setFont(Access::rl->font);
    scoreText.setPosition(230,350);

    enterToContinueText.setColor(sf::Color(255,255,255,0));
    enterToContinueText.setFont(Access::rl->font);
    enterToContinueText.setString("Press Enter To Continue");
    enterToContinueText.setPosition(230,450);

    sound.setBuffer(Access::rl->GAMEOVER_SND);
}

void GameOver::update()
{
    if (alphaItemIndex < 5) alphaCounter+=5;
    if (alphaCounter > 240) {alphaItemIndex++; alphaCounter = 0;}

    switch(alphaItemIndex)
    {
        case 1: GameOverText.setColor(sf::Color(255,255,255,alphaCounter));     break;
        case 2: highscoreText.setColor(sf::Color(255,255,255,alphaCounter));    break;
        case 3: scoreText.setColor(sf::Color(255,255,255,alphaCounter));        break;
        case 4: enterToContinueText.setColor(sf::Color(255,255,255,alphaCounter));        break;
    }
}

void GameOver::draw()
{
    if (show)
    {
        Access::window->draw(GameOverText);
        Access::window->draw(highscoreText);
        Access::window->draw(scoreText);
        Access::window->draw(enterToContinueText);
    }
}

void GameOver::reset()
{
    show = false;
    alphaItemIndex = 0;
    alphaCounter = 0;

    GameOverText.setColor(sf::Color(255,255,255,0));
    highscoreText.setColor(sf::Color(255,255,255,0));
    scoreText.setColor(sf::Color(255,255,255,0));
    enterToContinueText.setColor(sf::Color(255,255,255,0));
}