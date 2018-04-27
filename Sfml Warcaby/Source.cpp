#include "SFML\Graphics.hpp"
#include <Windows.h>
#include <fstream>
#include "Board.h"
#include <iostream>
#include "drawer.h"
#include "themes.h"



int main(int argc, char **argv)
{
	bool moved = false;
	std::fstream save;
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
	sf::Font font;
	font.loadFromFile(array_of_themes[themeID].link_to_font);
	sf::Text text;
	text.setFont(font);
	text.setCharacterSize(plansza.boxSize * 2);
	text.setFillColor(sf::Color(255, 0, 0));
	text.setOutlineColor(sf::Color(0, 0, 0));
	text.setOutlineThickness(plansza.boxSize / 20);
	text.setPosition(sf::Vector2f(0, 0));
	sf::Vector2i pomocniczy;
	while (gameWindow.isOpen())
	{
		bool done = false;
		gameWindow.clear();
		draw(plansza.boxSize, gameWindow, plansza, array_of_themes, themeID);
		gameWindow.display();
		if (plansza.white_player_mans == 0)
		{
			text.setString("Black Wins");
			sf::FloatRect textRect = text.getLocalBounds();
			text.setOrigin(textRect.left + textRect.width / 2.0f,
				textRect.top + textRect.height / 2.0f);
			text.setPosition(sf::Vector2f(plansza.ScreenWidth / 2.0f, plansza.ScreenHeight / 2.0f));
			gameWindow.draw(text);
			gameWindow.display();
			Sleep(3000);
			plansza.SetBoardOnStartPoint();
		}
		if (plansza.black_player_mans == 0)
		{
			text.setString("White Wins");
			sf::FloatRect textRect = text.getLocalBounds();
			text.setOrigin(textRect.left + textRect.width / 2.0f,
				textRect.top + textRect.height / 2.0f);
			text.setPosition(sf::Vector2f(plansza.ScreenWidth / 2.0f, plansza.ScreenHeight / 2.0f));
			gameWindow.draw(text);
			gameWindow.display();
			Sleep(3000);
			plansza.SetBoardOnStartPoint();
		}
		if (!plansza.isKingThatCanToBeat() && !plansza.IsManThatCanToBeat() && !plansza.isKnigThatCanMove() && !plansza.isManThatCanMove())
		{
			if (plansza.RoundNumber % 2 == 0)
			{
				text.setString("Black Wins");
				sf::FloatRect textRect = text.getLocalBounds();
				text.setOrigin(textRect.left + textRect.width / 2.0f,
					textRect.top + textRect.height / 2.0f);
				text.setPosition(sf::Vector2f(plansza.ScreenWidth / 2.0f, plansza.ScreenHeight / 2.0f));
				gameWindow.draw(text);
				gameWindow.display();
				Sleep(3000);
				plansza.SetBoardOnStartPoint();
			}
			else
			{
				text.setString("White Wins");
				sf::FloatRect textRect = text.getLocalBounds();
				text.setOrigin(textRect.left + textRect.width / 2.0f,
					textRect.top + textRect.height / 2.0f);
				text.setPosition(sf::Vector2f(plansza.ScreenWidth / 2.0f, plansza.ScreenHeight / 2.0f));
				gameWindow.draw(text);
				gameWindow.display();
				Sleep(3000);
				plansza.SetBoardOnStartPoint();
			}
		}
		//####################################### BOT
		if (plansza.BlackBotOn && plansza.RoundNumber % 2 == 1)
		{
			if (plansza.isKingThatCanToBeat() && !plansza.isPlaceMarkedToMoveFrom() && !done)
			{
				plansza.MarkAllKingsThatCanTOBeat();
				plansza.selectRandomBEtingKing();
				plansza.unmarkAllICanUseFields();
				plansza.markAllFielsdWhereICanPutThisKing();
				Sleep(700);
				plansza.SelectRandomPlaceToGo();
				pomocniczy = plansza.WhereIGOTo();
				plansza.BeatingKing(gameWindow);

				plansza.RoundNumber++;
				done = 1;
			}
			if (plansza.IsManThatCanToBeat() && !plansza.isPlaceMarkedToMoveFrom() && !done)
			{
				plansza.markAllMansThatCanToBeat();
				plansza.selectRandomBEatingMan();
				plansza.unmarkAllICanUseFields();
				plansza.MarkAllFieldsWhereCanIPutThisMan();

				while (plansza.isThereManinBestMode())
				{
					gameWindow.clear();
					draw(plansza.boxSize, gameWindow, plansza, array_of_themes, themeID);
					gameWindow.display();
					Sleep(500);
					plansza.SelectRandomPlaceToGo();
					plansza.BeatingMan(gameWindow);
					plansza.unmarkAllToFields();
				}


				plansza.RoundNumber++;
				done = 1;
			}
			if (!plansza.isKingThatCanToBeat() && !plansza.IsManThatCanToBeat() && !plansza.isPlaceMarkedToMoveFrom() && !done)
			{
				plansza.markAllKingsThatCanBeMoveForPlayer();
				plansza.markAllMansThatCanBeMoveForPlayer();
				if (plansza.isAmanThatAfterMoveWontDie())   //nie kojfnie
				{
					std::cout << "nie kojfnie" << std::endl;
					plansza.selectRandomMAnThatWOntDie();

					gameWindow.clear();
					draw(plansza.boxSize, gameWindow, plansza, array_of_themes, themeID);
					gameWindow.display();
					Sleep(500);

					pomocniczy = plansza.WhereIGOTo();
					plansza.MoveMan(pomocniczy);
					plansza.unmarkAllToFields();
					plansza.RoundNumber++;
					plansza.unmarkAllICanUseFields();
					done = 1;
				}
				else  //kojfnie
				{
					if (!done)
					{
						plansza.SelectRandomManThat();

						plansza.unmarkAllICanUseFields();

						plansza.MarkAllFieldsWhereCanIPutThisMan();
						gameWindow.clear();
						draw(plansza.boxSize, gameWindow, plansza, array_of_themes, themeID);
						gameWindow.display();
						Sleep(700);


						plansza.SelectRandomPlaceToGo();

						pomocniczy = plansza.WhereIGOTo();
						plansza.MoveMan(pomocniczy);
						plansza.unmarkAllToFields();
						plansza.RoundNumber++;
						done = 1;
					}
				}

			}
		}
		//#############################################################33
		while (gameWindow.pollEvent(events))
		{
			if (events.type == sf::Event::EventType::Closed)
			{
				gameWindow.close();
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			{
				gameWindow.close();
			}

			/////////////////////////////////////////////////////
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && !(plansza.BlackBotOn && plansza.RoundNumber % 2 == 1))
			{

				sf::Vector2i mouse_pos = sf::Mouse::getPosition(gameWindow);
				if (plansza.waspalcepress(plansza.botB, mouse_pos))
				{
					if (plansza.BlackBotOn)
						plansza.BlackBotOn = 0;
					else
						plansza.BlackBotOn = 1;
				}
				if (!plansza.NOTclickedInBoard(mouse_pos))  //clicked in board
				{
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
							if (plansza.isKingThatCanToBeat())
							{
								while (plansza.isThereKinginBestMode())
								{
									plansza.BeatingKing(gameWindow);
									gameWindow.clear();
									draw(plansza.boxSize, gameWindow, plansza, array_of_themes, themeID);
									gameWindow.display();
								}
								std::cout << "aaa" << std::endl;
								plansza.RoundNumber++;
								moved = true;
							}
							else
								if (plansza.IsManThatCanToBeat())
								{
									while (plansza.isThereManinBestMode())
									{
										std::cout << "A se wejde w pentle" << std::endl;
										plansza.displayAllBeast();
										plansza.BeatingMan(gameWindow);
										gameWindow.clear();
										draw(plansza.boxSize, gameWindow, plansza, array_of_themes, themeID);
										gameWindow.display();
									}
									std::cout << "bbb" << std::endl;
									plansza.RoundNumber++;
									moved = true;
								}

							if (!moved)
							{
								plansza.MoveMan(mouse_pos);
								std::cout << "ccc" << std::endl;
								plansza.RoundNumber++;
							}
							moved = false;
						}
						else
						{
							plansza.unmarkAllFields();

						}

					}
					Sleep(100);
				}
				else // not clicked in board
				{
					if (plansza.waspalcepress(plansza.saveB, mouse_pos))
					{
						std::cout << "a KLIKNE" << std::endl;
						save.open("save.txt", std::ios::out);
						save << plansza.white_player_mans << std::endl;
						save << plansza.black_player_mans << std::endl;
						save << plansza.ScreenHeight << std::endl;
						save << plansza.ScreenWidth << std::endl;
						save << plansza.boxSize << std::endl;
						save << plansza.RoundNumber << std::endl;
						for (int i = 0; i < 8; i++)
						{
							for (int j = 0; j < 8; ++j) {
								save << plansza.array_of_places[j][i].HaveIAcces << std::endl;
								save << plansza.array_of_places[j][i].IsThereAMan << std::endl;
								save << plansza.array_of_places[j][i].CanIUseThisMAn << std::endl;
								save << plansza.array_of_places[j][i].WhiteTeam << std::endl;
								save << plansza.array_of_places[j][i].IsaKing << std::endl;
								save << plansza.array_of_places[j][i].IsMarkToMoveFROM << std::endl;
								save << plansza.array_of_places[j][i].IsMArkToMoveTO << std::endl;
								save << plansza.array_of_places[j][i].CanIPutMarkedManThere << std::endl;
								save << plansza.array_of_places[j][i].CanToBeat << std::endl;
								save << plansza.array_of_places[j][i].BeastMode << std::endl;

							}
						}
						save.close();
					}
					if (plansza.waspalcepress(plansza.loadB, mouse_pos)) {
						std::cout << "A se wczytam";
						plansza.SetBoardOnStartPoint();
						save.open("save.txt", std::ios::in);
						save >> plansza.white_player_mans;
						save >> plansza.black_player_mans;
						save >> plansza.ScreenHeight;
						save >> plansza.ScreenWidth;
						save >> plansza.boxSize;
						save >> plansza.RoundNumber;
						for (int i = 0; i < 8; i++)
						{
							for (int j = 0; j < 8; ++j) {
								save >> plansza.array_of_places[j][i].HaveIAcces;
								save >> plansza.array_of_places[j][i].IsThereAMan;
								save >> plansza.array_of_places[j][i].CanIUseThisMAn;
								save >> plansza.array_of_places[j][i].WhiteTeam;
								save >> plansza.array_of_places[j][i].IsaKing;
								save >> plansza.array_of_places[j][i].IsMarkToMoveFROM;
								save >> plansza.array_of_places[j][i].IsMArkToMoveTO;
								save >> plansza.array_of_places[j][i].CanIPutMarkedManThere;
								save >> plansza.array_of_places[j][i].CanToBeat;
								save >> plansza.array_of_places[j][i].BeastMode;

							}
						}
						save.close();
					}
					if (plansza.waspalcepress(plansza.resetB, mouse_pos)) {
						plansza.SetBoardOnStartPoint();
						plansza.unmarkAllICanUseFields();
					}
				}
			}
			gameWindow.clear();

			if (!plansza.isPlaceMarkedToMoveFrom()) {
				if (plansza.IsManThatCanToBeat() || plansza.isKingThatCanToBeat())
				{
					plansza.markAllMansThatCanToBeat();
					plansza.MarkAllKingsThatCanTOBeat();
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
