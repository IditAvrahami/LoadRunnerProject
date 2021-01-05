#pragma once
#include "HorizontalEnemy.h"
#include <SFML/Graphics.hpp>

HorizontalEnemy::HorizontalEnemy() : m_myLastDirection(KB_RIGHT)
{}

virtual void HorizontalEnemy::move()
{
	
	sf::Vector2f location = getLocation();
//	location = getLocation();

	if (m_myLastDirection == KB_RIGHT)
	{
		
	}
	if (m_myLastDirection == KB_LEFT)
	{

	}

}