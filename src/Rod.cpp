#pragma once
#include "Rod.h"

Rod::Rod(sf::Texture picture) : m_rodPng(sf::Sprite(picture))
{}

void Rod::print(sf::RenderWindow& window)
{
	window.draw(m_rodPng);
}

void  Rod::setLocation(const int y, const int x)
{
	m_rodPng.setPosition((float)x, (float)y);
}