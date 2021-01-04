#pragma once
#include "Enemy.h"


class HorizontalEnemy : public Enemy
{
public:
	HorizontalEnemy();
	virtual~HorizontalEnemy() = default;
	virtual void move();

};
