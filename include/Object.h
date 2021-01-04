#pragma once
#include <SFML/Graphics.hpp>

class Object
{
public:
    Object();
    virtual ~Object()= default;
    virtual void print(sf::RenderWindow& window)=0;
    virtual sf::Sprite getSprite() = 0;
    virtual void setLocation(const int row, const int col)=0;
};
