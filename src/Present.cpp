#include "..\include\Present.h"
#include "..\include\Present.h"
#include "..\include\Present.h"
#include "..\include\Present.h"
#include "..\include\Present.h"
#pragma once
#include "Present.h"

Present::Present(sf::Sprite picture) : m_presentPng(sf::Sprite(picture))
{}

void Present::print(sf::RenderWindow& window)
{
	window.draw(m_presentPng);
}

void Present::setLocation(const float y, const float x)
{
	m_presentPng.setPosition(sf::Vector2f(x * COMPARISON, y * COMPARISON));
}

sf::Vector2f Present::getLocation() const
{
	return m_presentPng.getPosition();
}

bool Present::checkCollision(const sf::FloatRect& floatRect) const
{
	return m_presentPng.getGlobalBounds().intersects(floatRect);
}

sf::FloatRect Present::getGlobalBounds() const
{
	return m_presentPng.getGlobalBounds();
}

void Present::handleCollision(Object& obj)
{
	if (&obj == this)
		return;
	obj.handleCollision(*this);
}

void Present::handleCollision(Player& obj)
{
	// kind of present
	m_presentPng.setPosition(TO_DELETED);//delete coin and get into position -1 -1 to delete
	obj.handleCollision(*this); 
}
