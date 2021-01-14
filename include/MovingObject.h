#pragma once
#include <SFML/Graphics.hpp>
#include "Object.h"

class Board;

class MovingObject : public Object
{
public:
    MovingObject()=default;
    virtual ~MovingObject() = default;
    virtual void setSpeed(const int)=0;
    virtual int getSpeed()=0;
    virtual void move(const sf::Time& time)=0;
    virtual void gravityFunction()=0;
    virtual void moveLocation(const sf::Vector2f& d, sf::Time t)=0;

private:
    int m_speed=1;
};
