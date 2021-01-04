#pragma once
#include "Enemy.h"

void Enemy::setLocation(const int x, const int y)
{
	m_enemyPng.setPosition((float)x, (float)y);
}
