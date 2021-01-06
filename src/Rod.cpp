#pragma once
#include "Rod.h"

Rod::Rod(sf::Texture picture) : m_rodPng(sf::Sprite(picture))
{}

void Rod::print(sf::RenderWindow& window)
{
	std::cout << "rod class:  x:  " << m_rodPng.getPosition().x << "y: " << m_rodPng.getPosition().y << std::endl;
	window.draw(m_rodPng);
}

void  Rod::setLocation(const float y, const float x)
{
	m_rodPng.setPosition(sf::Vector2f(x * COMPARISON, y * COMPARISON));
}