#pragma once
#include <SFML/Graphics.hpp>
#include "StaticObject.h"
#include "Utillities.h"

class Ladder : public StaticObject
{
public:
	 Ladder (sf::Texture picture);
	virtual ~ Ladder()=default ;
	virtual void print(sf::RenderWindow& window);
	//virtual sf::Sprite getSprite();
	virtual void setLocation(const float y, const float x);

private:
	sf::Sprite m_ladderPng;
};
