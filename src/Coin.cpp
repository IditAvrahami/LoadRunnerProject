#pragma once
#include "coin.h"

Coin::Coin(sf::Texture picture) : m_coinPng(sf::Sprite(picture))
{}

void Coin::print(sf::RenderWindow& window)
{
	window.drew(m_enemyPng);
}

void Coin::setLocation(const int y, const int x)
{
	m_ladderPng.setPosition((float)x, (float)y);
}