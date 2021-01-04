#pragma once
#include "Enemy.h"


class SmartEnemy : public Enemy
{
public:
	SmartEnemy();
	~SmartEnemy() = default;
	virtual void move();

};
