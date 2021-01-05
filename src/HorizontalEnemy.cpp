#pragma once
#include "HorizontalEnemy.h"
#include <SFML/Graphics.hpp>

HorizontalEnemy::HorizontalEnemy(sf::Texture picture, const int speed) :Enemy(picture, speed),  m_myLastDirection(KB_RIGHT)
{}

sf::Vector2f HorizontalEnemy::directionToGo()
{
	
	sf::Vector2f location = getLocation();

	int col, row; // x- col, y- row
	col = location.x/COMPARISON;
	row = location.y / COMPARISON;
	if (m_myLastDirection == KB_RIGHT)
	{
	//	if(checkIfCan(row, col + 1))
		return KB_RIGHT;
	//else
//		return KB_LEFT;
	//move(time);// , KB_RIGHT);
	}
	if (m_myLastDirection == KB_LEFT)
	{
		//	if(checkIfCan(row, col + 1))
		return 	KB_LEFT;
	//else
	//	return KB_RIGHT;

	//move(time)//, KB_Left);
	}

}

void HorizontalEnemy::move(const sf::Time& time)
{
	sf::Vector2f direction; //need caculate direction
	Enemy::moveLocation(direction,time);
}
