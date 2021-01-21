#pragma once
#include "SmartEnemy.h"

SmartEnemy::SmartEnemy(sf::Sprite picture, const int speed) : Enemy(picture, speed)
{}

sf::Vector2f SmartEnemy::directionToGo()
{
	Movment movment;
	sf::Vector2f playerPosition = Player::instance().getLocation();

	if (playerPosition.y > Enemy::getLocation().y
		&& movment.ifCanDown((Enemy::getLocation().y) / COMPARISON, Enemy::getLocation().x / COMPARISON))//thereIsLadderOrRod())
	{
	//	if (movment.isLadder((Enemy::getLocation().y + 5) / COMPARISON, Enemy::getLocation().x / COMPARISON))
	//		Enemy::setLocation(Enemy::getLocation().y, Enemy::getLocation().x - 2);
		return KB_DOWN;
	}
	else if (playerPosition.y < Enemy::getLocation().y &&
		movment.canUp((Enemy::getLocation().y ) / COMPARISON, Enemy::getLocation().x / COMPARISON))
	{
	//	if (movment.isLadder((Enemy::getLocation().y + 5) / COMPARISON, Enemy::getLocation().x / COMPARISON))
	//		Enemy::setLocation(Enemy::getLocation().y, Enemy::getLocation().x - 2);
		return KB_UP;
	}
	else if (playerPosition.x > Enemy::getLocation().x)
		return KB_RIGHT;
	else if (playerPosition.x < Enemy::getLocation().x)
		return KB_LEFT;




	/*
	std::vector<sf::Vector2f> move;
	move.resize(4);
	//findBestDirection();

//	int* move = new int[4];
//	int row, col;
	int x = Enemy::getLocation().x - Player::instance().getLocation().x;
	int y = Enemy::getLocation().y - Player::instance().getLocation().y;
	
//	if (abs(col) > abs(row))
	if(abs(x) > abs(y))
		if (x < 0)
		{
			move[0] = KB_UP;
			move[2] = KB_DOWN;
			if (y < 0)
			{
				move[1] = KB_RIGHT;
				move[3] = KB_LEFT;
			}
			else
			{
				move[1] = KB_LEFT;
				move[3] = KB_RIGHT;
			}
		}
		else
		{
			move[0] = KB_DOWN;
			move[2] = KB_UP;
			if (y > 0)
			{
				move[1] = KB_RIGHT;
				move[3] = KB_LEFT;
			}
			else
			{
				move[1] = KB_LEFT;
				move[3] = KB_RIGHT;
			}
		}
	else if (y > 0)
	{
		move[0] = KB_RIGHT;
		move[2] = KB_LEFT;
		if (x < 0)
		{
			move[1] = KB_UP;
			move[3] = KB_DOWN;
		}
		else
		{
			move[1] = KB_DOWN;
			move[3] = KB_UP;
		}
	}
	else
	{
		move[0] = KB_LEFT;
		move[2] = KB_RIGHT;
		if (x < 0)
		{
			move[1] = KB_UP;
			move[3] = KB_DOWN;
		}
		else
		{
			move[1] = KB_DOWN;
			move[3] = KB_UP;
		}
	}

	return move;
	*/
}
void SmartEnemy::move(const sf::Time& time)
{

	sf::Vector2f direction = directionToGo(); //need caculate direction
	//sf::Vector2f toMove = nextMove(direction);
	Movment movment;
	int nextx = Enemy::getLocation().x / COMPARISON;
	int nexty = Enemy::getLocation().y / COMPARISON;
	sf::Vector2f position = Enemy::getLocation();

	if (direction == KB_RIGHT && (movment.isFloor(nexty + KB_DOWN.y + KB_RIGHT.y, nextx + KB_DOWN.x + KB_RIGHT.x)
		&& movment.isDisappear(nexty + KB_DOWN.y + KB_RIGHT.y, nextx + KB_DOWN.x + KB_RIGHT.x)))
	{
		direction = KB_STAY;
		position = Enemy::getLocation();
		Enemy::setLocation(nexty + KB_DOWN.y + KB_RIGHT.y, nextx + KB_DOWN.x + KB_RIGHT.x);
	}
	else if (direction == KB_LEFT && (movment.isFloor(nexty + KB_DOWN.y + KB_LEFT.y, nextx + KB_DOWN.x + KB_LEFT.x)
		&& movment.isDisappear(nexty + KB_DOWN.y + KB_LEFT.y, nextx + KB_DOWN.x + KB_LEFT.x)))
	{
		direction = KB_STAY;
		position = Enemy::getLocation();
		Enemy::setLocation(nexty + KB_DOWN.y + KB_LEFT.y, nextx + KB_DOWN.x + KB_LEFT.x);
	}


	Enemy::moveLocation(direction, time);
}

sf::Vector2f SmartEnemy::nextMove(const std::vector<sf::Vector2f>& direction) const
{
	Movment movment;
	int x = (int)(Enemy::getLocation().x / COMPARISON);
	int y = (int)(Enemy::getLocation().y / COMPARISON);
	
	for (size_t i = 0; i < 4; i++)
	{
		if (direction[i] == KB_DOWN)
		{
			if (movment.canDown(y, x))
				return KB_DOWN;
		}
		else if (direction[i] == KB_LEFT)
		{
			if (movment.canLeft(y, x))
				return KB_LEFT;
		}
		else if (direction[i] == KB_RIGHT)
		{
			if (movment.canRight(y, x))
				return KB_RIGHT;
		}
		else if (direction[i] == KB_UP)
		{
			if (movment.canUp(y, x))
				return KB_UP;
		}
	}
	
	return KB_STAY;
}
