#pragma once
#include "ScorePresent.h"
#include "Player.h"
#include "Present.h"

ScorePresent::ScorePresent(sf::Sprite picture) :Present(picture)
{}

bool ScorePresent::checkCollision(const sf::FloatRect& floatRect) const
{
	return m_presentPng.getGlobalBounds().intersects(floatRect);
}


void ScorePresent::handleCollision(Object& obj)
{
	if (&obj == this)
		return;
	obj.handleCollision(*this);
}

void ScorePresent::handleCollision(Player& obj)
{
	obj.setScore(10);
	m_presentPng.setPosition(TO_DELETED);//delete coin and get into position -1 -1 to delete
	obj.handleCollision(*this);
}

void ScorePresent::handleCollision(Enemy& gameObject)
{
}

void ScorePresent::handleCollision(Present& gameObject)
{
}

void ScorePresent::handleCollision(Coin& gameObject)
{
}

void ScorePresent::handleCollision(Floor& gameObject)
{
}

void ScorePresent::handleCollision(Rod& gameObject)
{
}

void ScorePresent::handleCollision(Ladder& gameObject)
{
}
