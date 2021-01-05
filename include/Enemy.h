#pragma once
#include <SFML/Graphics.hpp>
#include "MovingObject.h"

class Enemy : public MovingObject
{
public:
    Enemy(sf::Texture picture, const int speed);
    virtual ~Enemy() = default;
    virtual void setLocation(const int y, const int x);
    virtual void print(sf::RenderWindow& window);
    virtual void move(); // empy
    virtual sf::Sprite getSprite();
   virtual sf::Vector2f getLocation()const;
    //virtual bool checkNextMove(const int direction);
    virtual void setSpeed(const int);
    virtual int getSpeed();

private:
    sf::Sprite m_enemyPng;
    int m_speed;
};
