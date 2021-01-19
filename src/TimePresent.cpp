#pragma once
#include "TimePresent.h"
#include "Player.h"
#include "Present.h"
#include "Timer.h"

TimePresent::TimePresent(sf::Sprite picture) :Present(picture)
{}

bool TimePresent::checkCollision(const sf::FloatRect& floatRect) const
{
	return m_presentPng.getGlobalBounds().intersects(floatRect);
}


void TimePresent::handleCollision(Object& obj)
{
	if (&obj == this)
		return;
	obj.handleCollision(*this);
}

void TimePresent::handleCollision(Player& obj)
{
//	Timer::instance().addTime(); // ///////////////////   //////////////////   delete this 
	m_presentPng.setPosition(TO_DELETED);//delete coin and get into position -1 -1 to delete
	obj.handleCollision(*this);
}

void TimePresent::handleCollision(Enemy& gameObject)
{
}

void TimePresent::handleCollision(Present& gameObject)
{
}

void TimePresent::handleCollision(Coin& gameObject)
{
}

void TimePresent::handleCollision(Floor& gameObject)
{
}

void TimePresent::handleCollision(Rod& gameObject)
{
}

void TimePresent::handleCollision(Ladder& gameObject)
{
}