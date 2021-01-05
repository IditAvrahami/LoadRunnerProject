#pragma once
#include <vector>
#include <fstream>
#include <iostream>
#include <memory>
#include <SFML/Graphics.hpp>
#include "Object.h"
#include "Coin.h"
#include "Present.h"
#include "Enemy.h"
#include "Player.h"
#include "Ladder.h"
#include "Floor.h"
#include "Rod.h"
#include "SmartEnemy.h"
#include "RandomEnemy.h"
#include "HorizontalEnemy.h"
#include "StaticObject.h"

const int OBJECTS = 6; // change it with backgroud and play buttom

using std::ifstream;
using std::string;
using std::unique_ptr;

const int KB_UP = 72;
const int KB_DOWN = 80;
const int KB_LEFT = 75;
const int KB_RIGHT = 77;

class Board
{
public:
	Board(std::string levelName, Player& player, std::vector <Enemy>& enemyArray);
	virtual ~Board()=default;
	//void updateBoard(); // update all changes on board
	void loadBoardFromFile(Player& player, std::vector <Enemy>& enemyArray);
	bool loadBoard(std::string levelName, Player& player, std::vector <Enemy>& enemyArray); //  get the file and read the level to vector
	bool isGoodMove(const MovingObject& play)const; // check if is not floor the player can dig
	bool isGoodMove(const StaticObject& play, const int direction)const;
	int algorithmOfEnemy(); // 
	int getNumberOfCoins();
	int getNumberOfPresents();
	void createObjectVector();
	std::unique_ptr<StaticObject> createObject(const char);
	std::unique_ptr<Enemy>kindOfEnemy(const int type);

private:
	
	int m_height; //read from file
	int m_width;
	int m_coinsCounter=0;
	ifstream m_fileRead;
	sf::Time m_time;
	std::vector<std::vector<std::unique_ptr<StaticObject>>> m_board;
	//std::vector <Coin> m_coins;
	//std::vector <Present> m_presents; // location of the present and kind
	std::vector <sf::Texture> m_pictures;
};
