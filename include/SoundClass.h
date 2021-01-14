#pragma once
#include <SFML/Audio.hpp>


//singelton class
class SoundClass
{
public:
	virtual ~SoundClass()= default;
	void loadSoundAudio();
	void startSound();
	void endSound();
	static SoundClass& getSoundPointer();

private:
	SoundClass();
	sf::sound m_gameSoundPointer;
	sf::SoundBuffer buffer;
	//sf::soundBuffer m_gameSound;
};
