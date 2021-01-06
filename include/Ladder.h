#pragma once
#include <SFML/Graphics.hpp>
#include "StaticObject.h"
#include "Utillities.h"
#include <iostream>
#include <ostream>

class Ladder : public StaticObject
{
public:

	Ladder(sf::Sprite picture);
	virtual ~ Ladder()=default ;
	virtual void print(sf::RenderWindow& window);
	virtual void setLocation(const float y, const float x);

private:
	sf::Sprite m_ladderPng;
};
