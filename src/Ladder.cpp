#pragma once
#include "Ladder.h"

Ladder::Ladder(sf::Texture picture) : m_ladderPng(sf::Sprite (picture))
{}

void Ladder:: print(sf::RenderWindow& window)
{
	window.draw(m_ladderPng);
}

void  Ladder::setLocation(const int y, const int x)
{
	m_ladderPng.setPosition((float)x, (float)y);
}