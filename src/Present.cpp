#pragma once
#include "Present.h"
#include "Player.h"

Present::Present(sf::Sprite picture) : m_presentPng(sf::Sprite(picture))
{}

sf::Sprite Present::getSprite()
{
	return m_presentPng;
}

void Present::print(sf::RenderWindow& window)
{
	window.draw(m_presentPng);
}

void Present::setLocation(const float y, const float x)
{
	m_presentPng.setPosition(sf::Vector2f(x * COMPARISON, y * COMPARISON));
}

sf::Vector2f Present::getLocation() const
{
	return m_presentPng.getPosition();
}

sf::FloatRect Present::getGlobalBounds() const
{
	return m_presentPng.getGlobalBounds();
}
