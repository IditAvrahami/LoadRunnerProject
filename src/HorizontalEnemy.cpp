#pragma once
#include "HorizontalEnemy.h"
#include <SFML/Graphics.hpp>

HorizontalEnemy::HorizontalEnemy(sf::Sprite picture, const int speed) :Enemy(picture, speed),  m_myLastDirection(KB_RIGHT)
{}

sf::Vector2f HorizontalEnemy::directionToGo()
{
	
	Movment movment;
	sf::Vector2f direction = Enemy::getLocation();
	direction.x /= COMPARISON;
	direction.y /= COMPARISON;
	if (m_myLastDirection == KB_RIGHT && movment.isFloor(direction.y,direction.x))
	{
		std::cout << "in wall change to right" << std::endl;

		m_myLastDirection = KB_LEFT;
		return KB_LEFT;
	}
	if (m_myLastDirection == KB_LEFT && movment.isFloor(direction.y, direction.x))
	{
		std::cout << "in wall change to left" << std::endl;
		m_myLastDirection = KB_RIGHT;
		return KB_RIGHT;
	}
	if (Enemy::getDirection().x < 0)
	{
		m_myLastDirection = KB_LEFT;
		return KB_LEFT;
	}
	else
		m_myLastDirection = KB_RIGHT;
	return KB_RIGHT;
	
	/*
	Movment movment;
	sf::Vector2f direction;
	direction = Enemy::getLocation();


	direction.x = (direction.x/COMPARISON) + KB_LEFT.x;
	direction.y = (direction.y / COMPARISON) + KB_LEFT.y;

	if (movment.isFloor((int)direction.x, (int)direction.y + 1))
	{
		m_myLastDirection = KB_LEFT;
		return KB_LEFT;
	}
	else
		m_myLastDirection = KB_RIGHT;	
	return KB_RIGHT;

	*/
	/*
	sf::Vector2f location = getLocation();

	int x, y; // x- col, y- row
	x = (int)location.x/COMPARISON;
	y = (int)location.y / COMPARISON;
	Movment movment;

		if (m_myLastDirection == KB_RIGHT )
    	{
			//if (movment.canRight(col + KB_RIGHT.x, row + KB_RIGHT.y))
			if(movment.isLadder(y + KB_RIGHT.y, x + KB_RIGHT.x) || 
				movment.isRod(y + KB_RIGHT.y, x + KB_RIGHT.x) ||
				movment.isFloor(y + KB_RIGHT.x + KB_DOWN.x, x + KB_RIGHT.y + KB_DOWN.y) ||
				movment.isLadder(y + KB_RIGHT.x + KB_DOWN.x, x + KB_RIGHT.y + KB_DOWN.y))
			{
				m_myLastDirection = KB_RIGHT;
				return KB_RIGHT;
			}
			else
			{
				m_myLastDirection = KB_LEFT;
				return KB_LEFT;
			}
	//move(time);// , KB_RIGHT);
	 }
	if (m_myLastDirection == KB_LEFT)
	{
		//if (movment.canLeft(col + KB_LEFT.x, row + KB_LEFT.y))
		if(movment.isLadder(y + KB_LEFT.y, x + KB_LEFT.x) ||
			movment.isRod(y + KB_LEFT.y, x + KB_LEFT.x) ||
			movment.isFloor(y + KB_LEFT.y + KB_DOWN.y, x + KB_LEFT.x + KB_DOWN.x))
		{
			m_myLastDirection = KB_LEFT;
			return 	KB_LEFT;
		}
		else
		{
			m_myLastDirection = KB_RIGHT;
			return KB_RIGHT;
		}
	//move(time)//, KB_Left);
	}
	return KB_LEFT;
	*/
}

void HorizontalEnemy::move(const sf::Time& time)
{
	sf::Vector2f direction = directionToGo(); //need caculate direction
	Enemy::moveLocation(direction,time);
}
