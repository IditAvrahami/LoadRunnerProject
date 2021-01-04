#pragma once
#include <SFML/Graphics.hpp>
#include "Object.h"


class Coin : public Object
{
public:
	Coin();
	virtual ~Coin();
	void setCoin();
	int coinValue();
	virtual void print();
	virtual sf::Sprite getSprite();
	virtual void setLocation();

private:
	sf::Sprite m_coinPng;
};
