#pragma once
#include "SmartEnemy.h"

SmartEnemy::SmartEnemy(sf::Texture picture, const int speed) : Enemy(picture, speed)
{}

sf::Vector2f SmartEnemy::directionToGo()
{
	int randomDirection = rand() % 4; // random number

	switch (randomDirection)
	{
	case 0:
		//if(checkIfCan(KB_UP))
		return KB_UP;
		break;
	case 1:
		//if(checkIfCan(KB_UP))
		return KB_DOWN;
		break;
	case 2:
		//if(checkIfCan(KB_RIGHT))
		return KB_RIGHT;
		break;
	case 3:
		//if(checkIfCan(KB_LEFT))
		return KB_LEFT;
		break;
	}
	return sf::Vector2f(0, 0);
}
void SmartEnemy::move(const sf::Time& time)
{
	sf::Vector2f direction = directionToGo(); //need caculate direction
	Enemy::moveLocation(direction, time);
}