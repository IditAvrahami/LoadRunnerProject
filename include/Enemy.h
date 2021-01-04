#pragma once
#include <SFML/Graphics.hpp>
#include "MovingObject.h"

class Enemy : public MovingObject
{
public:
    Enemy();
    virtual ~Enemy()=default;
    virtual void setLocation(const int row, const int col);
    virtual void print();
    virtual void move();
    virtual sf::Sprite getSprite();
    virtual void setLocation();
    virtual bool checkNextMove();
    //int enemyMovments();  
  
private:
    sf::Sprite m_enemyPng;
    
};
