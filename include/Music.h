#pragma once
#include <SFML/Audio.hpp>

class Music
{
public:
	virtual ~ Music()= default ; // close music file
	static Music& instance();
	void startMusic();
	void stopMusic();
	void pauseMusic();
	void startWinMusic();
	void stopWinMusic();

private:
	Music(); // open music file
	sf::Music m_music;
	sf::Music m_win;
};
