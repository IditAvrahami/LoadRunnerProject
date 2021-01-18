#pragma once
#include "Floor.h"


Floor::Floor(sf::Sprite picture) : m_floorPng(sf::Sprite(picture))
{}

void Floor::print(sf::RenderWindow& window)
{
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
	if (!m_makecolision)
		gameObject.handleCollision(*this);
}

void Floor::handleCollision(Enemy& gameObject)
{
	if (!m_makecolision)
		gameObject.handleCollision(*this);
}

sf::Vector2f Floor::getLocation() const
{
	return m_floorPng.getPosition();
}

void Floor::disappear()
{
	m_makecolision = true;
	m_disappear.restart();
}

void Floor::appear()
{
	if (m_makecolision)
		if (m_disappear.getElapsedTime().asSeconds() > 3)
			m_makecolision = false;
}
