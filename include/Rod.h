#pragma once
#include "StaticObject.h"
#include <SFML/Graphics.hpp>

class Rod : public StaticObject
{
public:
	Rod();
	~Rod();
	virtual void print();
	virtual sf::Sprite getSprite();
	virtual void setLocation();

private:
	sf::Sprite m_rodPng;
};
