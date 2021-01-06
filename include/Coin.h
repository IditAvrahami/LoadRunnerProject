#pragma once
#include <SFML/Graphics.hpp>
#include "StaticObject.h"
#include "Utillities.h"
#include <iostream>
#include <ostream>
class Coin : public StaticObject
{
public:

	Coin(sf::Sprite picture);
	virtual ~Coin()=default;
	virtual void print(sf::RenderWindow& window);
	virtual void setLocation(const float y, const float x);

private:
	sf::Sprite m_CoinPng;
};
