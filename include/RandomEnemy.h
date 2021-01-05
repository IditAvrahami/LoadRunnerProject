#pragma once
#include <SFML/Graphics.hpp>
#include "Enemy.h"
#include "Utillities.h"


class RandomEnemy : public Enemy
{
public:
	RandomEnemy(sf::Texture picture, const int speed);
	virtual ~RandomEnemy() = default;
	sf::Vector2f directionToGo();
	virtual void move(const sf::Time& time);
};
