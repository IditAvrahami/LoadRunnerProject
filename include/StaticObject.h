#pragma once
#include <SFML/Graphics.hpp>
#include "Object.h"

class StaticObject : public Object
{
public:
	StaticObject();
	virtual ~StaticObject() = default;
	virtual void print()=0;
	virtual void setLocation(const int y, const int x);

private:
//	sf::Texture m_blackPng;
};
