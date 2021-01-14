#include "SoundClass.h"


void SoundClass::loadSoundAudio()
{
	m_gameSound.openFromFile("newVolume.mp3");
}

SoundClass::SoundClass()
{
	loadSoundAudio();
}