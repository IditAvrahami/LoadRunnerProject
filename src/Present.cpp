#pragma once
#include "Present.h"

Present::Present(sf::Texture picture) : m_presentPng(sf::Sprite(picture))
{}

void Present::print(sf::RenderWindow& window)
{
	window.drew(m_presentPng);
}

void Present::setLocation(const int y, const int x)
{
	m_presentPng.setPosition((float)x, (float)y);
}