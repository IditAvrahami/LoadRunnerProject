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
	//sf::Vector2f vector;
	//vector.x = x * COMPARISON;
	//vector.y = y * COMPARISON;
	m_floorPng.setPosition(sf::Vector2f(x*COMPARISON, y*COMPARISON));
//	m_floorPng.setPosition(x * COMPARISON, y * COMPARISON);
	std::cout << "x: " << m_floorPng.getPosition().x << " y : " << m_floorPng.getPosition().y << std::endl;
}