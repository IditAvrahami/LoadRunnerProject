#pragma once
#include "Controller.h"
#include <SFML/Graphics.hpp>
#include <SFML/System/Clock.hpp>

//Controller::Controller() : m_lives(3), m_level(1), m_score(0), m_board((*this).levelName())
Controller::Controller() : m_level(1), m_board((*this).levelName(), m_level)
{
	m_window.create(sf::VideoMode(m_board.getHeight() * COMPARISON, m_board.getWidth() * COMPARISON), (*this).levelName());

}

void Controller::openScreen()
{
	//heigth + 4 for the info about score level lives and time left
	m_window.create(sf::VideoMode((m_board.getHeight() + 4) * 50, m_board.getWidth() * 50), (*this).levelName());
}


void Controller::startGame()
{
	sf::Clock clock;
	m_window.setFramerateLimit(60);
	if (!m_window.isOpen())
		openScreen();
	while (m_window.isOpen() && m_board.getNumberOfCoins() != 0 && m_board.getLives() != 0)
	{
		m_window.clear();
		m_board.print(m_window);
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
					m_board.playerSetDirection(event.key.code);
				break;
			case sf::Event::KeyReleased:
				m_board.playerSetDirection(sf::Keyboard::Space);
				break;
			}

		}
		auto time = clock.restart();
		m_board.move(time);
	}
	if (m_window.isOpen())
		m_window.close();
}

void Controller::menupage()
{
	sf::RenderWindow menuPage(sf::VideoMode(1000, 1000), "welcome to lode runner");

	while (menuPage.isOpen())
	{
		sf::Texture start;
		start.loadFromFile("ladder.png");
		sf::Sprite startpng(start);
		startpng.setPosition(400, 200);
		startpng.setScale(10, 5);

		sf::Texture end;
		end.loadFromFile("enemy.png");
		sf::Sprite endpng(start);
		endpng.setPosition(400, 400);
		endpng.setScale(10, 5);

		/*
		* add bottom to level select
		sf::Texture end;
		end.loadFromFile("player.png");
		sf::Sprite endpng(start);
		endpng.setPosition(400, 100);
		*/

		menuPage.clear();
		menuPage.draw(startpng);
		menuPage.draw(endpng);
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
				if (event.mouseButton.x > 400 && event.mouseButton.x < 700
					&& event.mouseButton.y > 200 && event.mouseButton.y < 350)
				{
					menuPage.close();
					startGame();
					menuPage.create(sf::VideoMode(1000, 1000), "welcome to lode runner");
				}
				else if (event.mouseButton.x > 400 && event.mouseButton.x < 700
					&& event.mouseButton.y > 400 && event.mouseButton.y < 550)
					menuPage.close();
				break;
			case  sf::Event::MouseMoved:
				std::cout << event.mouseMove.x << " " << event.mouseMove.y << std::endl;
			}
		}
	}
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