#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include "StaticObject.h"
#include "Utillities.h"

class Player;
class Enemy;
class Coin;
class Present;
class Floor;
class Rod;
class Ladder;

class Present : public StaticObject
{
public:
    Present(sf::Sprite picture);
    virtual ~Present() = default;
    
 //   void badPresent();
 //   void livesPresent();
 //   void timePresent();
 //   void scorePresent();
 //   void slowerEnemyPresent();
 //   void ghostEnemyPresent();
    virtual sf::Sprite getSprite();
    virtual void print(sf::RenderWindow& window);
    virtual void setLocation(const float y, const float x)override;
	virtual sf::Vector2f getLocation()const override;
	virtual bool checkCollision(const sf::FloatRect& floatRect) const=0;
	virtual sf::FloatRect getGlobalBounds() const;
	virtual void handleCollision(Object& obj)=0;
	virtual void handleCollision(Player& gameObject)=0;
	virtual void handleCollision(Enemy& gameObject)=0;
	virtual void handleCollision(Present& gameObject)=0;
	virtual void handleCollision(Coin& gameObject)=0;
	virtual void handleCollision(Floor& gameObject) =0;
	virtual void handleCollision(Rod& gameObject) =0;
	virtual void handleCollision(Ladder& gameObject)=0;
protected:
	sf::Sprite m_presentPng;
private:
   
};
