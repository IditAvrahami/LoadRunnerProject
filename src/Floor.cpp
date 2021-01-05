#pragma once
#include "Floor.h"

Floor::Floor(sf::Texture picture) : m_floorPng(sf::Sprite(picture))
{}

void Floor::print(sf::RenderWindow& window)
{
	window.draw(m_floorPng);
}

void  Floor::setLocation(const int y, const int x)
{
	m_floorPng.setPosition((float)x, (float)y);
}