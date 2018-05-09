#pragma once
#ifndef themes_h
#define themes_h

#include "SFML\Graphics.hpp"

struct theme
{
	sf::Color border_color;
	sf::Color white_box_color;
	sf::Color black_box_color;
	sf::Color white_men_clor;
	sf::Color black_men_clolr;
	sf::Color marked_place;
	sf::Color i_can_go_there;
	sf::Color i_can_move_this_man;
	sf::Color can_to_beat;
	std::string link_to_font;
	std::string link_to_background;
};

void fillThemesArray(theme *themesArray);

#endif // !themes_h
