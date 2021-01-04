#pragma once
#include <SFML/Graphics.hpp>
#include "Object.h"


class Coin : public StaticObject
{
public:
	Coin();
	virtual ~Coin();
	void setCoin();
	int coinValue();
	virtual void print();
	virtual sf::Sprite getSprite();
	virtual void setLocation(const int y, const int x);

private:
	sf::Sprite m_coinPng;
};
