#pragme once
#include "LivePresent.h"
#include "Player.h"

LivePresent::LivePresent(sf::Sprite picture) : Present(picture)
{
}

bool LivePresent::checkCollision(const sf::FloatRect& floatRect) const
{
	return m_presentPng.getGlobalBounds().intersects(floatRect);
}


void LivePresent::handleCollision(Object& obj)
{
	if (&obj == this)
		return;
	obj.handleCollision(*this);
}

void LivePresent::handleCollision(Player& obj)
{
	obj.setLives(1); // more lives
	m_presentPng.setPosition(TO_DELETED);//delete coin and get into position -1 -1 to delete
	obj.handleCollision(*this);
}

void LivePresent::handleCollision(Enemy& gameObject)
{
}

void LivePresent::handleCollision(Present& gameObject)
{
}

void LivePresent::handleCollision(Coin& gameObject)
{
}

void LivePresent::handleCollision(Floor& gameObject)
{
}

void LivePresent::handleCollision(Rod& gameObject)
{
}

void LivePresent::handleCollision(Ladder& gameObject)
{
}

