#pragma once
#include <SFML/Graphics.hpp>
#include "Enemy.h"
#include "Utillities.h"


class HorizontalEnemy : public Enemy
{
public:
	HorizontalEnemy();
	virtual~HorizontalEnemy() = default;
	virtual void move();
private:
	sf::Vector2f m_myLastDirection;
};
