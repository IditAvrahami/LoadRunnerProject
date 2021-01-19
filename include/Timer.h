#pragma once
#include <SFML/Graphics.hpp>
#include "utillities.h"

class Board;

class Timer
{
public:
	
	virtual ~Timer() = default;
	int getTimer()const;
	void setTimer(const int );
	void addTime();
//	void resetTimer();
	bool ifPastSecond();
	void updateTimer();
	bool ifEndTime()const;
	static Timer& instance(); // return the single timer object
	void print(sf::RenderWindow& window
	);
	
private:
	Timer();
	int m_timerInt = 0;
	//sf::Time m_boardTime;
	sf::Time m_timer;
	sf::Clock m_clock;
	sf::Text m_timerText; // for print
	sf::Font m_font;
	sf::Texture m_timerPic;
	sf::Sprite m_timerPng;
	// int m_initTimer;
};
