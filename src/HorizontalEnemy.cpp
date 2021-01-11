#pragma once
#include "HorizontalEnemy.h"
#include <SFML/Graphics.hpp>

HorizontalEnemy::HorizontalEnemy(sf::Sprite picture, const int speed) :Enemy(picture, speed),  m_myLastDirection(KB_RIGHT)
{}

sf::Vector2f HorizontalEnemy::directionToGo()
{
	if (Enemy::getDirection().x < 0)
	{
		m_myLastDirection = KB_LEFT;
		return KB_LEFT;
	}
	else
		m_myLastDirection = KB_RIGHT;	
	return KB_RIGHT;


	/*
	sf::Vector2f location = getLocation();

	int col, row; // x- col, y- row
	col = (int)location.x/COMPARISON;
	row = (int)location.y / COMPARISON;
	*/

	/*	if (m_myLastDirection == KB_RIGHT )
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
	return KB_LEFT;
*/
}

void HorizontalEnemy::move(const sf::Time& time)
{
	sf::Vector2f direction = directionToGo(); //need caculate direction
	Enemy::moveLocation(direction,time);
}
