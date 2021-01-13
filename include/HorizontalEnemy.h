#pragma once
#include <SFML/Graphics.hpp>
#include "Enemy.h"
#include "Utillities.h"


class HorizontalEnemy : public Enemy
{
public:
	HorizontalEnemy(sf::Sprite picture, const int speed);
	virtual~HorizontalEnemy() = default;
	sf::Vector2f directionToGo();
	virtual void move(const sf::Time& time)override;
private:
	sf::Vector2f m_myLastDirection;
};
