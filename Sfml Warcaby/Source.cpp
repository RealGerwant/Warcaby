#include "SFML\Graphics.hpp"
#include <Windows.h>
#include "Board.h"
#include <iostream>
#include "drawer.h"
#include "themes.h"


int main(int argc, char **argv)
{
	int themes_number = 2;
	int themeID = 0;
	theme * array_of_themes;
	array_of_themes = new theme[themes_number];
	fillThemesArray(array_of_themes);

	Board plansza;
	plansza.SetBoardOnStartPoint();

	sf::RenderWindow gameWindow(sf::VideoMode(plansza.ScreenWidth, plansza.ScreenHeight), "Warcaby by Pajac");
	sf::Event events;
	sf::Keyboard::setVirtualKeyboardVisible;
	while (gameWindow.isOpen())
	{
		while (gameWindow.pollEvent(events))
		{
			std::cout << "PAPAJ" << std::endl;
			if (events.type == sf::Event::EventType::Closed)
			{
				gameWindow.close();
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			{
				gameWindow.close();
			}

			/////////////////////////////////////////////////////
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				sf::Vector2i mouse_pos = sf::Mouse::getPosition(gameWindow);
				if (!plansza.isPlaceMarkedToMoveFrom()) //jak jest zaznaczony
				{
					plansza.markplace(mouse_pos);
					plansza.unmarkAllICanUseFields();
					plansza.MarkAllFieldsWhereCanIPutThisMan();
					plansza.markAllFielsdWhereICanPutThisKing();
					break;
				}
				if (plansza.isPlaceMarkedToMoveFrom())
				{
					if (plansza.didUClickInMarkedPlace(mouse_pos))
					{
						if (plansza.IsManThatCanToBeat())
						{
							while (plansza.isThereManinBestMode())
							{

								std::cout << ".elomordeczo" << std::endl;
								plansza.BeatingMan(gameWindow);
								gameWindow.clear();
								draw(plansza.boxSize, gameWindow, plansza, array_of_themes, themeID);
								gameWindow.display();

							}
							plansza.RoundNumber++;
						}
						else
						{
							plansza.MoveMan(mouse_pos);
						}
					}
					else
					{
						plansza.unmarkAllFields();
					}

				}
				Sleep(100);
			}
			gameWindow.clear();

			if (!plansza.isPlaceMarkedToMoveFrom()) {
				if (plansza.IsManThatCanToBeat())
				{
					plansza.markAllMansThatCanToBeat();
					std::cout << "Jest Bicie" << std::endl;
				}
				else
				{
					plansza.markAllMansThatCanBeMoveForPlayer();
					plansza.markAllKingsThatCanBeMoveForPlayer();
				}

			}
			plansza.promotion();
			draw(plansza.boxSize, gameWindow, plansza, array_of_themes, themeID);
			gameWindow.display();
		}
	}
}