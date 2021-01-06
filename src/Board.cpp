#include "Board.h"
#include <string>
#include <vector>

Board::Board(std::string levelName)
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
	m_player.setSpeed(50);
	
	loadBoard(levelName); 
	m_backGroundPng.setScale(0.029, 0.041);
	m_backGroundPng.scale(m_height, m_width);
	
}


std::unique_ptr<Enemy> Board::kindOfEnemy(const int type)
{
	switch (type)
	{
	case 0:
		return std::make_unique<SmartEnemy>(m_picturesSprite[1], 40);
		break;
	case 1:
		return std::make_unique<HorizontalEnemy>(m_picturesSprite[1], 40);
		break;

	}
	return std::make_unique< RandomEnemy >(m_picturesSprite[1], 40);
}


void Board::move(sf::Time& time)
{
	m_player.move(time);
		for (int i = 0; i < m_enemy.size(); i++)
			m_enemy[i]->move(time);
}

std::unique_ptr<StaticObject> Board::createObject(const char tosprite)
{
	switch (tosprite)
	{
	case 'H':
		return std::make_unique<Ladder>(m_picturesSprite[2]);
		break;
	case '*':
		m_coinsCounter = m_coinsCounter + 1;
		return std::make_unique<Coin>(m_picturesSprite[3]);
		break;
	case '#':
		return std::make_unique<Floor>(m_picturesSprite[4]);
		break;
	case '-':
		return std::make_unique<Rod>(m_picturesSprite[5]);
		break;
	//	case '+':
	//		return std::make_unique<Present>(m_pictures[6]);
	//		break;
			//add present case
		}
		return std::unique_ptr<StaticObject>(nullptr);
	}

void Board::playerSetDirection(sf::Keyboard::Key direction)
{
	m_player.setDirection(direction);
}
void Board::loadBoardFromFile()
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
				m_board[i][j] = createObject(str[j]);
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

bool Board::loadBoard(std::string levelName)
{
	int time;
	m_fileRead.open(levelName);
	if (!m_fileRead.is_open())
		return false;

	m_fileRead >> m_height >> m_width >> time;
	m_time = sf::seconds((float)time);
	createBoard();
	loadBoardFromFile();
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

bool Board::isGoodMove(const MovingObject& play) const
{
	return false;
}

bool Board::isGoodMove(const StaticObject &play, const int direction)const
{
//	int x;
//	int y;
	/// <summary>
	/// //////////////////////////////////////////////////////////////////////////////////
	/// </summary>
	/// <param name="play"></param>
	/// <param name="direction"></param>
	/// <returns></returns>
	return false;
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