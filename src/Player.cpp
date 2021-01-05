#include "Player.h"

Player::Player()
{

}

void Player::setLocation(const int y, const int x)
{
	m_playerPng.setPosition((float)x, (float)y);
}
