#pragma once
#include "Coin.h"


Coin::Coin(sf::Sprite picture, const int level) : m_CoinPng(sf::Sprite(picture)) , m_value(level*2)
{}

void Coin::print(sf::RenderWindow& window)
{
	window.draw(m_CoinPng);
}

void Coin::setLocation(const float y, const float x)
{
	m_CoinPng.setPosition(sf::Vector2f(x * COMPARISON, y * COMPARISON));
}

int Coin::getValue()
{
	return m_value;
}

void Coin::handleCollision(Object& obj)
{
	if (&obj == this) 
		return;
	obj.handleCollision(*this);
}

void Coin::handleCollision(Player& obj)
{
	m_CoinPng.setPosition(TO_DELETED);//delete coin and get into position -1 -1 to delete
	//more score - in player
	obj.handleCollision(*this);
}

void Coin::handleCollision(Enemy& gameObject)
{
}

void Coin::handleCollision(Present& gameObject)
{
}

void Coin::handleCollision(Coin& gameObject)
{
}

void Coin::handleCollision(Floor& gameObject)
{
}

void Coin::handleCollision(Rod& gameObject)
{
}

void Coin::handleCollision(Ladder& gameObject)
{
}
