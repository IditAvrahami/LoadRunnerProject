#pragma once
#include <vector>
#include <fstream>
#include <iostream>
#include <memory>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Texture.hpp>
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
#include "Utillities.h"
#include "MovingObject.h"


using std::ifstream;
using std::string;
using std::unique_ptr;
using sf::RenderWindow;

class Board
{
public:
//	Board(std::string levelName, const int level); in private to singelton
	virtual ~Board()=default;
	void loadBoardFromFile(const int level);
	bool loadBoard(std::string levelName, const int level);
	int algorithmOfEnemy();  
	int getNumberOfCoins();
	void print(sf::RenderWindow &window);
	void createBoard();
	void pointToNull();
	void createObjectVector();
	std::unique_ptr<StaticObject> createObject(const char, const int);
	std::unique_ptr<Enemy>kindOfEnemy(const int type);
	int getHeight();
	int getWidth();
	void playerSetDirection(sf::Keyboard::Key  );
	void move(sf::Time&);
	int getLives();
	void handleCollisionsEnemy(Player& player);
	void handleCollisions(Object& gameObject);
	void updatePointersInBoard();
	static Board& boardObject();
	std::vector<std::vector<StaticObject*>> getBoard()const;
	void loadBoardFromController(std::string levelName, const int level);

private:
	Board();//std::string levelName, const int level);
	int m_height; //read from file
	int m_width;
	int m_coinsCounter=0;
	ifstream m_fileRead;
	sf::Time m_time;
	std::vector<std::vector<std::unique_ptr<StaticObject>>> m_board;
	std::vector <sf::Texture> m_pictures;
	std::vector <sf::Sprite> m_picturesSprite;
	sf::Sprite m_backGroundPng;
	std::vector <std::unique_ptr <Enemy>> m_enemy; 
	Player m_player;
};
