#pragma once
#include "HorizontalEnemy.h"
#include <SFML/Graphics.hpp>

HorizontalEnemy::HorizontalEnemy(sf::Sprite picture, const int speed) :Enemy(picture, speed),  m_myLastDirection(KB_RIGHT)
{}

sf::Vector2f HorizontalEnemy::directionToGo()
{
	Movment movment;
	int nextx = Enemy::getLocation().x / COMPARISON;
	int nexty = Enemy::getLocation().y / COMPARISON;

	if (Enemy::getDirection().x >= 0 &&
		((movment.isFloor(nexty + KB_DOWN.y + KB_RIGHT.y, nextx + KB_DOWN.x + KB_RIGHT.x)
			&& movment.isDisappear(nexty + KB_DOWN.y + KB_RIGHT.y, nextx + KB_DOWN.x + KB_RIGHT.x)) ||
			movment.isFloor(nexty + KB_DOWN.y + KB_RIGHT.y, nextx + KB_DOWN.x + KB_RIGHT.x) ||
			movment.isRod(nexty + KB_RIGHT.y, nextx + KB_RIGHT.x) ||
			movment.isLadder(nexty + KB_DOWN.y + KB_RIGHT.y, nextx + KB_DOWN.x + KB_RIGHT.x)))
	{
		m_myLastDirection = KB_RIGHT;
		return KB_RIGHT;
	}
	else if (//Enemy::getDirection().x <= 0 &&//m_myLastDirection == KB_LEFT &&
		(movment.isFloor(nexty + KB_DOWN.y + KB_LEFT.y, nextx + KB_DOWN.x + KB_LEFT.x)
			&& movment.isDisappear(nexty + KB_DOWN.y + KB_LEFT.y, nextx + KB_DOWN.x + KB_LEFT.x)) ||
		(movment.isFloor(nexty + KB_DOWN.y + KB_LEFT.y, nextx + KB_DOWN.x + KB_LEFT.x) ||
			movment.isRod(nexty + KB_LEFT.y, nextx + KB_LEFT.x) ||
			movment.isLadder(nexty + KB_DOWN.y + KB_LEFT.y, nextx + KB_DOWN.x + KB_LEFT.x)))
	{
		m_myLastDirection = KB_LEFT;
		return KB_LEFT;
	}
	return KB_STAY;

}

void HorizontalEnemy::move(const sf::Time& time)
{
	sf::Vector2f direction = directionToGo(); //need caculate direction
	Movment movment;
	int nextx = Enemy::getLocation().x / COMPARISON;
	int nexty = Enemy::getLocation().y / COMPARISON;
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