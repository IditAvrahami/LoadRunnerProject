#include "..\include\Player.h"
#include "Player.h"
#include "Board.h"
#include "Utillities.h"
#include <SFML/Graphics.hpp>

Player::Player(sf::Sprite picture, const int speed)
	:m_playerPng(picture), m_speed(speed), m_direction(sf::Vector2f(0, 0)), m_lives(3),m_score(0)
{}


Player::Player(sf::Sprite picture)
	: m_playerPng(picture), m_speed(1), m_direction(sf::Vector2f(0, 0)), m_lives(3), m_score(0)
{}
void Player::setLocation(const float y, const float x)
{
	m_playerPng.setPosition(sf::Vector2f(x * COMPARISON, y * COMPARISON));
}

sf::Vector2f Player::getLocation() const
{
	return m_playerPng.getPosition();
}

void Player::print(sf::RenderWindow& window)
{
//	std::cout << "player class:  x:  " << m_playerPng.getPosition().x << "y: " << m_playerPng.getPosition().y << std::endl;
	window.draw(m_playerPng);
}

void Player::move(const sf::Time& timePassed)
{
//	Movment myMovment;
	
	m_playerPng.move( m_speed * timePassed.asSeconds()* m_direction);
	m_lastDirection = m_speed * timePassed.asSeconds() * m_direction;
	//if colision return to place
	//if (checkcolision(m_playerPng.getPosition() ) )
	//	m_playerPng.move(m_direction * m_speed * timePassed.asSeconds() * -1 );

}

void Player::moveLocation(const sf::Vector2f& direction, sf::Time time)
{
	m_playerPng.move(m_speed * time.asSeconds() * direction);
	m_lastDirection = m_speed * time.asSeconds() * direction;
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

bool Player::checkCollision(const sf::FloatRect& floatRect) const
{
	return m_playerPng.getGlobalBounds().intersects(floatRect);
}

sf::FloatRect Player::getGlobalBounds() const
{
	return m_playerPng.getGlobalBounds();
}

void Player::handleCollision(Object& obj)
{
	if (&obj == this)
		return;
	obj.handleCollision(*this);
}

void Player::handleCollision(Coin& gameObject)
{
	m_score += gameObject.getValue();
	//gameObject.handleCollision(*this);
}

void Player::handleCollision(Present& gameObject)
{
	////////////////////////////////////////////////////////////
}

void Player::handleCollision(Floor& gameObject)
{
	m_playerPng.move(m_lastDirection.x * (-1), m_lastDirection.y * (-1));
	m_lastDirection.x *= (-1);
	m_lastDirection.y *= (-1);
}

void Player::handleCollision(Enemy& gameObject)
{
	m_lives--;
	lastScoreUpdateLose();
}

void Player::handleCollision(Rod& gameObject)
{

}

void Player::handleCollision(Ladder& gameObject)
{
}

void Player::gravityFunction()
{
	//Movment myMove;
	//int x = (m_playerPng.getPosition().x) / COMPARISON + KB_DOWN.x;
	//int y = (m_playerPng.getPosition().y) / COMPARISON + KB_DOWN.y;
	sf::Time time = sf::milliseconds(1);
	moveLocation(KB_DOWN, time);
	//m_playerPng.move(KB_DOWN); // sfml function
	//while (!Board::boardObject().handleCollisions(*this))
	//	m_playerPng.move(KB_DOWN);

	/*if (myMove.canDown(x, y))
	{
		//sf::Vector2f down = KB_DOWN;
		//down.x *= m_speed;
		//down.y *= m_speed;
		m_playerPng.move(KB_DOWN); // sfml function
	}*/
}

void Player::setSpeed(const int speed)
{
	m_speed = speed;
}

int Player::getSpeed()
{
	return m_speed;
}

void Player::setScore(const int more)
{
	m_score += more;
}

int Player::getScore()
{
	return m_score;
}

void Player::setLastScore()
{
	m_lastScore = m_score;
}

void Player::lastScoreUpdateLose()
{
	m_score = m_lastScore;
}

void Player::setLives(const int more)
{
	if(more == 1 || more == -1)
	m_lives += more;
}

int Player::getLives()
{
	return m_lives;
}
