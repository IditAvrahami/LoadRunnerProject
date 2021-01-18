#pragma once

class Music
{
public:
	virtual ~ Music()= default ; // close music file
	static Music& instance();
	void startMusic();
	void stopMusic();
	 
private:
	Music(); // open music file
	sf::Music m_music;
};
