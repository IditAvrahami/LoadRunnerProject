#pragma once
#include "Board.h"
#include "Coin.h"
#include "Present.h"
#include <SFML/Graphics.hpp>
#include "Player.h"
#include <string>
#include <memory>
#include <vector>

class Controller
{
public:
	Controller(); // ctor
	virtual ~Controller() =default;
	void openScreen(); // open new window with hei wid
	void startGame();
	void menupage();
	void failed();

private:
	//private functions
	std::string levelName();
	sf::Texture m_start;
	sf::Sprite m_startPng;
	sf::Texture m_end;
	sf::Sprite m_endPng;
	sf::Texture m_backGround;
	sf::Sprite m_backGroundPng;
	//private members
	int m_level = 0;
	sf::RenderWindow m_window;

};