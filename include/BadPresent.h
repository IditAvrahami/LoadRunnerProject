#pragma once
#include "Present.h"
#include <SFML/System/Vector2.hpp>

class Player;
class Enemy;
class Board;

class BadPresent : public Present
{
public:
	BadPresent(sf::Sprite picture);
	virtual ~BadPresent()=default;
	virtual bool checkCollision(const sf::FloatRect& floatRect) const override;
	virtual void handleCollision(Object& obj)override;
	virtual void handleCollision(Player& gameObject)override;
	virtual void handleCollision(Enemy& gameObject) override; // empy func
	virtual void handleCollision(Present& gameObject) override;// empy func
	virtual void handleCollision(Coin& gameObject)override;// empy func
	virtual void handleCollision(Floor& gameObject) override;// empy func
	virtual void handleCollision(Rod& gameObject) override;// empy func
	virtual void handleCollision(Ladder& gameObject)override;// empy func
private:

};
