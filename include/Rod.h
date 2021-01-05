#pragma once
#include "StaticObject.h"
#include <SFML/Graphics.hpp>

class Rod : public StaticObject
{
public:
	Rod(sf::Texture picture);
	virtual ~Rod() = default;
	virtual void print(sf::RenderWindow & window);
	//virtual sf::Sprite getSprite();
	virtual void setLocation(const int y, const int x);

private:
	sf::Sprite m_rodPng;
};
