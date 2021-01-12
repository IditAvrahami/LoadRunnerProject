#pragma once
#include "Rod.h"


Rod::Rod(sf::Sprite picture) : m_rodPng(sf::Sprite(picture))
{}
void Rod::print(sf::RenderWindow& window)
{
//	std::cout << "rod class:  x:  " << m_rodPng.getPosition().x << "y: " << m_rodPng.getPosition().y << std::endl;
	window.draw(m_rodPng);
}

void  Rod::setLocation(const float y, const float x)
{
	m_rodPng.setPosition(sf::Vector2f(x * COMPARISON, y * COMPARISON));
}

sf::Vector2f Rod::getLocation() const
{
	return m_rodPng.getPosition();
}

bool Rod::checkCollision(const sf::FloatRect& floatRect) const
{
	return m_rodPng.getGlobalBounds().intersects(floatRect);
}

sf::FloatRect Rod::getGlobalBounds() const
{
	return m_rodPng.getGlobalBounds();
}

void Rod::handleCollision(Object& obj)
{
	if (&obj == this)
		return;
	obj.handleCollision(*this);
}

void Rod::handleCollision(Player& obj)
{
	obj.handleCollision(*this);
}

void Rod::handleCollision(Enemy& obj)
{
	obj.handleCollision(*this);
}
