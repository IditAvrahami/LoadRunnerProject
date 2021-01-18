#include "..\include\Player.h"
#include "Player.h"
#include "Board.h"
#include "Utillities.h"
#include <SFML/Graphics.hpp>
#include "Rod.h"

Player::Player(sf::Sprite picture, const int speed)
	:m_playerPng(picture), m_speed(speed), m_direction(sf::Vector2f(0, 0)), m_lives(3), m_score(0)
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
	window.draw(m_playerPng);
}

void Player::move(const sf::Time& timePassed)
{
	Movment movment;
	sf::Vector2f place = m_playerPng.getPosition();
	place.x /= COMPARISON;
	place.y /= COMPARISON;
	if (movment.isRod(place.x, place.y) && m_direction == KB_UP)
	{
		return;
	}
	m_playerPng.move(m_speed * timePassed.asSeconds() * m_direction);
	m_lastDirection = m_speed * timePassed.asSeconds() * m_direction;
	/*if (m_wantDig != dontWont)
	{
		if (canDig())
			dig();
	}*/
}

void Player::dig()
{
	Movment movment;
	int nextx = m_playerPng.getPosition().x / COMPARISON;
	int nexty = m_playerPng.getPosition().y / COMPARISON;

	movment.disappearFloor(nextx, nexty);
	//add call to disapper of floor

	m_wantDig = dontWont;
}

void Player::moveLocation(const sf::Vector2f& direction, sf::Time time)
{
	m_playerPng.move(m_speed * time.asSeconds() * direction);
	m_lastDirection = m_speed * time.asSeconds() * direction;
}

bool Player::canDig()
{
	Movment movment;
	int nextx = m_playerPng.getPosition().x / COMPARISON;
	int nexty = m_playerPng.getPosition().y / COMPARISON;

	if (m_wantDig == right)
		if (movment.isFloor(nexty + KB_DOWN.y + KB_RIGHT.y, nextx + KB_DOWN.x + KB_RIGHT.x))
			return true;
		else
			return false;
	else //m_wantDig == left
		if (movment.isFloor(nexty + KB_DOWN.y + KB_LEFT.y, nextx + KB_DOWN.x + KB_LEFT.x))
			return true;
	return false;
}

void Player::setSprite(const sf::Texture& picture)
{
	m_playerPng.setTexture(picture);
}

void Player::setDirection(sf::Keyboard::Key key)
{
	switch (key)
	{
	case sf::Keyboard::Key::Right:
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
	case sf::Keyboard::Key::Z:
		m_direction = KB_STAY;
		m_wantDig = left;
		if (canDig())
			dig();
		break;
	case sf::Keyboard::Key::X:
		m_direction = KB_STAY;
		m_wantDig = right;
		if (canDig())
			dig();
		break;
	default:
		m_direction = KB_STAY;
	}

}

void Player::changeface(bool toRight)
{
	//need to check to where look and then
	if (toRight)
		m_playerPng.setScale(-1, 1);
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

void Player::handleCollision(Player& gameObject)
{
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
	/*
	static sf::Vector2f lastrod = gameObject.getLocation();
	sf::Vector2f place = gameObject.getLocation();
	if (lastrod == place)
		m_playerPng.setPosition(m_playerPng.getPosition().x, place.y + 20);
	else
		lastrod = place;
	*/
	
	/*
	sf::Vector2f rodPosition = gameObject.getLocation();
//	static Rod rod = gameObject;
	sf::Vector2f position;
	//if(gameObject == rod)
	position = gameObject.getLocation();
	//m_playerPng.setPosition(position.x, position.y + 10);
	m_playerPng.setPosition(m_playerPng.getPosition().x, position.y );
	*/
}

void Player::handleCollision(Ladder& gameObject)
{
}

void Player::gravityFunction()
{
	sf::Time time = sf::milliseconds(1);
	moveLocation(KB_DOWN, time);
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
	if (more == 1 || more == -1)
		m_lives += more;
}

int Player::getLives()
{
	return m_lives;
}
