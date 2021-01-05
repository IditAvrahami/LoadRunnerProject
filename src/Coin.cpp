#pragma once
#include "Coin.h"

Coin::Coin(sf::Texture picture) : m_coinPng(sf::Sprite(picture))
{}

void Coin::print(sf::RenderWindow& window)
{
	window.drew(m_CoinPng);
}

void Coin::setLocation(const int y, const int x)
{
	m_CoinPng.setPosition((float)x, (float)y);
}