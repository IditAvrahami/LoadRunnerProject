#include "..\include\Player.h"
#include "Player.h"
#include "Utillities.h"
#include <SFML/Graphics.hpp>

Player::Player(sf::Sprite picture, const int speed)
	:m_playerPng(picture), m_speed(speed), m_direction(sf::Vector2f(0, 0))
{}


Player::Player(sf::Sprite picture)
	: m_playerPng(picture), m_speed(1), m_direction(sf::Vector2f(0, 0))
{}
void Player::setLocation(const float y, const float x)
{
	m_playerPng.setPosition(sf::Vector2f(x * COMPARISON, y * COMPARISON));
}

void Player::print(sf::RenderWindow& window)
{
	std::cout << "player class:  x:  " << m_playerPng.getPosition().x << "y: " << m_playerPng.getPosition().y << std::endl;
	window.draw(m_playerPng);
}

void Player::move(const sf::Time& timePassed)
{
	m_playerPng.move( m_speed * timePassed.asSeconds()* m_direction);
	//if colision return to place
	//if (checkcolision(m_playerPng.getPosition() ) )
	//	m_playerPng.move(m_direction * m_speed * timePassed.asSeconds() * -1 );

}

void Player::setSprite(const sf::Texture &picture)
{
	m_playerPng.setTexture(picture);
}

void Player::setDirection(sf::Keyboard::Key key)
{
	switch (key)
	{
	case sf::Keyboard::Key::Right :
		m_direction = KB_RIGHT;
		break;
	case sf::Keyboard::Key::Left:
		m_direction = KB_LEFT;
		break;
	case sf::Keyboard::Key::Up:
		m_direction = KB_UP;
		break;
	case sf::Keyboard::Key::Down:
		m_direction = KB_DOWN;
		break;
	default:
			m_direction = KB_STAY;
	}

}

void Player::changeface(bool toRight)
{
	//need to check to where look and then
	if (toRight)
		m_playerPng.setScale(-1,1);
	else
		m_playerPng.setScale(1, 1);
}

void Player::setSpeed(const int speed)
{
	m_speed = speed;
}

int Player::getSpeed()
{
	return m_speed;
}
