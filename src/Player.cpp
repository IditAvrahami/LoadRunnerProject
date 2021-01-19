#include "..\include\Player.h"
#include "Player.h"
#include "Board.h"
#include "Utillities.h"
#include <SFML/Graphics.hpp>
#include "Rod.h"
/*
Player::Player(sf::Sprite picture, const int speed)
	:m_playerPng(picture), m_speed(speed), m_direction(sf::Vector2f(0, 0)), m_lives(3), m_score(0)
{}
*/
/*
Player::Player(sf::Sprite picture)
	: m_playerPng(picture), m_speed(1), m_direction(sf::Vector2f(0, 0)), m_lives(3), m_score(0)
{}
*/
Player::Player() 
{
	m_playerPic.loadFromFile("player.png");
	m_playerPng.setTexture(m_playerPic);
	//	m_playerPng = sf::Sprite(m_playerPic);
	m_speed = 1;
	m_livesfont.loadFromFile("resources/sansation.ttf");
	m_livesText.setFont(m_livesfont);
	m_livesText.setCharacterSize(50);
//	m_livesText.setPosition((float)((width - 6) * COMPARISON), (float)((height)*COMPARISON));
	m_livesText.setFillColor(sf::Color::White);

	m_scorefont.loadFromFile("resources/sansation.ttf");
	m_scoreText.setFont(m_scorefont);
	m_scoreText.setCharacterSize(50);
//	m_scoreText.setPosition((float)((width - 9) * COMPARISON), (float)((height)*COMPARISON));
	m_scoreText.setFillColor(sf::Color::White);

}

void Player::updateFont()
{
	int width = Board::boardObject().getWidth();
	int height = Board::boardObject().getHeight();

	m_livesText.setPosition((float)((width - 5)* COMPARISON), (float)((height)*COMPARISON));
	m_scoreText.setPosition((float)((width - 7)* COMPARISON), (float)((height)*COMPARISON));
}

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
	m_scoreText.setString(std::to_string(m_score));
	window.draw(m_scoreText); 
	m_livesText.setString(std::to_string(m_lives));
	window.draw(m_livesText);

	window.draw(m_playerPng);
}

void Player::move(const sf::Time& timePassed)
{
	Movment movment;
	sf::Vector2f place = m_playerPng.getPosition();
	place.x /= COMPARISON;
	place.y /= COMPARISON;
	if (movment.isRod(place.y, place.x) && m_direction == KB_UP)
	//if (movment.isRod(place.x, place.y) && m_direction == KB_UP)
	{
		return;
	}
	m_playerPng.move(m_speed * timePassed.asSeconds() * m_direction);
	m_lastDirection = m_speed * timePassed.asSeconds() * m_direction;

}

void Player::dig()
{
	Movment movment;
	int nextx = m_playerPng.getPosition().x / COMPARISON;
	int nexty = m_playerPng.getPosition().y / COMPARISON;
	//movment.disappearFloor(nextx, nexty);
	//movment.disappearFloor(nexty, nextx); // we change
	if(m_wantDig == left)
		movment.disappearFloor(nexty + KB_DOWN.y + KB_LEFT.y, nextx + KB_DOWN.x + KB_LEFT.x);
	if(m_wantDig == right)
		movment.disappearFloor(nexty + KB_DOWN.y + KB_RIGHT.y, nextx + KB_DOWN.x + KB_RIGHT.x);
										  //add call to disapper of floor

	m_wantDig = dontWont;
}

void Player::moveLocation(const sf::Vector2f& direction, sf::Time time)
{
	m_playerPng.move(m_speed * time.asSeconds() * direction);
	m_lastDirection = m_speed * time.asSeconds() * direction;
}

Player& Player::instance()
{
	static Player player;
	return player;
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

sf::Sprite Player::getSprite() const
{
	return m_playerPng;
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
