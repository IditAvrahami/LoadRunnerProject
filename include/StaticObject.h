#pragma once
#include <SFML/Graphics.hpp>
#include "Object.h"

class StaticObject : public Object
{
public:
	StaticObject()=default;
	virtual ~StaticObject() = default;
	//virtual void print()=0;
	virtual void print(sf::RenderWindow& window) = 0;
	virtual void setLocation(const int y, const int x)=0;

private:
//	sf::Texture m_blackPng;
};
