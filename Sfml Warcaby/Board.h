#pragma once
#include "SFML\Graphics.hpp"




struct borders
{
	int left;
	int up;
	int right;
	int down;
};
struct place
{
	bool HaveIAcces = 0;
	bool IsThereAMan = 0;
	bool CanIUseThisMAn = 0;
	bool WhiteTeam = 1;
	bool IsaKing = 0;
	bool IsMarkToMoveFROM = 0;
	bool IsMArkToMoveTO = 0;
	bool CanIPutMarkedManThere = 0;
	bool CanToBeat = 0;
	borders broders;
	bool BeastMode = 0;
	bool clicked = 0;


};
class Board
{
public:
	int white_player_mans = 12;
	int black_player_mans = 12;
	int ScreenHeight = 720;
	int ScreenWidth = (16 * ScreenHeight) / 9;
	int boxSize = ScreenHeight/10;
	int RoundNumber = 0;
	place ** array_of_places;
	Board();
	void SetBoardOnStartPoint();
	void markplace(sf::Vector2i position);
	bool isPlaceMarkedToMoveFrom();
	bool NOTclickedInBoard(sf::Vector2i position);
	void unmarkAllFields();
	void markAllMansThatCanBeMoveForPlayer();
	void markAllMansThatCanToBeat();
	void unmarkAllICanUseFields();
	void MarkAllFieldsWhereCanIPutThisMan();
	void MoveMan(sf::Vector2i position);
	bool didUClickInMarkedPlace(sf::Vector2i position);
	bool IsManThatCanToBeat();
	void markAllFielsdWhereICanPutThisKing();
	void markAllKingsThatCanBeMoveForPlayer();
	void promotion();
	void BeatingMan(sf::RenderWindow &gameWindow );
	bool isThereManinBestMode();
	void readRoundNumber();
};