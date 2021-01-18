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

	if (Enemy::getDirection().x >= 0 &&//m_myLastDirection == KB_RIGHT && 
		(movment.isFloor(nexty + KB_DOWN.y + KB_RIGHT.y, nextx + KB_DOWN.x + KB_RIGHT.x) ||
			movment.isRod(nexty + KB_RIGHT.y, nextx + KB_RIGHT.x) ||
			movment.isLadder(nexty + KB_DOWN.y + KB_RIGHT.y, nextx + KB_DOWN.x + KB_RIGHT.x)))
	{
		m_myLastDirection = KB_RIGHT;
		return KB_RIGHT;
	}
	else
		if (//Enemy::getDirection().x <= 0 &&//m_myLastDirection == KB_LEFT &&
			(movment.isFloor(nexty + KB_DOWN.y + KB_LEFT.y, nextx + KB_DOWN.x + KB_LEFT.x) ||
				movment.isRod(nexty + KB_LEFT.y, nextx + KB_LEFT.x) ||
				movment.isLadder(nexty + KB_DOWN.y + KB_LEFT.y, nextx + KB_DOWN.x + KB_LEFT.x)))
		{
			m_myLastDirection = KB_LEFT;
			return KB_LEFT;
		}
	return KB_RIGHT;

}

void HorizontalEnemy::move(const sf::Time& time)
{
	sf::Vector2f direction = directionToGo(); //need caculate direction
	Enemy::moveLocation(direction,time);
}
