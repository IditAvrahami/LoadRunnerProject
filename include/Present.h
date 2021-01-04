#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include "Object.h"


class Present : public StaticObject
{
public:
    Present();
    virtual ~Present() = default;
    
 //   void badPresent();
 //   void livesPresent();
 //   void timePresent();
 //   void scorePresent();
 //   void slowerEnemyPresent();
 //   void ghostEnemyPresent();
    virtual void putPresentOnBoard();
    virtual void findAllPresent();
    virtual void setPresent();
    //void setPresent();
    virtual sf::Sprite getSprite();
    virtual void setLocation(const int y, const int x);
private:
    sf::Sprite m_presentPng;
};
