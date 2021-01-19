#pragma once
#include "Timer.h"
#include "Board.h"


Timer::Timer() 
{
	
	int width = Board::boardObject().getWidth();
	int height = Board::boardObject().getHeight();
	/*m_timerPic.loadFromFile("timer.png");
	m_timerPng = sf::Sprite(m_timerPic);
	m_timerPng.setPosition(width*COMPARISON-40, height*COMPARISON + 50);
	*/
	m_font.loadFromFile("resources/sansation.ttf");
	m_timerText.setFont(m_font);
	m_timerText.setCharacterSize(50);
	m_timerText.setPosition((float)((width - 3) * COMPARISON), (float)((height) * COMPARISON));
	m_timerText.setFillColor(sf::Color::White);
}

int Timer::getTimer() const
{
	return m_timerInt;
}

void Timer::setTimer(const int time)
{
	m_clock.restart(); //start the timer
	m_timerInt = time;
}

void Timer::addTime()
{
	m_timerInt += 10;
}

bool Timer::ifPastSecond()
{
	sf::Time timePassed = m_clock.getElapsedTime();
	if (timePassed.asSeconds() > 1)
	{
		m_clock.restart();
		return true;
	}
	return false;
}

void Timer::updateTimer()
{
	if (ifPastSecond())
		m_timerInt--;
}

bool Timer::ifEndTime() const
{
	
	if (m_timerInt == 0)
		return true;
	return false;
}

Timer& Timer::instance()
{
	static Timer timer;
	return timer;
}

void Timer::print(sf::RenderWindow& window)
{
	m_timerText.setString(std::to_string(m_timerInt));
	window.draw( m_timerText);
	//window.draw(m_timerPng);
}

