#pragma once
#include <SFML/Graphics.hpp>
#include "Enemy.h"


class HorizontalEnemy : public Enemy
{
public:
	HorizontalEnemy();
	virtual~HorizontalEnemy() = default;
	virtual void move();
private:
	int m_myLastDirection = KB_RIGHT;
};
