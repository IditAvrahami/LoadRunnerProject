#pragma once
#include "StaticObject.h"
#include <SFML/Graphics.hpp>
#include "Utillities.h"
#include <iostream>
#include <ostream>
#include "Player.h"
#include "Enemy.h"

class Coin;
class Present;
class Floor;
class Rod;
class Ladder;

class Rod : public StaticObject
{
public:
	
	Rod(sf::Sprite picture);
	virtual ~Rod() = default;
	virtual void print(sf::RenderWindow & window);
	virtual void setLocation(const float y, const float x);

	virtual void handleCollision(Object& obj)override;
	virtual void handleCollision(Player& gameObject)override; // change angel?
	virtual void handleCollision(Enemy& gameObject) override;// change angel?
	virtual void handleCollision(Present& gameObject) override {};
	virtual void handleCollision(Coin& gameObject)override {};
	virtual void handleCollision(Floor& gameObject) override {};
	virtual void handleCollision(Rod& gameObject) override {};
	virtual void handleCollision(Ladder& gameObject)override {};


private:
	sf::Sprite m_rodPng;
};
