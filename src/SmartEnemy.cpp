#pragma once
#include "SmartEnemy.h"

SmartEnemy::SmartEnemy(sf::Sprite picture, const int speed) : Enemy(picture, speed)
{}

std::vector<sf::Vector2f> SmartEnemy::directionToGo()
{
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
				move[1] = KB_LEFT;
				move[3] = KB_RIGHT;
			}
			else
			{
				move[1] = KB_RIGHT;
				move[3] = KB_LEFT;
			}
		}
		else
		{
			move[0] = KB_DOWN;
			move[2] = KB_UP;
			if (y > 0)
			{
				move[1] = KB_LEFT;
				move[3] = KB_RIGHT;
			}
			else
			{
				move[1] = KB_RIGHT;
				move[3] = KB_LEFT;
			}
		}
	else if (y > 0)
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
	else
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

	return move;
	
}
void SmartEnemy::move(const sf::Time& time)
{
	std::vector<sf::Vector2f> direction = directionToGo(); //need caculate direction
	sf::Vector2f toMove = nextMove(direction);
	Enemy::moveLocation(toMove, time);
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
