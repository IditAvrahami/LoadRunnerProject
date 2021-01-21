#include "Movment.h"
#include "Board.h"
#include "Rod.h"
#include "Ladder.h"
#include "Floor.h"

Movment::Movment() :m_map(Board::boardObject().getBoard())
{}

bool Movment::isRod(const int x, const int y) const
{
	if (isValid(x, y))
	{
		if (m_map[x][y])
		{
			if (typeid(*m_map[x][y]) == typeid(Rod))
				return true;
		}
		return false;
	}
}

bool Movment::isLadder(const int x, const int y) const
{
	if (isValid(x, y))
	{
		if (m_map[x][y])
		{
			if (typeid(*m_map[x][y]) == typeid(Ladder))
				return true;
		}
		return false;
	}
}

bool Movment::isFloor(const int x, const int y) const
{
	if (isValid(x, y))
	{
		if (m_map[x][y])
		{
			if (typeid(*m_map[x][y]) == typeid(Floor))
			{
				//		Floor* floor = dynamic_cast<Floor*>(m_map[x][y]);
				//		bool disappear = floor->getDisappear();
				//	if (!disappear) // diappear == true need to ignore
				return true;
			}
		}
		return false;
	}
}

bool Movment::isNull(const int x, const int y) const
{
	if (isValid(x, y))
	{
		if (m_map[x][y])
		{
			return false;
		}
		return true;
	}
}

bool Movment::isDisappear(const int x, const int y) const
{
	Floor* floor = dynamic_cast<Floor*>(m_map[x][y]);
	bool disappear = floor->getDisappear();
	if (disappear) // if the floor in x, y index is disappear
		return true;

	return false;
}

bool Movment::isValid(const int x, const int y)const
{
	if (x > 0 && x < Board::boardObject().getHeight())
	{
		if (y > 0 && y + 1 < Board::boardObject().getWidth())
			return true;
	}
	return false;
}

/*bool Movment::isRod(const int x, const int y) const
{
	if (m_map[x][y])
	{
	if (typeid(*m_map[x][y]) == typeid(Rod))
		return true;
	}
	return false;
}

bool Movment::isLadder(const int x, const int y) const
{
	if (m_map[x][y])
	{
		if (typeid(*m_map[x][y]) == typeid(Ladder))
			return true;
	}
	return false;
}

bool Movment::isFloor(const int x, const int y) const
{
	if (m_map[x][y])
	{
		if (typeid(*m_map[x][y]) == typeid(Floor))
		{
			Floor* floor = dynamic_cast<Floor*>(m_map[x][y]);
			bool disappear = floor->getDisappear();
			if (!disappear) // diappear == true need to ignore
			return true;
		}
	}
	return false;
}

bool Movment::isNull(const int x, const int y) const
{
	if (m_map[x][y])
	{
			return false;
	}
	return true;
}*/

bool Movment::canUp(const int x,const int y) const
{
	//int newXUp = x + KB_UP.x;
	//int newYUp = y + KB_UP.y;

	int newXUp = x + KB_UP.y;
	int newYUp = y + KB_UP.x;


	if (isLadder(newXUp, newYUp))
		return true;
	
	return false;
}

bool Movment::ifCanDown(const int x, const int y) const
{
	int newXUp = x + KB_DOWN.y;
	int newYUp = y + KB_DOWN.x;
	if (isLadder(newXUp, newYUp) || isRod(newXUp, newYUp) || !m_map[newXUp][newYUp])// && !m_map[x][y] && isFloor(x, y))// || typeid(*m_map[x][y]) == typeid(nullptr))
	{
		return true;
	}
	return false;
}


bool Movment::canDown(const int x, const int y) const
{
	int newXUp = x + KB_DOWN.x;
	int newYUp = y + KB_DOWN.y;
	if (!isLadder(x, y) && !isRod(x, y) && !m_map[x][y] && isFloor(x,y))// || typeid(*m_map[x][y]) == typeid(nullptr))
	{
		return true;
	}
		return false;
}

bool Movment::canRight(const int x, const int y) const
{
	int checkX = x + KB_RIGHT.x;
	int checkY = y + KB_RIGHT.y;

//	if (isLadder(x, y) && !m_map[checkX][checkY] )
	if (isLadder(x, y) && isFloor(checkX, checkY))
	{
		return false;
	}
	if(isRod(x, y) && isFloor(checkX, checkY))
	{
		return false;
	}
	return true;
}

bool Movment::canLeft(const int x, const int y) const
{
	int checkX = x + KB_LEFT.x;
	int checkY = y + KB_LEFT.y;

	//	if (isLadder(x, y) && !m_map[checkX][checkY] )
	if (isLadder(x, y) && isFloor(checkX,checkY))
	{
		return false;
	}
	if (isRod(x, y) && isFloor(checkX,checkY))
	{
		return false;
	}
	return true;
}

void Movment::disappearFloor(const int x, const int y) const
{
	if (typeid(*m_map[x][y]) == typeid(Floor))
	{
		Floor* floor = dynamic_cast<Floor*>(m_map[x][y]); //get regular poinetr to floor in i j position
		floor->disappear();
	}
}
