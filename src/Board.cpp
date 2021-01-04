#include "Board.h"
#include <string>
#include <vector>

Board::Board(std::string levelName, Player& player, std::vector <Enemy> enemyArray)
{ 
	srand(NULL);

	// play button and background
	// kind of enemeis
	
	m_pictures.resize(OBJECTS);

	m_pictures[0].loadFromFile("player.png");

	m_pictures[1].loadFromFile("enemy.png");

	m_pictures[2].loadFromFile("ladder.png");

	m_pictures[3].loadFromFile("coin.png");

	m_pictures[4].loadFromFile("floor.png");

	m_pictures[5].loadFromFile("rod.png");

//	m_pictures[6].loadFromFile("back.png");

	//	m_pictures[7].loadFromFile("download.png");

	loadBoard(levelName);
}

void Board::loadBoardFromFile(Player& player, std::vector <Enemy> enemyArray)
{
	int enemyKind = algorithmOfEnemy();
	string str;
	getline(m_fileRead, str); //read enter
	for (int i = 0; i < m_height; i++)
	{
		getline(m_fileRead, str);
		for (int j = str.size(); j >= 0; j--) // insert to the vector the board
		{
			if (str[j] == '@')
				player.setLocation(i, j);
			else if (!(str[j] == '@') && !(str[j] == '%'))
			{
				m_board[i].insert(m_board[i].begin(), createObject(str[j])); // insert pointer to object to array
				m_board[i][j].setLocation(i, j);
			}
			else // is enemy
				{
				enemyArray.push_back(kindOfEnemy(enemyKind));
			    }
			
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
	m_time = (sf::Vector2f)time; // convert int to time
	loadBoardFromFile(player, enemyArray);
	//createBoard();
	m_fileRead.close();

	return true;
}

bool Board::isGoodMove(const StaticObject &play, const int direction)const
{
	int x;
	int y;
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
	return rand() % 3; // daniel you see that????
}

int Board::getNumberOfCoins()
{
	return m_coinsCounter;
}

int Board::getNumberOfPresents()
{
	return m_presents.size();
}

void Board::createObjectVector()
{
	m_board.resize(m_height);
	for (int i = 0; i < m_height; i++)
		m_board[i].resize(m_width); // board of vectors
}

std::unique_ptr<Object> Board::createObject(const char tosprite) const
{
	switch (tosprite)
	{
	case 'H':
		return std::unique_ptr<Ladder>();
		break;
	case '*':
		m_coinsCounter++;
		return std::unique_ptr<Coin>();
		break;
	case '#':
		return std::unique_ptr<Floor>();
		break;
	case '-':
		return std::unique_ptr<Rod>();
		break;
	}
	return nullptr;
}

std::unique_ptr<Enemy> Board::kindOfEnemy(const int type)
{
	switch (type)
	{
	case 0:
		return std::unique_ptr<SmartEnemy>;
		break;
	case 1:
		return std::unique_ptr<HorizontalEnemy>;
		break;

	}
	return std::unique_ptr< RandomEnemy >;
}

