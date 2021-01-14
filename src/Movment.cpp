#include "Movment.h"

Movment::Movment() :m_map(Board::boardObject().getBoard())
{
}

bool Movment::isRod(const int x, const int y) const
{
	if (typeid(*m_map[x][y]) == typeid(Rod))
		return true;
	return false;
}

bool Movment::isLadder(const int x, const int y) const
{
	if (typeid(*m_map[x][y]) == typeid(Ladder))
		return true;
	return false;
}

bool Movment::isFloor(const int x, const int y) const
{
	if (typeid(*m_map[x][y]) == typeid(Floor))
		return true;
	return false;
}