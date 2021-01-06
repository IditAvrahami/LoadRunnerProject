#pragma once
#include <SFML/Graphics.hpp>
#include "Object.h"
#include "Utillities.h"

class StaticObject : public Object
{
public:
	StaticObject()=default;
	virtual ~StaticObject() = default;
	//virtual void print()=0;
	virtual void print(sf::RenderWindow& window) = 0;
	virtual void setLocation(const float y, const float x)=0;

private:
//	sf::Texture m_blackPng;
};
