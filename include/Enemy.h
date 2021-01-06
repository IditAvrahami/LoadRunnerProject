#pragma once
#include <SFML/Graphics.hpp>
#include "MovingObject.h"
#include "Utillities.h"
#include <iostream>
#include <ostream>

class Enemy : public MovingObject
{
public:

    Enemy(sf::Sprite picture, const int speed);
    virtual ~Enemy() = default;
    virtual void setLocation(const float y, const float x);
    void moveLocation(const sf::Vector2f& d, sf::Time t);
    virtual void print(sf::RenderWindow& window);
    virtual void move(const sf::Time& time);
    virtual sf::Sprite getSprite();
   virtual sf::Vector2f getLocation()const;
    virtual void setSpeed(const int);
    virtual int getSpeed();

private:
    sf::Sprite m_enemyPng;
    int m_speed;
};
