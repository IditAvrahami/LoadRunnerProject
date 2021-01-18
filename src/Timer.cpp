#pragma once
#include "Timer.h"

int Timer::getTimer() const
{
	return m_timer;
}

void Timer::setTimer(const int time)
{
	m_timer = time;
//	m_initTimer = time;
}

void Timer::addTime()
{
	m_timer += 10;
}

bool Timer::ifEndTime() const
{
	if (m_timer == 0)
		return true;
	return false;
}

Timer& Timer::instance()
{
	static Timer timer;
	return timer;
}

void Timer::resetTimer()
{
}
