#pragma once
#ifndef drawer_h
#define drawer_h
#include "SFML\Graphics.hpp"
#include "Board.h"
#include "themes.h"

std::string add2string(std::string text1, std::string text2);


std::string intToStr(int number);


void draw(int boxsize, sf::RenderWindow &renderWindow, Board &plansza, theme *theme_arr, int themeID);


#endif // !drawer_h
