#include "Movment.h"
#include "Board.h"
#include "Rod.h"
#include "Ladder.h"
#include "Floor.h"

Movment::Movment() :m_map(Board::boardObject().getBoard())
{}

bool Movment::isRod(const int x, const int y) const
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
			return true; 
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
}

bool Movment::canUp(const int x,const int y) const
{
	int newXUp = x, newYUp = y;
	newXUp += KB_UP.x;
	newYUp += KB_UP.y;
	if (isLadder(newXUp, newYUp))
		return true;
	return false;
}

bool Movment::canDown(const int x, const int y) const
{
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
		Floor* floor = dynamic_cast<Floor*>(m_map[x][y]);
		floor->disappear();
	}
}
