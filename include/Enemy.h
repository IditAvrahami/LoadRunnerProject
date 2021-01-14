#pragma once
#include <SFML/Graphics.hpp>
#include "MovingObject.h"
#include "Utillities.h"
#include <iostream>
#include <ostream>
#include "Player.h"
#include "Movment.h"
//#include "Board.h"

class Coin;
class Present;
class Floor;
class Rod;
class Ladder;


class Enemy : public MovingObject
{
public:

    Enemy(sf::Sprite picture, const int speed);
    virtual ~Enemy() = default;
    virtual void setLocation(const float y, const float x);
    void moveLocation(const sf::Vector2f& d, sf::Time t);
    virtual void print(sf::RenderWindow& window);
    virtual void move(const sf::Time& time)override;
    virtual void gravityFunction();
    virtual sf::Sprite getSprite();
    virtual sf::Vector2f getLocation()const override;
    virtual void setSpeed(const int)override;
    virtual int getSpeed()override;
    sf::Vector2f getDirection();
    virtual bool checkCollision(const sf::FloatRect& floatRect) const;
    virtual sf::FloatRect getGlobalBounds() const;
    virtual void handleCollision(Object& obj)override;
    virtual void handleCollision(Player& gameObject)override;
    virtual void handleCollision(Coin& gameObject) override {};
    virtual void handleCollision(Present& gameObject) override {};
    virtual void handleCollision(Enemy& gameObject)override {};
    virtual void handleCollision(Floor& gameObject) override;
    virtual void handleCollision(Rod& gameObject) override; // chage angel?? or picture??
    virtual void handleCollision(Ladder& gameObject)override; // chage angel?? or picture??

private:
    sf::Sprite m_enemyPng;
    sf::Vector2f m_direction;
    int m_speed;
};
