#pragma once
#include "Floor.h"
#include "Board.h"

Floor::Floor(sf::Sprite picture) : m_floorPng(sf::Sprite(picture))
{}

void Floor::print(sf::RenderWindow& window)
{
	if (!m_Disappear)
	{
		sf::Vector2f windowPosition, temp;
		temp.x = m_floorPng.getPosition().x;
		temp.y = m_floorPng.getPosition().y;
		windowPosition.x = m_floorPng.getPosition().x - COMPARISON;
		windowPosition.y = m_floorPng.getPosition().y - COMPARISON;
		m_floorPng.setPosition(windowPosition);
		window.draw(m_floorPng);
		m_floorPng.setPosition(temp);
	}
//	window.draw(m_floorPng);
}

void  Floor::setLocation(const float y, const float x)
{
	m_floorPng.setPosition(sf::Vector2f(x*COMPARISON, y*COMPARISON));
}

bool Floor::checkCollision(const sf::FloatRect& floatRect) const
{
	return m_floorPng.getGlobalBounds().intersects(floatRect);
}

sf::FloatRect Floor::getGlobalBounds() const
{
	return m_floorPng.getGlobalBounds();
}

void Floor::handleCollision(Object& obj)
{
	if (&obj == this)
		return;
	obj.handleCollision(*this);
}

void Floor::handleCollision(Player& gameObject)
{
	if (!m_Disappear)
		gameObject.handleCollision(*this);
}

void Floor::handleCollision(Enemy& gameObject)
{
	if (m_fullFloor && !m_Disappear)
	{
		sf::Vector2f position = m_floorPng.getPosition();
		position.x /= COMPARISON;
		position.y /= COMPARISON;
		gameObject.setLocation(position.y-1, position.x);
	}
	else if (!m_Disappear)
		gameObject.handleCollision(*this);
	else
		m_fullFloor = true;
}

sf::Vector2f Floor::getLocation() const
{
	return m_floorPng.getPosition();
}

void Floor::setSprite(sf::Sprite sprite)
{
	m_floorPng = sprite;
}

bool Floor::getDisappear() const
{
	return m_Disappear;
}

void Floor::disappear()
{
	if (!m_Disappear)
	{
		if (m_floorPng.getPosition().y == (Board::boardObject().getHeight()-1) * COMPARISON)
			return;
		m_Disappear = true;
		m_disappearTimer.restart();
		m_position = m_floorPng.getPosition();
		//m_floorPng.setPosition(TO_DELETED);
	}
}

void Floor::appear(sf::Sprite sprite)
{
	sf::Time AITime = sf::milliseconds(3000.0f);
	if (m_Disappear)
	{
		if (m_disappearTimer.getElapsedTime().asMilliseconds() > AITime.asMilliseconds())
		{
			m_Disappear = false;
			//setSprite(sprite);
			m_floorPng.setPosition(m_position);
			if (m_floorPng.getGlobalBounds().intersects(Player::instance().getGlobalBounds()))
				Player::instance().setLives(-1);
			
		}
		
	}
}