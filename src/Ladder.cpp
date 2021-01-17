#pragma once
#include "Ladder.h"


Ladder::Ladder(sf::Sprite picture) : m_ladderPng(sf::Sprite(picture))
{}

void Ladder:: print(sf::RenderWindow& window)
{
	window.draw(m_ladderPng);
}

void  Ladder::setLocation(const float y, const float x)
{
	m_ladderPng.setPosition(sf::Vector2f(x * COMPARISON, y * COMPARISON));
}

bool Ladder::checkCollision(const sf::FloatRect& floatRect) const
{
	return m_ladderPng.getGlobalBounds().intersects(floatRect);
}

sf::FloatRect Ladder::getGlobalBounds() const
{
	return m_ladderPng.getGlobalBounds();
}

void Ladder::handleCollision(Object& obj)
{
	if (&obj == this)
		return;
	obj.handleCollision(*this);
}

void Ladder::handleCollision(Player& gameObject)
{
}

void Ladder::handleCollision(Coin& gameObject)
{
}

void Ladder::handleCollision(Present& gameObject)
{
}

void Ladder::handleCollision(Enemy& gameObject)
{
}

void Ladder::handleCollision(Floor& gameObject)
{
}

void Ladder::handleCollision(Rod& gameObject)
{
}

void Ladder::handleCollision(Ladder& gameObject)
{
}

sf::Vector2f Ladder::getLocation() const
{
	return m_ladderPng.getPosition();
}
