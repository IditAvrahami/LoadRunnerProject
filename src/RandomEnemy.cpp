#pragma once
#include "RandomEnemy.h"


RandomEnemy::RandomEnemy(sf::Sprite picture, const int speed) : Enemy(picture, speed)
{}

sf::Vector2f RandomEnemy::directionToGo()
{
	Movment movment;
	sf::Vector2f location = Enemy::getLocation();
	static int randomDirection = rand() % 4; // random number
	static int numberOfSteps = (rand() % 10) + 20;
	if (numberOfSteps == 0)
	{
		randomDirection = rand() % 4; // random number
		numberOfSteps = (rand() % 10) + 20;
	}
	else
		numberOfSteps--;

	location.x = (location.x / COMPARISON);
	location.y = (location.y / COMPARISON);

	switch (randomDirection)
	{
	case 0:
		if (movment.canUp((int)location.y, (int)location.x))
			return KB_UP;
	case 1:
		if (movment.canDown((int)location.y, (int)location.x))
			return KB_DOWN;
	case 2:
		if (movment.canRight((int)location.y, (int)location.x))
			return KB_RIGHT;
	case 3:
		if (movment.canLeft((int)location.y, (int)location.x))
			return KB_LEFT;
	}
	if (movment.canUp((int)location.y, (int)location.x))
		return KB_UP;
	if (movment.canDown((int)location.y, (int)location.x))
		return KB_DOWN;
	if (movment.canRight((int)location.y, (int)location.x))
		return KB_RIGHT;
	if (movment.canLeft((int)location.y, (int)location.x))
		return KB_LEFT;
	return sf::Vector2f(0, 0);
}

void RandomEnemy::move(const sf::Time& time)
{
	sf::Vector2f direction = directionToGo(); //need caculate direction
	Movment movment;
	int nextx = Enemy::getLocation().x / COMPARISON;
	int nexty = (Enemy::getLocation().y + 10) / COMPARISON;
	sf::Vector2f position = Enemy::getLocation();

	//check is fall to floor and fall
	if (direction == KB_RIGHT && (movment.isFloor(nexty + KB_DOWN.y + KB_RIGHT.y, nextx + KB_DOWN.x + KB_RIGHT.x)
		&& movment.isDisappear(nexty + KB_DOWN.y + KB_RIGHT.y, nextx + KB_DOWN.x + KB_RIGHT.x)))
	{
		direction = KB_STAY;
		position = Enemy::getLocation();
		Enemy::setLocation(nexty + KB_DOWN.y + KB_RIGHT.y, nextx + KB_DOWN.x + KB_RIGHT.x);
	}
	else if (direction == KB_LEFT && (movment.isFloor(nexty + KB_DOWN.y + KB_LEFT.y, nextx + KB_DOWN.x + KB_LEFT.x)
		&& movment.isDisappear(nexty + KB_DOWN.y + KB_LEFT.y, nextx + KB_DOWN.x + KB_LEFT.x)))
	{
		direction = KB_STAY;
		position = Enemy::getLocation();
		Enemy::setLocation(nexty + KB_DOWN.y + KB_LEFT.y, nextx + KB_DOWN.x + KB_LEFT.x);
	}
	Enemy::moveLocation(direction, time);
}
