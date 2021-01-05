#pragma once
#include <SFML/Graphics.hpp>
#include "StaticObject.h"

class Ladder : public StaticObject
{
public:
	 Ladder (sf::Texture picture);
	virtual ~ Ladder()=default ;
	virtual void print(sf::RenderWindow& window);
	//virtual sf::Sprite getSprite();
	virtual void setLocation(const int y, const int x);

private:
	sf::Sprite m_ladderPng;
};
