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


Board::Board() : m_height(0), m_width(0)  
{	
	srand(time(NULL));
	
	m_pictures.resize(OBJECTS);

	m_pictures[0].loadFromFile("candy.png");

	m_pictures[1].loadFromFile("manC.png");
//	m_pictures[1].loadFromFile("sinagot.png");

	//m_pictures[2].loadFromFile("ladder.png");
	m_pictures[2].loadFromFile("ladder3.png");

	m_pictures[3].loadFromFile("coin.png");

	m_pictures[4].loadFromFile("floor.png");

	m_pictures[5].loadFromFile("newRod.png");

	m_pictures[6].loadFromFile("candyWorld.png");

	m_picturesSprite.resize(OBJECTS);
	for (int i = 0; i < OBJECTS; i++)
	{
		m_picturesSprite[i] = sf::Sprite(m_pictures[i]);
	}
	m_backGroundPng.setTexture(m_pictures[6]);

	m_player.setSpeed(150);
//	Player::instance().setSpeed(150);
	
}

void Board::loadBoardFromController(std::string levelName,const int level)
{
	loadBoard(levelName, level);
	m_backGroundPng.setScale(0.029, 0.039); /// do the calculate
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
	int number;
	if(Timer::instance().getTimer() == -1 )
	 number = rand() % (NUMBER_OF_PRESENT-1);
	else
		 number = rand() % NUMBER_OF_PRESENT;

	switch (number)
	{
	case 0:
		std::cout << "score" << std::endl;
		return std::make_unique<ScorePresent>(m_picturesSprite[0]); // now is present		
		break;
	case 1:
		std::cout << "lives" << std::endl;
		return std::make_unique<LivePresent>(m_picturesSprite[0]);		
		break;
	case 2:
		std::cout << "badddd" << std::endl;
		return std::make_unique<BadPresent>(m_picturesSprite[0]); 
		break;
	case 3:
		std::cout << "time" << std::endl;
		return std::make_unique<TimePresent>(m_picturesSprite[0]);
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
	m_player.move(time);
	//Player::instance().move(time);
	handleCollisions(m_player);
	handleGravity(&m_player);

	for (int i = 0; i < m_enemy.size(); i++)
	{
		m_enemy[i]->move(time);
		handleCollisions(*m_enemy[i]);
		handleGravity(m_enemy[i].get()); // return regular pointer to enemy
	}
	handleCollisionsEnemy(m_player);
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
				if (typeid(*m_board[i][j]) == typeid(Floor))
				{
					Floor* floor = dynamic_cast<Floor*>(m_board[i][j].get()); // get regular pointer to floor(floor kind)
					floor->appear(sf::Sprite(m_picturesSprite[4]));
				}
				if (m_board[i][j]->getLocation().x == TO_DELETED.x && m_board[i][j]->getLocation().y == TO_DELETED.y)
				{
					if (typeid(*m_board[i][j]) == typeid(Coin))
					{
						m_board[i][j] = nullptr; // point to null 
						m_coinsCounter--;
					}
					else // if present
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

void Board::setLives(const int more)
{
	m_player.setLives(more);
}

int Board::getLives() // delete
{
	return m_player.getLives();
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

void Board::playerSetDirection(sf::Keyboard::Key direction) //to delete
{
	m_player.setDirection(direction);
//	Player::instance().setDirection(direction);
}

void Board::loadBoardFromFile(const int level)
{
	algorithmOfEnemy();
	int temp;
	string str;
	getline(m_fileRead, str); //read enter
	for (int i = 1; i < m_height - 1; i++)
	{
		getline(m_fileRead, str);
		for (int j = str.size()-1 ; j >= 0; j--) // insert to the vector the board
		{
			if (str[j] == '@')
			{
				//updateWndowPosition
				m_player.setLocation(i, j + 1);
				//Player::instance().setLocation(i , j+1);
			//	Player::instance().setLocation(i-1, j+1);
			}
			else if (!(str[j] == '@') && !(str[j] == '%'))
			{
				//temp = j + 1;
				m_board[i][j+1] = createObject(str[j], level);
				//updateWndowPosition
				if(str[j] == 'H')
					m_board[i][j + 1]->setLocation(i , j + 1 + 0.25);
				else if (str[j] != ' ')
					m_board[i][j+1]->setLocation(i, j+1);
			}
			else // is enemy
			{
				//updateWndowPosition
				m_enemy.push_back(kindOfEnemy(m_enemyType));
				m_enemy[m_enemy.size() - 1]->setLocation(i, j+1);
			}
		}
	}
	doBounds();
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
	m_height += 2;
	m_width += 2;
	Timer::instance().setTimer(time);
	m_player.updateFont();
	//Player::instance().updateFont();
	
	m_time = sf::seconds((float)time); 
	createBoard();
	loadBoardFromFile(level);
	m_fileRead.close();

	return true;
}

void Board::createBoard()
{
	m_board.resize(m_height );
	for (size_t i = 0; i < m_height; i++)
	{
		m_board[i].resize(m_width);
	}
	pointToNull();
}

void Board::algorithmOfEnemy()
{
//	m_enemyType = 2;
	m_enemyType = rand() % 3;
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
	
	for (int i = 1; i < m_height-1; i++)
		for (int j = 1; j < m_width-1; j++)
		{
			if (m_board[i][j])
				m_board[i][j]->print(window);
		}
	for (int i = 0; i < m_enemy.size(); i++)
	{
		m_enemy[i]->print(window);
	}
	if(Timer::instance().getTimer() != -1)
	Timer::instance().print(window);
	m_player.print(window);
	//Player::instance().print(window);
}

void Board::addEnemy()
{
	Enemy newEnemy(m_picturesSprite[1], 60); // create new enemy
	m_enemy.push_back(kindOfEnemy(m_enemyType)); // get pointer to kind of enemy
	sf::Vector2f vector = findGoodPlace();
	int index = m_enemy.size()-1;
	m_enemy[index]->setLocation(vector.y, vector.x);
}

sf::Vector2f Board::findGoodPlace()
{
	Movment move;
	int row, col;
	row = m_height - 1;
	col = m_width - 1;
	for (size_t i = 1; i < row; i++)
	{
		for (size_t j = 1; j < col ; j++)
		{
			if(move.isFloor(i, j))
			{
				if (!m_board[i - 1][j])
				{
					i--;
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

void Board::doBounds()
{
	for (size_t i = 0; i < m_height; i++)
	{
		for (size_t j = 0; j < m_width; j++)
		{
			if (i == 0 || i == (m_height - 1))
			{
				m_board[i][j] = createObject('#', 0);
				m_board[i][j]->setLocation(i, j);
			}
			else if (j==0 || j == (m_width - 1))
			{
				m_board[i][j] = createObject('#', 0);
				m_board[i][j]->setLocation(i, j);
			}
		}
	}
}

sf::Vector2f Board::getPlayerLocation() const
{
	return m_player.getLocation();
}

Player Board::getPlayer() const
{
	return m_player;
}


