#pragma once
#include "Enemy.h"

Enemy::Enemy(sf::Texture picture, const int speed) : m_enemyPng(sf::Sprite(picture)), m_speed(speed)
{}

void Enemy::setLocation(const int x, const int y)
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

void Enemy::setSpeed(const int newSpeed)
{
	m_speed = newSpeed;
}

int Enemy::getSpeed()
{
	return m_speed;
}

