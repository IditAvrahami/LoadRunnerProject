#include "..\include\Player.h"
#include "Player.h"
#include "Utillities.h"
#include <SFML/Graphics.hpp>


Player::Player(sf::Texture picture, const int speed) 
	:m_playerPng(picture),m_speed(speed), m_direction(sf::Vector2f(0,0))
{}

Player::Player(sf::Texture picture)
	: m_playerPng(picture), m_speed(1), m_direction(sf::Vector2f(0, 0))
{}

void Player::setLocation(const int y, const int x)
{
	m_playerPng.setPosition((float)x, (float)y);
}

void Player::print(sf::RenderWindow& window)
{
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
	}
	m_direction = (0,0);
}

void Player::changeface(bool toRight)
{
	//need to check to where look and then
	if (toRight)
		m_playerPng.setScale(-1,1);
	else
		m_playerPng.setScale(1, 1);
}