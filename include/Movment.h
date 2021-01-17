#pragma once
#include "Utillities.h"
//#include "Board.h"
class Board;
class Ladder;
class Rod;
class Floor;
class StaticObject;

class Movment
{
public:
	Movment();
	virtual ~Movment()=default;
	bool isRod(const int x, const int y)const;
	bool isLadder(const int x, const int y)const;
	bool isFloor(const int x, const int y)const;
	bool isNull(const int x, const int y)const;
	bool canUp (const int x,const int y)const;
	bool canDown(const int x, const int y)const;
	bool canRight(const int x, const int y)const;
	bool canLeft(const int x, const int y)const;

private:
	std::vector<std::vector<StaticObject*>> m_map;
};
