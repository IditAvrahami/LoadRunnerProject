#pragma once
#include "Ladder.h"

Ladder::Ladder(sf::Texture picture) : m_ladderPng(sf::Sprite (picture))
{}

void Ladder:: print(sf::RenderWindow& window)
{
	window.draw(m_ladderPng);
}

void  Ladder::setLocation(const float y, const float x)
{
	m_ladderPng.setPosition(sf::Vector2f(x * COMPARISON, y * COMPARISON));
}