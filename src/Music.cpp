#pragma once
#include "Music.h"
/*
SoundClass::SoundClass()
{
	loadSoundAudio();
}*/
Music::Music()
{
	m_music.openFromFile("music.wav");
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
}

void Music::stopMusic()
{
	m_music.stop();
}

void Music::pauseMusic()
{
	m_music.pause();
}
