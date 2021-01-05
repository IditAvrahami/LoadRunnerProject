#pragma once
#include <SFML/Graphics.hpp>
#include "Object.h"

class Board;

class MovingObject : public Object
{
public:
    MovingObject()=default;
    virtual ~MovingObject() = default;
  //  virtual bool checkNextMove()=0;
  //  virtual void print(sf::RenderWindow& window);
    virtual void setSpeed(const int)=0;
    virtual int getSpeed()=0;
  //  virtual void setLocation(const int y, const int x)=0;
    virtual void move(const sf::Time& time)=0;


private:
  //  sf::sprite m_hideObject;
    int m_speed=1;
};
