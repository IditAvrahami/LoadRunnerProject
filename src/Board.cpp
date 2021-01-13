#include "Board.h"
#include <string>
#include <vector>
#include<typeinfo>


Board::Board() : m_height(0), m_width(0)  //std::string levelName, const int level)
{	
	srand(time(NULL));

	// play button and background
	// kind of enemeis
	
	m_pictures.resize(OBJECTS);

	m_pictures[0].loadFromFile("player.png");

	m_pictures[1].loadFromFile("enemy.png");

	m_pictures[2].loadFromFile("ladder.png");

	m_pictures[3].loadFromFile("coin.png");

	m_pictures[4].loadFromFile("floor.png");

	m_pictures[5].loadFromFile("rod.png");
	//change size of object

	m_pictures[6].loadFromFile("candyWorld.png");
	//m_pictures[7].loadFromFile("present.png");

	m_picturesSprite.resize(OBJECTS);
	for (int i = 0; i < OBJECTS; i++)
	{
		m_picturesSprite[i] = sf::Sprite(m_pictures[i]);
	}
	m_backGroundPng.setTexture(m_pictures[6]);
	m_player.setSprite(m_pictures[0]);
	m_player.setSpeed(150);
	
//	loadBoard(levelName, level); 
//	m_backGroundPng.setScale(0.029, 0.041);
//	m_backGroundPng.scale(m_height, m_width);
	
}

void Board::loadBoardFromController(std::string levelName,const int level)
{
	loadBoard(levelName, level);
	m_backGroundPng.setScale(0.029, 0.041);
	m_backGroundPng.scale(m_height, m_width);
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
	handleCollisions(m_player);
	
	for (int i = 0; i < m_enemy.size(); i++)
	{
		m_enemy[i]->move(time);
		handleCollisions(*m_enemy[i]);
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

void Board::handleCollisions(Object& gameObject)
{
	for (int i=0; i < m_height ; i++)
	{
		for (int j=0 ; j < m_width ; j++)
		{
			if (m_board[i][j])
			{
				if (gameObject.checkCollision(m_board[i][j]->getGlobalBounds()))
				{
					gameObject.handleCollision(*m_board[i][j]);
				}
			}
		}
	}
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
					if (typeid(*m_board[i][j]) == typeid(Coin))
					{
						m_coinsCounter--;
					}
					m_board[i][j] = nullptr; // point to null 
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
	//	case '+':
	//		return std::make_unique<Present>(m_pictures[7]);
	//		break;
			//add present case
	}
		return std::unique_ptr<StaticObject>(nullptr);
}

void Board::playerSetDirection(sf::Keyboard::Key direction)
{
	m_player.setDirection(direction);
}

void Board::loadBoardFromFile(const int level)
{
	int enemyKind = algorithmOfEnemy();

	string str;
	getline(m_fileRead, str); //read enter
	for (int i = 0; i < m_height; i++)
	{
		getline(m_fileRead, str);
		for (int j = str.size() - 1; j >= 0; j--) // insert to the vector the board
		{
			if (str[j] == '@')
			{
				m_player.setLocation(i, j);
			}
			else if (!(str[j] == '@') && !(str[j] == '%'))
			{
				m_board[i][j] = createObject(str[j], level);
				if (str[j] != ' ')
					m_board[i][j]->setLocation(i, j);
			}
			else // is enemy
			{
				m_enemy.push_back(kindOfEnemy(enemyKind));
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

int Board::algorithmOfEnemy()
{
	return rand() % 3;
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
			if (m_board[i][j])
				m_board[i][j]->print(window);
	for (int i = 0; i < m_enemy.size(); i++)
	{
		m_enemy[i]->print(window);
	}
	m_player.print(window);
}