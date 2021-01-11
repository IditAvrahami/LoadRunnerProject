#include "..\include\Enemy.h"
#pragma once
#include "Enemy.h"

Enemy::Enemy(sf::Sprite picture, const int speed) : m_enemyPng(sf::Sprite(picture)), m_speed(speed)
{}

void Enemy::setLocation(const float y, const float x)
{
	m_enemyPng.setPosition(sf::Vector2f(x * COMPARISON, y * COMPARISON));
}

void Enemy::moveLocation(const sf::Vector2f & direction,sf::Time time)
{
	m_enemyPng.move(  m_speed * time.asSeconds() * direction );
	m_direction = m_speed * time.asSeconds() * direction;
}


void Enemy::print(sf::RenderWindow& window)
{
	window.draw(m_enemyPng);
}

void Enemy::move(const sf::Time& time)
{
}

sf::Sprite Enemy::getSprite()
{
	return m_enemyPng;
}

sf::Vector2f Enemy::getLocation() const
{
	return m_enemyPng.getPosition();
}

void Enemy::setSpeed(const int newSpeed)
{
	m_speed = newSpeed;
}

int Enemy::getSpeed()
{
	return m_speed;
}

sf::Vector2f Enemy::getDirection()
{
	return m_direction;
}

void Enemy::handleCollision(Object& obj)
{
	if (&obj == this)
		return;
	obj.handleCollision(*this);
}

void Enemy::handleCollision(Player& obj)
{
	//update lives and set last score (the good idea of daniel or abayev)in player
	obj.handleCollision(*this);
}



void Enemy::handleCollision(Floor& gameObject)
{
	m_enemyPng.move(m_direction.x*(-1), m_direction.y*(-1));
	m_direction.x *= (-1);
	m_direction.y *= (-1);
}

void Enemy::handleCollision(Rod& gameObject)
{ // chage angel?? or picture??
}

void Enemy::handleCollision(Ladder& gameObject)
{
}
