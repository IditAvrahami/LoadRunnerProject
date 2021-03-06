#pragma once
#include "Controller.h"
#include <SFML/Graphics.hpp>
#include <SFML/System/Clock.hpp>
#include "Timer.h"
#include "Music.h"


Controller::Controller() : m_level(1)
{
	m_start.loadFromFile("start.png");
	m_startPng = sf::Sprite(m_start);
	m_startPng.setPosition(400, 200);

	m_end.loadFromFile("exit.png");
	m_endPng = sf::Sprite(m_end);
	m_endPng.setPosition(400, 300);

		//add bottom to level select
	m_backGround.loadFromFile("backgroudCandyWithCookies.jpg");
	m_backGroundPng = sf::Sprite(m_backGround);
	Board::boardObject().loadBoardFromController(levelName(), m_level);
	openScreen();

}

void Controller::openScreen()
{
	//heigth + 4 for the info about score level lives and time left
	m_window.create(sf::VideoMode((Board::boardObject().getWidth()-2) * COMPARISON, (Board::boardObject().getHeight()+1) * COMPARISON), levelName());
}


void Controller::startGame()
{
	int lives=3;
	sf::Clock clock;
	m_window.setFramerateLimit(60);
	if (!m_window.isOpen())
		openScreen();
	 Music::instance().startMusic(); /////////////////////////////////////////////////////////////
	//while (Player::instance().getLives() > 0)// && Board::boardObject().loadBoard(levelName(), m_level))
	 while (Board::boardObject().getLives() > 0)
	 {
		while (m_window.isOpen() && Board::boardObject().getNumberOfCoins() != 0 && Board::boardObject().getLives() != 0
			&& ((Timer::instance().getTimer() > 0) || (Timer::instance().getTimer() == -1)))
		{
			lives = Board::boardObject().getLives();//Player::instance().getLives();
			

			if (Timer::instance().getTimer() != -1)
				Timer::instance().updateTimer();
			m_window.clear();
			Board::boardObject().print(m_window);
			m_window.display();
			// Handle events
			sf::Event event;
			for (auto event = sf::Event{}; m_window.pollEvent(event); ) // wait to event
			{
				switch (event.type)
				{
				case sf::Event::Closed:
					m_window.close();
					break;
				case sf::Event::KeyPressed:
					if (event.key.code == sf::Keyboard::Escape)
						m_window.close();
					else
						Board::boardObject().playerSetDirection(event.key.code);
					break;
				case sf::Event::KeyReleased:
					Board::boardObject().playerSetDirection(sf::Keyboard::Space);
					break;
				}

			}
			auto time = clock.restart();
			Board::boardObject().move(time);

			if (lives - Board::boardObject().getLives() == 1) //if failed
			{
				lives--;
				Board::boardObject().clearVectors();
				Board::boardObject().loadBoard(levelName(), m_level);
				Board::boardObject().getPlayer().setLastScore();//Player::instance().setLastScore();
			}

		}
		Music::instance().stopMusic(); 

		if (Board::boardObject().getNumberOfCoins() == 0)
		{ // good music
		//	Music::instance().startWinMusic();
			m_level++;
			Board::boardObject().clearVectors();
			Board::boardObject().getPlayer().setLastScore();//Player::instance().setLastScore();
			m_window.close();
			if (Board::boardObject().loadBoard(levelName(), m_level))
			{
				openScreen();
				Music::instance().startMusic();
			}
			else
				break;
		}
		
	}
	
	if (Board::boardObject().getLives() == 0)
	{ // bad music
		failed();
	}
	
	if (m_window.isOpen())
		m_window.close();
}

void Controller::menupage()
{
	sf::RenderWindow menuPage(sf::VideoMode(1000, 550), "welcome to lode runner");
	//start.loadFromFile("backgroundCandyWithCookies.png");
	while (menuPage.isOpen())
	{
		menuPage.clear();
		menuPage.draw(m_backGroundPng);
		menuPage.draw(m_startPng);
		menuPage.draw(m_endPng);
		menuPage.display();
		if (auto event = sf::Event{}; menuPage.waitEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
			case sf::Keyboard::Escape:
				menuPage.close();
				break;
			case sf::Event::MouseButtonReleased:
				if (event.mouseButton.x > 400 && event.mouseButton.x < 500
					&& event.mouseButton.y > 200 && event.mouseButton.y < 300)
				{
					menuPage.close();
					startGame();
					menuPage.create(sf::VideoMode(1000, 550), "welcome to lode runner");
				}
				else if (event.mouseButton.x > 400 && event.mouseButton.x < 500
					&& event.mouseButton.y > 300 && event.mouseButton.y < 400)
					menuPage.close();
				break;
			//case  sf::Event::MouseMoved:
			}
		}
	}
}

void Controller::failed()
{
	m_level = 1;
	Board::boardObject().getPlayer().setLives(3);//Player::instance().setLives(3); // more 3 lives
	Board::boardObject().getPlayer().resetData();//Player::instance().resetData();
	Board::boardObject().clearVectors();
	Board::boardObject().loadBoard(levelName(), m_level);	
}

std::string Controller::levelName()
{
	int i;
	std::string level = std::to_string(m_level);
	int size = level.size();
	auto fileName = std::string("level");
	for (i = 0; i < size; i++)
		fileName.push_back(level[i]);
	fileName.push_back('.');
	fileName.push_back('t');
	fileName.push_back('x');
	fileName.push_back('t');

	return std::string(fileName);
}