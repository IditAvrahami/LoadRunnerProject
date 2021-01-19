#pragma once
#include <SFML/Graphics.hpp>

const sf::Vector2f KB_UP = { 0,-1 };
const sf::Vector2f KB_DOWN = { 0,1 };
const sf::Vector2f KB_LEFT = { -1,0 };
const sf::Vector2f KB_RIGHT = { 1,0 };
const sf::Vector2f KB_STAY = { 0,0 };
const sf::Vector2f TO_DELETED = { -1,-1 };

const int OBJECTS =7; // change it with backgroud and play buttom without player
const int COMPARISON = 30;
const int PLAYER = 107;
const int ENEMY = 108;
const int LEDDER = 109;
const int COIN = 110;
const int FLOOR = 111;
const int ROD = 112;
const int NOTHING = 113;
const int NUMBER_OF_PRESENT = 1;
