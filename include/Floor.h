#pragma once
#include <SFML/Graphics.hpp>
#include "StaticObject.h"
#include "Utillities.h"
#include<SFML/Graphics/Sprite.hpp>
#include <iostream>
#include <ostream>

class Floor : public StaticObject
{
public:
	//Floor(sf::Texture picture);
	Floor(sf::Sprite picture);
	virtual ~Floor() = default;
	virtual void print(sf::RenderWindow & window);
	//virtual sf::Sprite getSprite();
	virtual void setLocation(const float y, const float x);

private:
	sf::Sprite m_floorPng;

};
