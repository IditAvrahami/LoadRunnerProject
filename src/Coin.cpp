#pragma once
#include "Coin.h"


Coin::Coin(sf::Sprite picture, const int level) : m_CoinPng(sf::Sprite(picture)) , m_value(level*2)
{}

void Coin::print(sf::RenderWindow& window)
{
	sf::Vector2f windowPosition, temp;
	temp.x = m_CoinPng.getPosition().x;
	temp.y = m_CoinPng.getPosition().y;
	windowPosition.x = m_CoinPng.getPosition().x - COMPARISON;
	windowPosition.y = m_CoinPng.getPosition().y - COMPARISON;
	m_CoinPng.setPosition(windowPosition);
	window.draw(m_CoinPng);
	m_CoinPng.setPosition(temp);
}

void Coin::setLocation(const float y, const float x)
{
	m_CoinPng.setPosition(sf::Vector2f(x * COMPARISON, y * COMPARISON));
}

int Coin::getValue()
{
	return m_value;
}

bool Coin::checkCollision(const sf::FloatRect& floatRect) const
{
	return m_CoinPng.getGlobalBounds().intersects(floatRect);
}

sf::FloatRect Coin::getGlobalBounds() const
{
	return m_CoinPng.getGlobalBounds();
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

sf::Vector2f Coin::getLocation() const
{
	return m_CoinPng.getPosition();
}
