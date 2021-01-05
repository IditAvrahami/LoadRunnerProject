#pragma once
#include "Enemy.h"


class RandomEnemy : public Enemy
{
public:
	RandomEnemy();
	virtual ~RandomEnemy() = default;
	virtual void enemyAlgorithem();

};
