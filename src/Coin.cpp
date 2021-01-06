#pragma once
#include "Coin.h"

Coin::Coin(sf::Texture picture) : m_CoinPng(sf::Sprite(picture))
{}

void Coin::print(sf::RenderWindow& window)
{
	window.draw(m_CoinPng);
}

void Coin::setLocation(const float y, const float x)
{
	m_CoinPng.setPosition(sf::Vector2f(x * COMPARISON, y * COMPARISON));
//	m_CoinPng.setPosition((float)x, (float)y);
}