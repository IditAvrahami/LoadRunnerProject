#pragma once
#include "Enemy.h"


class RandomEnemy : public Enemy
{
public:
	RandomEnemy();
	~RandomEnemy() = default;
	virtual void move();

};
