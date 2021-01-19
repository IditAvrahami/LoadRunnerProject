#pragma once
#include "BadPresent.h"
#include "Player.h"
#include "Enemy.h"
#include "Board.h"

BadPresent::BadPresent(sf::Sprite picture) : Present(picture)
{
}

bool BadPresent::checkCollision(const sf::FloatRect& floatRect) const
{
	return m_presentPng.getGlobalBounds().intersects(floatRect);
}


void BadPresent::handleCollision(Object& obj)
{
	if (&obj == this)
		return;
	obj.handleCollision(*this);
}

void BadPresent::handleCollision(Player& obj)
{
	int type = Board::boardObject().getTypeOfEnemy();
	std::unique_ptr <Enemy> newEnemy= Board::boardObject().kindOfEnemy(type);
	Board::boardObject().addEnemy();
	m_presentPng.setPosition(TO_DELETED);//delete coin and get into position -1 -1 to delete
	obj.handleCollision(*this);
}

void BadPresent::handleCollision(Enemy& gameObject)
{
}

void BadPresent::handleCollision(Present& gameObject)
{
}

void BadPresent::handleCollision(Coin& gameObject)
{
}

void BadPresent::handleCollision(Floor& gameObject)
{
}

void BadPresent::handleCollision(Rod& gameObject)
{
}

void BadPresent::handleCollision(Ladder& gameObject)
{
}

