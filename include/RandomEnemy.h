#pragma once
#include <SFML/Graphics.hpp>
#include "Enemy.h"
#include "Utillities.h"
#include "Movment.h"


class RandomEnemy : public Enemy
{
public:
	RandomEnemy(sf::Sprite picture, const int speed);
	virtual ~RandomEnemy() = default;
	sf::Vector2f directionToGo();
	virtual void move(const sf::Time& time)override;
};
