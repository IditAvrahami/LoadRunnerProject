#pragma once
#include "Controller.h"
#include <SFML/Graphics.hpp>
#include <SFML/System/Clock.hpp>

Controller::Controller() : m_lives(3), m_level(1), m_score(0), m_board((*this).levelName(), m_player, m_enemy)
{
	m_window.create(sf::VideoMode(m_board.getHeight() * 50, m_board.getWidth() * 50), (*this).levelName());

}

void Controller::openScreen(int heigth, int width)
{
	//heigth + 4 for the info about score level lives and time left
	m_window.create(sf::VideoMode((m_board.getHeight() + 4) * 50, m_board.getWidth() * 50), (*this).levelName());
}


void Controller::startGame()
{
	sf::Clock clock;
	m_window.setFramerateLimit(60);

	while (m_window.isOpen() && m_board.getNumberOfCoins() != 0)
	{
		print();
		// Handle events
		sf::Event event;
		while (m_window.pollEvent(event))
		{
			/*// Window closed or escape key pressed: exit
			if ((event.type == sf::Event::Closed) ||
				((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape)))
			{
				m_window.close();
				break;
			}*/
			switch (event.type)
			{
			case sf::Event::Closed:
				m_window.close();
				break;
			case sf::Event::KeyPressed:
				if (event.key.code == sf::Keyboard::Escape)
					m_window.close();
				else
					m_player.setDirection(event.key.code);
				break;
			case sf::Event::KeyReleased:
				m_player.setDirection(sf::Keyboard::Space);
				break;
			}

		}
		auto time = clock.restart();
		m_player.move(time);
		for (int i = 0; i < m_enemy.size(); i++)
			m_enemy[i]->move(time);
		

	}
}

void Controller::print()
{
	m_window.clear();
	m_board.print(m_window);
	m_player.print(m_window);
	for (int i = 0; i < m_enemy.size(); i++)
		m_enemy[i]->print(m_window);
	m_window.display();
}

std::string Controller::levelName()
{
	std::string level = std::to_string(m_level);
	int size = level.size();
	auto fileName = std::string("level");
	for (int i = 0; i < size; i++)
		fileName.push_back(level[i]);
	return std::string(fileName);
}