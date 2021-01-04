#pragma once
#include "StaticObject.h"
#include <SFML/Graphics.hpp>

class Ladder : public StaticObject
{
public:
	 Ladder ();
	virtual ~ Ladder()=default ;
	virtual void print();
	virtual sf::Sprite getSprite();
	virtual void setLocation();

private:
	sf::Sprite m_ladderPng;
};