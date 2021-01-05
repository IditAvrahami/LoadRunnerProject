#include "Player.h"
#include <SFML/Graphics.hpp>

Player::Player(sf::Texture picture, const int speed) 
	:m_playerPng(picture),m_speed(speed), m_direction(sf::Vector2f(0,0))
{}

void Player::setLocation(const int y, const int x)
{
	m_playerPng.setPosition((float)x, (float)y);
}

void Player::print()
{
	
}
