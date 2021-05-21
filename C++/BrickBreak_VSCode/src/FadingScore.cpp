#include "FadingScore.hpp"

FadingScore::FadingScore(sf::Vector2f position, int score)
{
	text.setFont(Access::rl->font);
	text.setString("+" + std::to_string(score));
	text.setPosition(position);

	velocity = 10;
}

void FadingScore::update()
{
	text.move(0,-velocity);
	text.setColor(sf::Color(255,255,255,velocity * 150.0));
	if (velocity > 0)  
		velocity-=0.5;
	else 
		delete_me = true;
}

void FadingScore::draw()
{
	if(velocity > 0) Access::window->draw(text);
}