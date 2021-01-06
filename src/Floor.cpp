#pragma once
#include "Floor.h"

Floor::Floor(sf::Texture picture) : m_floorPng(sf::Sprite(picture))
{}

void Floor::print(sf::RenderWindow& window)
{
	window.draw(m_floorPng);
}

void  Floor::setLocation(const float y, const float x)
{
	m_floorPng.setPosition(sf::Vector2f(x*COMPARISON, y*COMPARISON));
}