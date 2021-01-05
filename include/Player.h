#pragma once
#include <SFML/Graphics.hpp>
#include "MovingObject.h"

class Player : public MovingObject
{
public:
    Player(sf::Texture picture, const int speed);
    virtual ~Player() =default;
    virtual void setLocation(const int y, const int x);
    virtual void print();
    virtual void move();
    void dig();
    bool canDig();
    virtual sf::Sprite getSprite() ;
    virtual bool checkNextMove();
    virtual void setDirection(sf::Keyboard::Key);

    //virtual void setLocation();

private:
        sf::Sprite m_playerPng;
        int m_speed;
        sf::Vector2f m_direction;
};
