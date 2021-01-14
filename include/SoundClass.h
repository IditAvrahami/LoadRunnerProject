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
	sf::Sound m_gameSoundPointer;
	sf::SoundBuffer buffer;
	sf::Music m_gameSound;
	//sf::soundBuffer m_gameSound;
};
