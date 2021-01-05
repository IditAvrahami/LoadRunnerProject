#pragma once
#include <SFML/Graphics.hpp>
#include "Object.h"

class Board;

class MovingObject : public Object
{
public:
    MovingObject();
    virtual ~MovingObject() = default;
    virtual bool checkNextMove()=0;
    virtual void setSpeed()=0;
    virtual int getSpeed()=0;
    virtual void setSign()=0;
    virtual void setLocation(const int y, const int x)=0;
    virtual void move()=0;


private:
  //  sf::sprite m_hideObject;
    int m_speed;
};
