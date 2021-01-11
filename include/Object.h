#pragma once
#include <SFML/Graphics.hpp>
#include "Utillities.h"

class Player;
class Enemy;
class Coin;
class Present;
class Floor;
class Rod;
class Ladder;

class Object
{
public:
    Object()=default;
    virtual ~Object()= default;
    virtual void print(sf::RenderWindow& window)=0;
    virtual void setLocation(const float y, const float x)=0;
    virtual void handleCollision(Object& gameObject) = 0;
    virtual void handleCollision(Player& gameObject) = 0;
    virtual void handleCollision(Enemy& gameObject) = 0;
    virtual void handleCollision(Present& gameObject) = 0;
    virtual void handleCollision(Coin& gameObject)  = 0;
    virtual void handleCollision(Floor& gameObject)  = 0;
    virtual void handleCollision(Rod& gameObject)  = 0;
    virtual void handleCollision(Ladder& gameObject) = 0;
};
