#pragma once
#include <SFML/Graphics.hpp>
#include "MovingObject.h"
#include "Utillities.h"
#include <iostream>
#include <ostream>

class Player : public MovingObject
{
public:
    Player() {};
    Player(sf::Sprite picture, const int speed);
  //  Player(sf::Texture picture, const int speed);
   // Player(sf::Texture picture);
    Player(sf::Sprite picture);
    virtual ~Player() =default;
    virtual void setLocation(const float y, const float x)override;
    virtual void print(sf::RenderWindow& window)override;
    virtual void move(const sf::Time &timePassed)override;
    //void dig();
    //bool canDig();
    void setSprite(const sf::Texture& picture);
  //  void setSprite(const sf::Sprite& picture);
    virtual void setSpeed(const int)override ;
    virtual int getSpeed()override ;
    //virtual sf::Sprite getSprite() ;
    //virtual bool checkNextMove();
    virtual void setDirection(sf::Keyboard::Key);
    void changeface(bool toRight);

    //virtual void setLocation();

private:
        sf::Sprite m_playerPng;
        int m_speed=1;
        sf::Vector2f m_direction;
};
