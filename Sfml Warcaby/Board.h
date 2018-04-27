#pragma once
#include "SFML\Graphics.hpp"


struct borders
{
	float left;
	float up;
	float right;
	float down;
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
};
class Board
{
public:
	bool blokada_white;
	bool blokada_black;
	bool black_wins;
	bool white_wins;
	int white_player_mans = 12;
	int black_player_mans = 12;
	int ScreenHeight = 720;
	int ScreenWidth = (16 * ScreenHeight) / 9;
	int boxSize = ScreenHeight/10;
	int RoundNumber = 0;
	place ** array_of_places;
	place saveB;
	place loadB;
	place resetB;
	place botB;
	bool BlackBotOn = 0;
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
	bool waspalcepress(place place, sf::Vector2i mouse_position);
	bool isKingThatCanToBeat();
	void MarkAllKingsThatCanTOBeat();
	void BeatingKing(sf::RenderWindow &gameWindow);
	bool isThereKinginBestMode();
	bool isManThatCanMove();
	bool isKnigThatCanMove();
	void displayAllBeast();
	void SelectRandomManThat();
	void SelectRandomPlaceToGo();
	sf::Vector2i WhereIGOTo();
	void unmarkAllToFields();
	bool isAMAnThatAfterBEtingWontDie();
	bool isAmanThatAfterMoveWontDie();
	void selectRandomMAnThatWOntDie();
	void selectRandomBEatingMan();
	void selectRandomBEtingKing();
};




