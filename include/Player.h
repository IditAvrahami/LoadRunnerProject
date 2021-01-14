#pragma once
#include <SFML/Graphics.hpp>
#include "MovingObject.h"
#include "Utillities.h"
#include <iostream>
#include <ostream>
#include "Enemy.h"
#include "Coin.h"
#include "Movment.h"
//#include "Board.h"

class Board;
class Present;
class Floor;
class Rod;
class Ladder;

class Player : public MovingObject
{
public:
    Player() {};
    Player(sf::Sprite picture, const int speed);
    Player(sf::Sprite picture);
    virtual ~Player() =default;
    virtual void setLocation(const float y, const float x)override;
    virtual sf::Vector2f getLocation()const override;
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
    void setScore(const int more);
    int getScore();
    void setLastScore();
    void lastScoreUpdateLose();
    void setLives(const int more);
    int getLives();
    virtual void setDirection(sf::Keyboard::Key);
    void changeface(bool toRight);
    virtual bool checkCollision(const sf::FloatRect& floatRect) const override;
    virtual sf::FloatRect getGlobalBounds() const override;
    virtual void handleCollision(Object& obj)override;
    virtual void handleCollision(Player& gameObject)override {};
    virtual void handleCollision(Coin& gameObject) override;
    virtual void handleCollision(Present& gameObject) override;////////////////////////////////////////////////////////////
    virtual void handleCollision(Floor& gameObject)override;
    virtual void handleCollision(Enemy& gameObject)override;
    virtual void handleCollision(Rod& gameObject) override; // chage angel?? or picture??
    virtual void handleCollision(Ladder& gameObject)override;// chage angel?? or picture??
    virtual void gravityFunction()override;
    void moveLocation(const sf::Vector2f& direction, sf::Time time)override;

private:
        sf::Sprite m_playerPng;
        int m_speed=1;
        int m_lives = 3;
        int m_score = 0;
        int m_lastScore = 0;
        sf::Vector2f m_direction;
        sf::Vector2f m_lastDirection;
};
