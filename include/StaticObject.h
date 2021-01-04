#pragma once
#include <SFML/Graphics.hpp>
#include "Object.h"

class StaticObject : public Object
{
public:
	StaticObject();
	virtual ~StaticObject() = default;
	virtual void print()=0;
	virtual void setLocation(const int row, const int col);

private:
//	sf::Texture m_blackPng;
};
