#pragma once
#include "Music.h"

Music::Music()
{
	m_music.openFromFile("music.wav");
	m_win.openFromFile("nextLevel.wav");
}


Music& Music::instance()
{
	static Music music;
	return music;
}

void Music::startMusic()
{
	m_music.play();
	m_music.setLoop(true);
	m_music.setVolume((float)30);
}

void Music::stopMusic()
{
	m_music.stop();
}

void Music::pauseMusic()
{
	m_music.pause();
}

void Music::startWinMusic()
{
	m_win.play();
}

void Music::stopWinMusic()
{
	m_win.stop();
}
