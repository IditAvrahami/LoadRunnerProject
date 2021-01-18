#pragma once
#include <SFML/Graphics.hpp>


class Timer
{
public:
	
	virtual ~Timer() = default;
	int getTimer()const;
	void setTimer(const int );
	void addTime();
	//void resetTimer();
	bool ifEndTime()const;
	static Timer& instance(); // return the single timer object

private:
	Timer();
	//int m_timer = 0;
	sf::Time m_time;
	sf::Clock m_clock;
	sf::Text m_timerText;
	sf::Font m_font;
	// int m_initTimer;
};
