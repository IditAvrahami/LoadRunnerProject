#pragma once
#include <SFML/Graphics.hpp>
#include "StaticObject.h"
#include "Utillities.h"
#include <iostream>
#include <ostream>
#include "Enemy.h"
#include "Player.h"

class Present;
class Floor;
class Rod;
class Ladder;

class Coin : public StaticObject
{
public:

	Coin(sf::Sprite picture, const int level);
	virtual ~Coin()=default;
	virtual void print(sf::RenderWindow& window);
	virtual void setLocation(const float y, const float x);
	int getValue();
	virtual void handleCollision(Object& obj)override;
	virtual void handleCollision(Player& gameObject)override;
	virtual void handleCollision(Enemy& gameObject) override;
	virtual void handleCollision(Present& gameObject) override;
	virtual void handleCollision(Coin& gameObject)override;
	virtual void handleCollision(Floor& gameObject) override;
	virtual void handleCollision(Rod& gameObject) override;
	virtual void handleCollision(Ladder& gameObject)override;

private:
	sf::Sprite m_CoinPng;
	int m_value;
};
