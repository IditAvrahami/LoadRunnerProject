#pragma once
#include <SFML/Graphics.hpp>
#include "MovingObject.h"

class Enemy : public MovingObject
{
public:
    Enemy();
    virtual ~Enemy()=default;
    virtual void setLocation(const int y, const int x);
    virtual void print();
    virtual void move();
    virtual sf::Sprite getSprite();
    virtual bool checkNextMove();
    virtual void setSpeed() ;
    virtual int getSpeed() ;
    virtual void setSign() ;
    virtual void move() ;
    //int enemyMovments();  
  
private:
    sf::Sprite m_enemyPng;
    
};
