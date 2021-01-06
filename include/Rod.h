#pragma once
#include "StaticObject.h"
#include <SFML/Graphics.hpp>
#include "Utillities.h"
#include <iostream>
#include <ostream>

class Rod : public StaticObject
{
public:
	
	Rod(sf::Sprite picture);
	virtual ~Rod() = default;
	virtual void print(sf::RenderWindow & window);
	virtual void setLocation(const float y, const float x);

private:
	sf::Sprite m_rodPng;
};
