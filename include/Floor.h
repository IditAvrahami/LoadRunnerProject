#pragma once
#include <SFML/Graphics.hpp>
#include "StaticObject.h"

class Floor : public StaticObject
{
public:
	Floor();
	virtual ~Floor()=default;
	virtual void print();
	virtual sf::Sprite getSprite();
	virtual void setLocation(const int y, const int x);

private:
	sf::Sprite m_floorPng;

};
