#pragma once
#include "RandomEnemy.h"


RandomEnemy::RandomEnemy(sf::Sprite picture, const int speed) : Enemy(picture, speed)
{}

sf::Vector2f RandomEnemy::directionToGo()
{
	Movment movment;
	sf::Vector2f location = Enemy::getLocation();
	int randomDirection = rand() % 4; // random number
	
	switch (randomDirection)
	{
	case 0:
		location.x = (location.x/COMPARISON) + KB_UP.x;
		location.y = (location.y / COMPARISON) + KB_UP.y;
		if(movment.canUp((int)location.x, (int)location.y))
		return KB_UP;
		break;
	case 1:
		location.x = (location.x / COMPARISON) + KB_DOWN.x;
		location.y = (location.y / COMPARISON) + KB_DOWN.y;
		if(movment.canDown((int)location.x, (int)location.y))
		return KB_DOWN;
		break;
	case 2:
		location.x = (location.x / COMPARISON) + KB_RIGHT.x;
		location.y = (location.y / COMPARISON) + KB_RIGHT.y;
		if(movment.canRight((int)location.x, (int)location.y))
		return KB_RIGHT;
		break;
	case 3:
		location.x = (location.x / COMPARISON) + KB_LEFT.x;
		location.y = (location.y / COMPARISON) + KB_LEFT.y;
		if(movment.canLeft((int)location.x, (int)location.y))
		return KB_LEFT;
		break;
	}
	return sf::Vector2f(0, 0);
}

void RandomEnemy::move(const sf::Time& time)
{
	sf::Vector2f direction = directionToGo(); //need caculate direction
	Enemy::moveLocation(direction, time);
}
