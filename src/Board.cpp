#include "Board.h"
#include <string>
#include <vector>

Board::Board(std::string levelName, Player& player, std::vector <std::unique_ptr <Enemy>>& enemyArray)
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

	//m_pictures[6].loadFromFile("present.png");

	//	m_pictures[7].loadFromFile("forest.png");
	// ( m_pictures[0] );
	
	loadBoard(levelName,player,enemyArray);
}

void Board::loadBoardFromFile(Player& player, std::vector <std::unique_ptr <Enemy>>& enemyArray)
{
	int enemyKind = algorithmOfEnemy();
	
	//enemyArray.resize(0);
	string str;
	getline(m_fileRead, str); //read enter
	for (int i = 0; i < m_height; i++)
	{
		getline(m_fileRead, str);
		for (int j = str.size()-1; j >= 0; j--) // insert to the vector the board
		{
			if (str[j] == '@')
			{ 
				player.setSprite(m_pictures[1]);
				player.setLocation(i, j);
			}
			else if (!(str[j] == '@') && !(str[j] == '%'))
			{
				m_board[i][j] = createObject(str[j]);
				if(str[j] != ' ')
				m_board[i][j]->setLocation(i, j);
			}
			else // is enemy
			{
				//enemyArray.resize(enemyArray.size());
				enemyArray.push_back(kindOfEnemy(enemyKind));
				enemyArray[enemyArray.size() - 1]->setLocation(i, j);
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

bool Board::loadBoard(std::string levelName,Player& player, std::vector <std::unique_ptr <Enemy>>& enemyArray)
{
	int time;
	m_fileRead.open(levelName);
	if (!m_fileRead.is_open())
		return false;

	m_fileRead >> m_height >> m_width >> time;
	m_time = sf::seconds((float)time);
	createBoard();
	loadBoardFromFile(player, enemyArray);
	//createBoard();
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
	return rand() % 3; // daniel you see that????
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

std::unique_ptr<StaticObject> Board::createObject(const char tosprite)
{
	switch (tosprite)
	{
	case 'H':
		return std::make_unique<Ladder>(m_pictures[2]);
		break;
	case '*':
		m_coinsCounter = m_coinsCounter+1;
		return std::make_unique<Coin>(m_pictures[3]);
		break;
	case '#':
		return std::make_unique<Floor>(m_pictures[4]);
		break;
	case '-':
		return std::make_unique<Rod>(m_pictures[5]);
		break;
	/*case '+':
		return std::make_unique<Present>(m_pictures[6]);
		break;
		//add present case*/
	}
	return std::unique_ptr<StaticObject>(nullptr);
}

std::unique_ptr<Enemy> Board::kindOfEnemy(const int type)
{
	switch (type)
	{
	case 0:
		return std::make_unique<SmartEnemy>(m_pictures[1], 1);
		break;
	case 1:
		return std::make_unique<HorizontalEnemy>(m_pictures[1], 1);
		break;

	}
	return std::make_unique< RandomEnemy >(m_pictures[1], 1);
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
	for (int i = 0; i < m_height; i++)
		for (int j = 0; j < m_width; j++)
			if (m_board[i][j])
				m_board[i][j]->print(window);
	a.setTexture(m_pictures[5]);
	a.setPosition(0, 0);
	window.draw(a);
}