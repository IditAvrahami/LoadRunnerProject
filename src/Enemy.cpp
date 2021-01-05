#include "..\include\Enemy.h"
#pragma once
#include "Enemy.h"

Enemy::Enemy(sf::Texture picture, const int speed) : m_enemyPng(sf::Sprite(picture)), m_speed(speed)
{}

void Enemy::setLocation(const int y, const int x)
{
	m_enemyPng.setPosition((float)x, (float)y);
}

void Enemy::print(sf::RenderWindow& window)
{
	window.draw(m_enemyPng);
}

void Enemy::move()
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
