#pragma once
#include <SFML/Graphics.hpp>
#include "StaticObject.h"
#include "Utillities.h"
#include <iostream>
#include <ostream>
#include "Enemy.h"
#include "Player.h"

class Coin;
class Present;
class Rod;
class Floor;

class Ladder : public StaticObject
{
public:

	Ladder(sf::Sprite picture);
	virtual ~ Ladder()=default ;
	virtual void print(sf::RenderWindow& window);
	virtual void setLocation(const float y, const float x);

    virtual void handleCollision(Object& obj)override;
    virtual void handleCollision(Player& gameObject)override {};
    virtual void handleCollision(Coin& gameObject) override {};
    virtual void handleCollision(Present& gameObject) override {};
    virtual void handleCollision(Enemy& gameObject)override {};
    virtual void handleCollision(Floor& gameObject) override {};
    virtual void handleCollision(Rod& gameObject) override {};
    virtual void handleCollision(Ladder& gameObject)override {};

private:
	sf::Sprite m_ladderPng;
};
