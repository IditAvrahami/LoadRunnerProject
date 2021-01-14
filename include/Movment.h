#pragma once
//#include "Board.h"

class Ladder;
class Rod;
class Floor;
class StaticObject;

class Movment
{
public:
	Movment();
	~Movment();
	bool isRod(const int x, const int y)const;
	bool isLadder(const int x, const int y)const;
	bool isFloor(const int x, const int y)const;

private:
	std::vector<std::vector<StaticObject*>> m_map;
};
