#pragma once
#include <SFML/Graphics.hpp>
#include "StaticObject.h"


class Coin : public StaticObject
{
public:
	Coin(sf::Texture picture);
	virtual ~Coin()=default;
	void setCoin();
	int coinValue();
	virtual void print(sf::RenderWindow& window);
	//virtual sf::Sprite getSprite();
	virtual void setLocation(const int y, const int x);

private:
	sf::Sprite m_CoinPng;
};
