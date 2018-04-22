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

void fillThemesArray(theme *themesArray)
{
	(themesArray)[0].border_color = sf::Color(210, 177, 130);
	(themesArray)[0].black_box_color = sf::Color(153, 102, 51);
	(themesArray)[0].white_box_color = sf::Color(222, 222, 222);
	(themesArray)[0].black_men_clolr = sf::Color(0, 0, 0);
	(themesArray)[0].white_men_clor = sf::Color(250, 250, 250);
	themesArray[0].marked_place = sf::Color(204, 102, 0);
	themesArray[0].i_can_go_there = sf::Color(51, 102, 153);
	themesArray[0].i_can_move_this_man = sf::Color(115, 146, 64);
	(themesArray)[0].link_to_background = "Backgrounds/wood4.jpg";
	themesArray[0].can_to_beat = sf::Color(255, 0, 0);
	themesArray[0].link_to_font = "Fonts/Umbrella.otf";


	(themesArray)[1].border_color = sf::Color(218, 213, 109);
	(themesArray)[1].black_box_color = sf::Color(40, 40, 40);
	(themesArray)[1].white_box_color = sf::Color(227, 44, 101);
	(themesArray)[1].black_men_clolr = sf::Color(184, 135, 224);
	(themesArray)[1].white_men_clor = sf::Color(255, 252, 225);
	(themesArray)[1].link_to_background = "Backgrounds/code.jpg";
	themesArray[1].can_to_beat = sf::Color(255, 0, 0);



}

#endif // !themes_h
