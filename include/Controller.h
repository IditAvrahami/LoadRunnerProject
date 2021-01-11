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
	void openScreen(int heigth, int width); // open new window with hei wid
	void startGame();
	//void print();
	//	void printAndClearBoard();
/*	int getLives();
	int getLevel();
	int getScore();
	int getTime();
	void setLives();
	void setLevel();
	void setScore();
	void setTime();
	*/
	

private:
	//private functions
	std::string levelName();

	//private members
//	std::vector <std::unique_ptr <Enemy>> m_enemy; // check what to do
//	Player m_player;
//	int m_lives=0;            move tp player
	int m_level=0;
//	int m_score=0;            move to player
	Board m_board;
	sf::RenderWindow m_window;
	//sf::clock m_time;
	//std::vector <Coin> m_coins;
	//std::vector <Present> m_presents; // location of the present and kind
};