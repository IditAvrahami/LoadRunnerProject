#pragma once
#include <SFML/Graphics.hpp>
#include "StaticObject.h"
#include "Utillities.h"

class Coin : public StaticObject
{
public:
	Coin(sf::Texture picture);
	virtual ~Coin()=default;
	void setCoin();
	int coinValue();
	virtual void print(sf::RenderWindow& window);
	//virtual sf::Sprite getSprite();
	virtual void setLocation(const float y, const float x);

private:
	sf::Sprite m_CoinPng;
};
