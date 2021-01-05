#pragma once
#include "Enemy.h"
#include <SFML/Graphics.hpp>
#include "Utillities.h"

class SmartEnemy : public Enemy
{
public:
	SmartEnemy(sf::Texture picture, const int speed);
	virtual ~SmartEnemy() = default;
//	virtual void enemyAlgorithem();
	sf::Vector2f directionToGo();
	virtual void move(const sf::Time& time);
};
