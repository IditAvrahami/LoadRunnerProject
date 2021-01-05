#pragma once
#include "Enemy.h"


class SmartEnemy : public Enemy
{
public:
	SmartEnemy();
	virtual ~SmartEnemy() = default;
	virtual void move();
};
