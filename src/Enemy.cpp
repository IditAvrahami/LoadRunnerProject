//#include "..\include\Enemy.h"
#pragma once
#include "Enemy.h"
#include <SFML/System/Vector2.hpp>
#include "Floor.h"

Enemy::Enemy(sf::Sprite picture, const int speed) : m_enemyPng(sf::Sprite(picture)), m_speed(speed)
{}

void Enemy::setLocation(const float y, const float x)
{
	m_enemyPng.setPosition(sf::Vector2f(x * COMPARISON, y * COMPARISON));
}

void Enemy::moveLocation(const sf::Vector2f & direction,sf::Time time)
{
	std::cout << "direction " << direction.x << " " << direction.y << std::endl;
	m_enemyPng.move(  m_speed * time.asSeconds() * direction );
	m_direction = m_speed * time.asSeconds() * direction;
//	std::cout << "in move location " << m_direction.x << " " << m_direction.y << std::endl;
}


void Enemy::print(sf::RenderWindow& window)
{
	window.draw(m_enemyPng);
}


void Enemy::move(const sf::Time& time)
{
}

void Enemy::gravityFunction()
{
	sf::Time time = sf::milliseconds(1);
	moveLocation(KB_DOWN, time);
	std::cout << "================================" << std::endl;
	//m_enemyPng.move(KB_DOWN); // sfml function
	/*Movment myMove;
	int x = (m_enemyPng.getPosition().x) / COMPARISON + KB_DOWN.x;
	int y = (m_enemyPng.getPosition().y) / COMPARISON + KB_DOWN.y;

	if (myMove.canDown(x, y))
	{
		sf::Vector2f down = KB_DOWN;
		down.x *= m_speed;
		down.y *= m_speed;
		m_enemyPng.move(down); // sfml function
	}*/
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

bool Enemy::checkCollision(const sf::FloatRect& floatRect) const
{
	return m_enemyPng.getGlobalBounds().intersects(floatRect);
}

sf::FloatRect Enemy::getGlobalBounds() const
{
	return m_enemyPng.getGlobalBounds();
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
	std::cout << "floor pos  " << gameObject.getLocation().x << " " << gameObject.getLocation().y << std::endl;

}

void Enemy::handleCollision(Rod& gameObject)
{ // chage angel?? or picture??
}

void Enemy::handleCollision(Ladder& gameObject)
{
}
