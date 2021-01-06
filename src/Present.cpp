#pragma once
#include "Present.h"

Present::Present(sf::Texture picture) : m_presentPng(sf::Sprite(picture))
{}

void Present::print(sf::RenderWindow& window)
{
	window.draw(m_presentPng);
}

void Present::setLocation(const float y, const float x)
{
	m_presentPng.setPosition(sf::Vector2f(x * COMPARISON, y * COMPARISON));
}