#pragma once
#include "Present.h"

class Player;

class TimePresent : public Present
{
public:
	TimePresent(sf::Sprite picture);
	virtual ~TimePresent()=default;
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
