#pragma once
#ifndef drawer_h
#define drawer_h
#include "SFML\Graphics.hpp"
#include "Board.h"
#include "themes.h"

std::string add2string(std::string text1, std::string text2)
{
	std::string str;
	str.append(text1);
	str.append(" ");
	str.append(text2);
	return str;
}

std::string intToStr(int number)
{
	auto str = std::to_string(number);
	return str;
}

void draw(int boxsize, sf::RenderWindow &renderWindow, Board &plansza, theme *theme_arr,int themeID)
{
	int manRadius = boxsize / 3;
	int kingRadius = boxsize / 6;
	int kingShift = boxsize / 3;
	int manShift = boxsize / 6;
	sf::CircleShape man,king;
	man.setRadius(manRadius);
	king.setRadius(kingRadius);
	king.setFillColor(sf::Color(125, 125, 0));

	sf::RectangleShape place;
	place.setSize(sf::Vector2f(boxsize, boxsize));

	for (int i = boxsize; i < boxsize*9; i+=boxsize)
	{
		int arrI = i / boxsize - 1;
		for (int j = boxsize; j < boxsize * 9; j += boxsize)
		{
			int arrJ = j / boxsize - 1;

			//place drawing
			place.setPosition(j, i);
			if (plansza.array_of_places[arrI][arrJ].HaveIAcces)
			{
				place.setFillColor(theme_arr[themeID].black_box_color);

				//czy moge sie ruszy� tym pionkiem
				if (plansza.array_of_places[arrI][arrJ].CanIUseThisMAn)
				{
					place.setFillColor(theme_arr[themeID].i_can_move_this_man);
				}
				if (plansza.array_of_places[arrI][arrJ].CanToBeat)
				{
					place.setFillColor(theme_arr[themeID].can_to_beat);
				}
				if (plansza.array_of_places[arrI][arrJ].CanIPutMarkedManThere)
				{
					place.setFillColor(theme_arr[themeID].i_can_go_there);
				}
				if (plansza.array_of_places[arrI][arrJ].IsMArkToMoveTO)
				{
					place.setFillColor(sf::Color(255,0,0));
				}
				//czy zaznaczone
				if (plansza.array_of_places[arrI][arrJ].IsMarkToMoveFROM)
				{
					place.setFillColor(theme_arr[themeID].marked_place);
				}
			}
			else
			{
				place.setFillColor(theme_arr[themeID].white_box_color);
			}
			renderWindow.draw(place);

			//man drawing
			if (plansza.array_of_places[arrI][arrJ].IsThereAMan)
			{
				man.setPosition(sf::Vector2f(j + manShift, i + manShift));
				if (plansza.array_of_places[arrI][arrJ].WhiteTeam)
					man.setFillColor(theme_arr[themeID].white_men_clor);
				else
					man.setFillColor(theme_arr[themeID].black_men_clolr);
				renderWindow.draw(man);
				if (plansza.array_of_places[arrI][arrJ].IsaKing)
				{
					king.setPosition(j + kingShift, i + kingShift);
					renderWindow.draw(king);
				}
			}

			
		}
	}
	// round ractangle
	sf::RectangleShape roundColor;
	roundColor.setSize(sf::Vector2f(boxsize, boxsize));
	roundColor.setPosition(sf::Vector2f(10 * boxsize, boxsize));
	roundColor.setOutlineThickness(boxsize / 12);
	if (plansza.RoundNumber%2 ==0)
	{
		roundColor.setFillColor(theme_arr[themeID].white_men_clor);
		roundColor.setOutlineColor(theme_arr[themeID].black_men_clolr);
	}
	else
	{
		roundColor.setFillColor(theme_arr[themeID].black_men_clolr);
		roundColor.setOutlineColor(theme_arr[themeID].white_men_clor);
	}
	renderWindow.draw(roundColor);
	//mens text
	sf::Font font;
	font.loadFromFile(theme_arr[themeID].link_to_font);
	sf::Text mens_count;
	mens_count.setCharacterSize(boxsize / 2);
	mens_count.setFont(font);
	auto str = add2string("Black mans count:", intToStr(plansza.black_player_mans));
	mens_count.setString(str);
	mens_count.setFillColor(theme_arr[themeID].black_men_clolr);
	mens_count.setOutlineThickness(boxsize / 30);
	mens_count.setOutlineColor(theme_arr[themeID].white_men_clor);
	mens_count.setPosition(sf::Vector2f(boxsize *3.2f, boxsize/8));
	renderWindow.draw(mens_count);
	auto str2 = add2string("White mans count:", intToStr(plansza.white_player_mans));
	mens_count.setString(str2);
	mens_count.setFillColor(theme_arr[themeID].white_men_clor);
	mens_count.setOutlineThickness(boxsize / 30);
	mens_count.setOutlineColor(theme_arr[themeID].black_men_clolr);
	mens_count.setPosition(sf::Vector2f(boxsize *3.2f, 9.125f*boxsize));
	renderWindow.draw(mens_count);

}

#endif // !drawer_h
