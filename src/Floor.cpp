#pragma once
#include "Floor.h"


Floor::Floor(sf::Sprite picture) : m_floorPng(sf::Sprite(picture))
{}
void Floor::print(sf::RenderWindow& window)
{
//	std::cout << "floor class:  x:  " << m_floorPng.getPosition().x << "y: " << m_floorPng.getPosition().y << std::endl;
	window.draw(m_floorPng);
}

void  Floor::setLocation(const float y, const float x)
{
	m_floorPng.setPosition(sf::Vector2f(x*COMPARISON, y*COMPARISON));
}

bool Floor::checkCollision(const sf::FloatRect& floatRect) const
{
	return m_floorPng.getGlobalBounds().intersects(floatRect);
}

sf::FloatRect Floor::getGlobalBounds() const
{
	return m_floorPng.getGlobalBounds();
}

void Floor::handleCollision(Object& obj)
{
	if (&obj == this)
		return;
	obj.handleCollision(*this);
}

void Floor::handleCollision(Player& gameObject)
{
	gameObject.handleCollision(*this);
}

void Floor::handleCollision(Enemy& gameObject)
{
	gameObject.handleCollision(*this);
}

sf::Vector2f Floor::getLocation() const
{
	return m_floorPng.getPosition();
}
