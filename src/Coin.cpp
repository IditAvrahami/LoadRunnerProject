#pragma once
#include "Coin.h"


Coin::Coin(sf::Sprite picture) : m_CoinPng(sf::Sprite(picture))
{}

void Coin::print(sf::RenderWindow& window)
{
	std::cout << "print the coin in x: " << m_CoinPng.getPosition().x << " y:" << m_CoinPng.getPosition().y << std::endl;
	window.draw(m_CoinPng);
}

void Coin::setLocation(const float y, const float x)
{
	m_CoinPng.setPosition(sf::Vector2f(x * COMPARISON, y * COMPARISON));
}