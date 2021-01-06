#pragma once
#include <SFML/Graphics.hpp>
#include "Utillities.h"

class Object
{
public:
    Object()=default;
    virtual ~Object()= default;
    virtual void print(sf::RenderWindow& window)=0;
    virtual void setLocation(const float y, const float x)=0;
};
