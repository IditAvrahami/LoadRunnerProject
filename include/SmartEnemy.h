#pragma once
#include "Enemy.h"
#include <SFML/Graphics.hpp>
#include "Utillities.h"

class SmartEnemy : public Enemy
{
public:
	SmartEnemy(sf::Sprite picture, const int speed);
	virtual ~SmartEnemy() = default;
//	virtual void enemyAlgorithem();
	std::vector<sf::Vector2f> directionToGo();
	virtual void move(const sf::Time& time)override;
	sf::Vector2f nextMove(const std::vector<sf::Vector2f> &direction)const;
};
