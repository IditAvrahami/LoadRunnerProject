#pragma once
#include "Floor.h"


Floor::Floor(sf::Sprite picture) : m_floorPng(sf::Sprite(picture))
{}

void Floor::print(sf::RenderWindow& window)
{
	if(!m_makecolision)
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

void Floor::setSprite(sf::Sprite sprite)
{
	m_floorPng = sprite;
}

void Floor::disappear()
{
	m_makecolision = true;
	m_disappear.restart();
	m_position = m_floorPng.getPosition();
	m_floorPng.setPosition(TO_DELETED);
}

void Floor::appear(sf::Sprite sprite)
{
	sf::Time AITime = sf::milliseconds(300.0f);
	if (m_makecolision)
	{
		if (m_disappear.getElapsedTime().asMilliseconds() > AITime.asMilliseconds())
		{
			m_makecolision = false;
			setSprite(sprite);
			m_floorPng.setPosition(m_position);
		}
	}
}