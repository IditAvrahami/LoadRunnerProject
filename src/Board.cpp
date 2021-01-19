#include "Board.h"
#include "Enemy.h"
#include "Object.h"
#include "Coin.h"
#include "ScorePresent.h"
#include "TimePresent.h"
#include "LivePresent.h"
#include "BadPresent.h"
#include "Ladder.h"
#include "Floor.h"
#include "Rod.h"
#include "SmartEnemy.h"
#include "RandomEnemy.h"
#include "HorizontalEnemy.h"
#include "StaticObject.h"
#include "Utillities.h"
#include "MovingObject.h"
#include "Movment.h"
#include "Timer.h"
#include <string>
#include <vector>
#include<typeinfo>


Board::Board() : m_height(0), m_width(0)  //std::string levelName, const int level)
{	
	srand(time(NULL));
	
	// play button and background
	// kind of enemeis
	
	m_pictures.resize(OBJECTS);

	m_pictures[0].loadFromFile("candy.png");

	m_pictures[1].loadFromFile("manC.png");

	m_pictures[2].loadFromFile("ladder.png");

	m_pictures[3].loadFromFile("coin.png");

	m_pictures[4].loadFromFile("floor.png");

	m_pictures[5].loadFromFile("rod.png");

	m_pictures[6].loadFromFile("candyWorld.png");

	m_picturesSprite.resize(OBJECTS);
	for (int i = 0; i < OBJECTS; i++)
	{
		m_picturesSprite[i] = sf::Sprite(m_pictures[i]);
	}
	m_backGroundPng.setTexture(m_pictures[6]);
	//Player::instance().setSprite(m_pictures[0]);
	//m_player.setSprite(m_pictures[0]);
	Player::instance().setSpeed(150);
//	m_player.setSpeed(150);
	
}

void Board::loadBoardFromController(std::string levelName,const int level)
{
	loadBoard(levelName, level);
	m_backGroundPng.setScale(0.029, 0.039);
	m_backGroundPng.scale(m_height, m_width);
}

void Board::handleGravity(MovingObject* movable)
{
	Movment movment;
	sf::Time time = sf::milliseconds(3);

	if (typeid(*movable) == typeid(HorizontalEnemy))
	{
		return;
	}
	
	bool needFix = false;
	while (!handleCollisions(*movable))
	{
		needFix = true;
		(*movable).gravityFunction();
	}
	if (needFix)
		(*movable).moveLocation(KB_UP, time);

}

std::unique_ptr<Present> Board::kindOfPresent()
{
	int number = rand() % NUMBER_OF_PRESENT;

	switch (number)
	{
	case 0:
		return std::make_unique<ScorePresent>(m_picturesSprite[0]); // now is present
		break;
	case 1:
		return std::make_unique<TimePresent>(m_picturesSprite[0]);
		break;
	case 2:
		return std::make_unique<BadPresent>(m_picturesSprite[0]); 
		break;
	case 3:
		return std::make_unique<LivePresent>(m_picturesSprite[0]); 
		break;
	}
//	return std::unique_ptr<Present>();
}

std::unique_ptr<Enemy> Board::kindOfEnemy(const int type)
{
	switch (type)
	{
	case 0:
		return std::make_unique<SmartEnemy>(m_picturesSprite[1], 60);
		break;
	case 1:
		return std::make_unique<HorizontalEnemy>(m_picturesSprite[1], 60);
		break;

	}
	return std::make_unique< RandomEnemy >(m_picturesSprite[1], 60);
}


void Board::move(sf::Time& time)
{
	Player::instance().move(time);
	handleCollisions(Player::instance());
	handleGravity(&Player::instance());

	for (int i = 0; i < m_enemy.size(); i++)
	{
		m_enemy[i]->move(time);
		handleCollisions(*m_enemy[i]);
		handleGravity(m_enemy[i].get()); // return regular pointer to enemy
	}
	handleCollisionsEnemy(Player::instance());
	updatePointersInBoard();
}

void Board::handleCollisionsEnemy(Player& player)
{
	for (auto& movable : m_enemy)
	{
		if (player.checkCollision(movable->getGlobalBounds()))
		{
			player.handleCollision(*movable);
		}
	}
}

bool Board::handleCollisions(Object& gameObject)
{
	bool colid = false;
	for (int i=0; i < m_height ; i++)
	{
		for (int j=0 ; j < m_width ; j++)
		{
			if (m_board[i][j])
			{
				if (gameObject.checkCollision(m_board[i][j]->getGlobalBounds()))
				{
					gameObject.handleCollision(*m_board[i][j]);
					colid = true;
				}
			}
		}
	}
	return colid;
}

void Board::updatePointersInBoard()
{
	for (size_t i = 0; i < m_height; i++)
	{
		for (size_t j = 0; j < m_width; j++)
		{
			if (m_board[i][j])
			{
				if (m_board[i][j]->getLocation().x == -1 && m_board[i][j]->getLocation().y == -1)
				{
					if (typeid(*m_board[i][j]) == typeid(Floor))
					{	
						Floor* floor = dynamic_cast<Floor*>(m_board[i][j].get()); // get regular pointer to floor(floor kind)
						floor->appear(sf::Sprite(m_picturesSprite[4]));
					}
					else if (typeid(*m_board[i][j]) == typeid(Coin))
					{
						m_board[i][j] = nullptr; // point to null 
						m_coinsCounter--;
					}
					else 
					{
						m_board[i][j] = nullptr; // point to null 
					}
				}
			}
		}
	}
}

Board& Board::boardObject()
{
	static Board boardObject;
	return boardObject;
}

std::vector<std::vector<StaticObject*>> Board::getBoard() const
{
	std::vector<std::vector<StaticObject*>> tempBoard;
	tempBoard.resize(m_height);
	for (size_t i = 0; i < m_height; i++)
	{
		tempBoard[i].resize(m_width);
	}

	for (size_t i = 0; i < m_height; i++)
	{
		for (size_t j = 0; j < m_width; j++)
		{
			tempBoard[i][j] = m_board[i][j].get(); // return normall pointer
		}
	}

	return tempBoard;
}

int Board::getLives()
{
	return Player::instance().getLives();
}


std::unique_ptr<StaticObject> Board::createObject(const char tosprite, const int level)
{
	switch (tosprite)
	{
	case 'H':
		return std::make_unique<Ladder>(m_picturesSprite[2]);
		break;
	case '*':
		m_coinsCounter = m_coinsCounter + 1;
		return std::make_unique<Coin>(m_picturesSprite[3], level);
		break;
	case '#':
		return std::make_unique<Floor>(m_picturesSprite[4]);
		break;
	case '-':
		return std::make_unique<Rod>(m_picturesSprite[5]);
		break;
	case '+':
		return  kindOfPresent();   //std::make_unique<Present>(m_picturesSprite[7]);
		break;
	}
		return std::unique_ptr<StaticObject>(nullptr);
}

void Board::playerSetDirection(sf::Keyboard::Key direction)
{
	Player::instance().setDirection(direction);
}

void Board::loadBoardFromFile(const int level)
{
	algorithmOfEnemy();

	string str;
	getline(m_fileRead, str); //read enter
	for (int i = 0; i < m_height; i++)
	{
		getline(m_fileRead, str);
		for (int j = str.size() - 1; j >= 0; j--) // insert to the vector the board
		{
			if (str[j] == '@')
			{
				Player::instance().setLocation(i, j);
			}
			else if (!(str[j] == '@') && !(str[j] == '%'))
			{
				m_board[i][j] = createObject(str[j], level);
				if (str[j] != ' ')
					m_board[i][j]->setLocation(i, j);
			}
			else // is enemy
			{
				m_enemy.push_back(kindOfEnemy(m_enemyType));
				m_enemy[m_enemy.size() - 1]->setLocation(i, j);
			}
		}
	}
}



void Board::pointToNull()
{
	for (size_t i = 0; i < m_height; i++)
	{
		for (size_t j = 0; j < m_width; j++)
		{
			m_board[i][j] = nullptr;
		}
	}
}

bool Board::loadBoard(std::string levelName, const int level)
{
	int time;
	m_fileRead.open(levelName);
	if (!m_fileRead.is_open())
		return false;
	
	m_fileRead >> m_height >> m_width >> time;
	Timer::instance().setTimer(time);
	Player::instance().updateFont();
	//m_backGroundPng.scale(1 / m_width, 1 / m_height); // change background size
	m_time = sf::seconds((float)time);
	createBoard();
	loadBoardFromFile(level);
	m_fileRead.close();

	return true;
}

void Board::createBoard()
{
	m_board.resize(m_height);
	for (size_t i = 0; i < m_height; i++)
	{
		m_board[i].resize(m_width);
	}
	pointToNull();
}

void Board::algorithmOfEnemy()
{
	m_enemyType = 1;
	//m_enemyType = rand() % 3;
}

int Board::getTypeOfEnemy() const
{
	return m_enemyType;
}

int Board::getNumberOfCoins()
{
	return m_coinsCounter;
}


void Board::createObjectVector()
{
	m_board.resize(m_height);
	for (int i = 0; i < m_height; i++)
		m_board[i].resize(m_width); // board of vectors
}

int Board::getHeight()
{
	return m_height;
}

int Board::getWidth()
{
	return m_width;
}

void Board::print(sf::RenderWindow& window)
{
	window.draw(m_backGroundPng);
	
	for (int i = 0; i < m_height; i++)
		for (int j = 0; j < m_width; j++)
		{
			if (i == 3 && j == 14)//////////////////////////////////////
				int a = 5;
			if (m_board[i][j])
				m_board[i][j]->print(window);
		}
	for (int i = 0; i < m_enemy.size(); i++)
	{
		m_enemy[i]->print(window);
	}
	if(Timer::instance().getTimer() != -1)
	Timer::instance().print(window);
	Player::instance().print(window);
}

void Board::addEnemy()
{
	int index;
	Enemy newEnemy(m_picturesSprite[1], 60); // create new enemy
	m_enemy.push_back(kindOfEnemy(m_enemyType)); // get pointer to kind of enemy
	sf::Vector2f vector = findGoodPlace();
	vector.x *= COMPARISON;
	vector.y *= COMPARISON;
	index = m_enemy.size();
	m_enemy[index]->setLocation(vector.y, vector.x);
}

sf::Vector2f Board::findGoodPlace()
{
	for (size_t i = 0; i < m_height; i++)
	{
		for (size_t j = 0; j < m_width; j++)
		{
			if (!m_board[i][j]) // if not null
			{
				if (m_board[i + 1][j])
				{
					i++;
					return sf::Vector2f((float)j, (float)i);
				}
			}
		}
	}
	return sf::Vector2f(0.f, 0.f);
}

void Board::clearVectors()
{
	m_coinsCounter = 0;
	m_enemy.clear();
	for (size_t i = 0; i < m_height; i++)
	{
		m_board[i].clear();
	}
}

