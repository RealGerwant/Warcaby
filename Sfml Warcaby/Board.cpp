#include "Board.h"
#include "Calculation.h"
#include <iostream>




Board::Board()
{
	array_of_places = new place*[8];
	for (int i = 0; i < 8; i++)
	{
		array_of_places[i] = new place[8];
	}

}

void Board::SetBoardOnStartPoint()
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; ++j)
		{
			if ((i % 2 == 0 && j % 2 == 0) || (i%2==1 && j%2==1))
			{
				array_of_places[i][j].HaveIAcces = 0;
			}
			else
			{
				array_of_places[i][j].HaveIAcces = 1;
				array_of_places[i][j].IsaKing = 0;
				if (i < 3)
				{
					array_of_places[i][j].IsThereAMan = 1;
					array_of_places[i][j].WhiteTeam = 0;
				}
				if (i > 4)
				{
					array_of_places[i][j].IsThereAMan = 1;
					array_of_places[i][j].WhiteTeam = 1;
				}
			}
		}
	}
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; ++j)
		{
			if (array_of_places[j][i].HaveIAcces)
			{
				array_of_places[j][i].broders.left = (i + 1)*boxSize;
				array_of_places[j][i].broders.right = (i + 2)*boxSize;
				array_of_places[j][i].broders.up = (j + 1)*boxSize;
				array_of_places[j][i].broders.down = (j + 2)*boxSize;
			}
		}
	}
}

void Board::markplace(sf::Vector2i position)
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; ++j)
		{
			if (waspalcepress(array_of_places[j][i], position) && array_of_places[j][i].CanIUseThisMAn )
			{
				array_of_places[j][i].IsMarkToMoveFROM = 1;
			}
			if (waspalcepress(array_of_places[j][i], position) && array_of_places[j][i].CanToBeat)
			{
				array_of_places[j][i].IsMarkToMoveFROM = 1;
				array_of_places[j][i].BeastMode = 1;
			}
		}
	}
}

bool Board::isPlaceMarkedToMoveFrom()
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; ++j)
		{
			if (array_of_places[j][i].IsMarkToMoveFROM)
				return true;
		}
	}
	return false;
}

bool Board::NOTclickedInBoard(sf::Vector2i position)
{
	if (position.x>boxSize*9 || position.x < boxSize || position.y > boxSize*9 || position.y< boxSize)
	{
		return true;
	}
	return false;
}

void Board::unmarkAllFields()
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; ++j)
		{
			array_of_places[j][i].CanIPutMarkedManThere = 0;
			array_of_places[j][i].CanIUseThisMAn = 0;
			array_of_places[j][i].IsMarkToMoveFROM = 0;
			array_of_places[j][i].CanToBeat = 0;
		}
	}
}

void Board::unmarkAllICanUseFields()
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; ++j)
		{
			array_of_places[j][i].CanIUseThisMAn = 0;
		}
	}
}

void Board::markAllMansThatCanBeMoveForPlayer()
{
	if (RoundNumber%2 == 0)
		//white player
	{
			for (int i = 0; i < 8; i++)
			{
				for (int j = 0; j < 8; ++j)
				{
					if (array_of_places[j][i].IsThereAMan && !array_of_places[j][i].IsaKing)
					if (array_of_places[j][i].WhiteTeam)
					{
						if (((j - 1 >= 0) && (i - 1 >= 0) && !array_of_places[j - 1][i - 1].IsThereAMan) || (j-1 >= 0) && (i+1 <8 ) && !array_of_places[j-1][i+1].IsThereAMan)
						{
							array_of_places[j][i].CanIUseThisMAn = 1;
						}
					}
				}
			}
	}
	else
		//black player
	{
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; ++j)
			{
				if (array_of_places[j][i].IsThereAMan)
					if (!array_of_places[j][i].WhiteTeam)
					{
						if (((j + 1 <8 ) && (i + 1 < 8) && !array_of_places[j + 1][i + 1].IsThereAMan) || (j + 1 < 8) && (i - 1 >= 0) && !array_of_places[j + 1][i - 1].IsThereAMan)
						{
							array_of_places[j][i].CanIUseThisMAn = 1;
						}
					}
			}
		}
	}
}


void Board::MarkAllFieldsWhereCanIPutThisMan()
{
	if (RoundNumber % 2 == 0)
		//white player
	{
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; ++j)
			{
				if (array_of_places[j][i].IsMarkToMoveFROM )
					if (array_of_places[j][i].CanToBeat)
					{
						if ((j - 2 >= 0) && (i - 2 >= 0) && !array_of_places[j - 2][i - 2].IsThereAMan && array_of_places[j - 1][i - 1].IsThereAMan && !array_of_places[j - 1][i - 1].WhiteTeam)
						{
							array_of_places[j - 2][i - 2].CanIPutMarkedManThere = 1;
						}
						if ((j - 2 >= 0) && (i + 2 <8) && !array_of_places[j - 2][i + 2].IsThereAMan && array_of_places[j - 1][i + 1].IsThereAMan && !array_of_places[j - 1][i + 1].WhiteTeam)
						{
							array_of_places[j - 2][i + 2].CanIPutMarkedManThere = 1;
						}
					}
					else
					{
						{
							if ((j - 1 >= 0) && (i - 1 >= 0) && !array_of_places[j - 1][i - 1].IsThereAMan)
							{
								array_of_places[j - 1][i - 1].CanIPutMarkedManThere = 1;
							}
							if ((j - 1 >= 0) && (i + 1 <8) && !array_of_places[j - 1][i + 1].IsThereAMan)
							{
								array_of_places[j - 1][i + 1].CanIPutMarkedManThere = 1;
							}
						}
					}
			}
		}
	}
	else
	{
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; ++j)
			{
				if (array_of_places[j][i].IsMarkToMoveFROM)
				{
					if (array_of_places[j][i].CanToBeat)
					{
						if ((j + 2 <8) && (i + 2 < 8) && !array_of_places[j + 2][i + 2].IsThereAMan && array_of_places[j + 1][i + 1].IsThereAMan && array_of_places[j + 1][i + 1].WhiteTeam)
						{
							array_of_places[j + 2][i + 2].CanIPutMarkedManThere = 1;
						}
						if ((j + 2 < 8) && (i - 2 >= 0) && !array_of_places[j + 2][i - 2].IsThereAMan && array_of_places[j + 1][i - 1].IsThereAMan && array_of_places[j + 1][i - 1].WhiteTeam)
						{
							array_of_places[j + 2][i - 2].CanIPutMarkedManThere = 1;
						}
					}
					else
					{
						if (((j + 1 <8) && (i + 1 < 8) && !array_of_places[j + 1][i + 1].IsThereAMan))
						{
							array_of_places[j + 1][i + 1].CanIPutMarkedManThere = 1;
						}
						if ((j + 1 < 8) && (i - 1 >= 0) && !array_of_places[j + 1][i - 1].IsThereAMan)
						{
							array_of_places[j + 1][i - 1].CanIPutMarkedManThere = 1;
						}
					}
				}
			}
		}
	}
}

bool Board::isThereManinBestMode()
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; ++j)
		{
			if (array_of_places[j][i].BeastMode)
			{
				return true;
			}
		}
	}
	return false;
}


void Board::MoveMan(sf::Vector2i position)
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; ++j)
		{
			if (waspalcepress(array_of_places[j][i], position) && array_of_places[j][i].CanIPutMarkedManThere)
			{
				array_of_places[j][i].IsThereAMan = 1;
				int i2 = i, j2 = j;
				bool team;
				bool king;
				for (int i = 0; i < 8; i++)
				{
					for (int j = 0; j < 8; ++j)
					{
						if (array_of_places[j][i].IsMarkToMoveFROM)
						{
								king = array_of_places[j][i].IsaKing;
								array_of_places[j][i].IsaKing = 0;
								team = array_of_places[j][i].WhiteTeam;
								array_of_places[j][i].IsMarkToMoveFROM = 0;
								array_of_places[j][i].IsThereAMan = 0;
						}
					}
				}
				array_of_places[j2][i2].WhiteTeam = team;
				array_of_places[j2][i2].IsaKing = king;
			}
		}
	}
	unmarkAllFields();
	RoundNumber++;
}

void Board::BeatingMan(sf::RenderWindow &gameWindow) {
	std::cout << "endered";
	sf::Vector2i position;
	int jfrom, ifrom;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; ++j)
		{
			if (array_of_places[j][i].IsMarkToMoveFROM )
			{
				jfrom = j;
				ifrom = i;
			}
		}
	}
	array_of_places[jfrom][ifrom].IsThereAMan = 0;
	array_of_places[jfrom][ifrom].BeastMode = 0;
	array_of_places[jfrom][ifrom].IsMarkToMoveFROM = 0;
	int jto , ito;
	bool get = false;
	while (!get)
	{
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; ++j)
			{
				if (waspalcepress(array_of_places[j][i], position) && array_of_places[j][i].CanIPutMarkedManThere)
				{
					std::cout << "coooo?" << j << i << std::endl;
					jto = j;
					ito = i;
					get = true;
				}
			}
		}
		while ((sf::Mouse::isButtonPressed(sf::Mouse::Left)))
		{
			position = sf::Mouse::getPosition(gameWindow);
		}
	}
	array_of_places[jto][ito].IsThereAMan= 1;
	array_of_places[jto][ito].WhiteTeam = array_of_places[jfrom][ifrom].WhiteTeam;
	unmarkAllFields();
	if (RoundNumber % 2 == 0)
	{
		if (ito > ifrom)
		{
			array_of_places[jfrom - 1][ifrom + 1].IsThereAMan = 0;
			array_of_places[jfrom - 1][ifrom + 1].IsaKing = 0;
		}
		if (ito < ifrom)
		{
			array_of_places[jfrom - 1][ifrom - 1].IsThereAMan = 0;
			array_of_places[jfrom - 1][ifrom - 1].IsaKing = 0;
		}
		--black_player_mans;
	}
	else
	{
		if (ito > ifrom)
			array_of_places[jfrom + 1][ifrom + 1].IsThereAMan = 0;
		if (ito < ifrom)
			array_of_places[jfrom + 1][ifrom - 1].IsThereAMan = 0;
		--white_player_mans;
	}

	int j = jto, i = ito;

	if (RoundNumber % 2 == 0)
		//white player
	{
				if (array_of_places[j][i].IsThereAMan && !array_of_places[j][i].IsaKing)
					if (array_of_places[j][i].WhiteTeam)
					{
						if ((j - 1 >= 0) && (i - 1 >= 0) && array_of_places[j - 1][i - 1].IsThereAMan && !array_of_places[j - 1][i - 1].WhiteTeam && j - 2 >= 0 && (i - 2 >= 0) && !array_of_places[j - 2][i - 2].IsThereAMan)
						{
							array_of_places[j][i].IsMarkToMoveFROM = 1;
							array_of_places[j][i].CanToBeat = 1;
							array_of_places[j][i].BeastMode = 1;
							array_of_places[j-2][i-2].CanIPutMarkedManThere = 1;
						}
						if ((j - 1 >= 0) && (i + 1 < 8) && array_of_places[j - 1][i + 1].IsThereAMan && !array_of_places[j - 1][i + 1].WhiteTeam && (j - 2 >= 0) && (i + 2 < 8) && !array_of_places[j - 2][i + 2].IsThereAMan)
						{
							array_of_places[j][i].IsMarkToMoveFROM = 1;
							array_of_places[j][i].CanToBeat = 1;
							array_of_places[j][i].BeastMode = 1;
							array_of_places[j - 2][i + 2].CanIPutMarkedManThere = 1;
						}
					}

	}
	else
		//black player
	{
				if (array_of_places[j][i].IsThereAMan && !array_of_places[j][i].IsaKing)
					if (!array_of_places[j][i].WhiteTeam)
					{
						if ((j + 1 <8) && (i + 1 < 8) && array_of_places[j + 1][i + 1].IsThereAMan && array_of_places[j + 1][i + 1].WhiteTeam && (j + 2 <8) && (i + 2 < 8) && !array_of_places[j + 2][i + 2].IsThereAMan) 
						{
							array_of_places[j][i].IsMarkToMoveFROM = 1;
							array_of_places[j][i].CanToBeat = 1;
							array_of_places[j][i].BeastMode = 1;
							array_of_places[j + 2][i + 2].CanIPutMarkedManThere = 1;

						}
						if ((j + 1 < 8) && (i - 1 >= 0) && array_of_places[j + 1][i - 1].IsThereAMan && array_of_places[j + 1][i - 1].WhiteTeam && (j + 2 < 8) && (i - 2 >= 0) && !array_of_places[j + 2][i - 2].IsThereAMan)
						{
							array_of_places[j][i].IsMarkToMoveFROM = 1;
							array_of_places[j][i].CanToBeat = 1;
							array_of_places[j][i].BeastMode = 1;
							array_of_places[j + 2][i - 2].CanIPutMarkedManThere = 1;
						}
					}
	}
}

bool Board::didUClickInMarkedPlace(sf::Vector2i position)
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; ++j)
		{
			if (waspalcepress(array_of_places[j][i], position) && array_of_places[j][i].CanIPutMarkedManThere)
			{
				return true;
			}
		}
	}
	return false;
}

void Board::promotion()
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; ++j)
		{
			if (array_of_places[j][i].IsThereAMan && !array_of_places[j][i].IsaKing)
			{
				//bia³e
				if (array_of_places[j][i].WhiteTeam && !array_of_places[j][i].IsaKing && j==0)
				{
					array_of_places[j][i].IsaKing = 1;
				}
				//czarne
				if (!array_of_places[j][i].WhiteTeam && !array_of_places[j][i].IsaKing && j == 7)
				{
					array_of_places[j][i].IsaKing = 1;
				}
			}
		}
	}
}



void Board::markAllMansThatCanToBeat()
{
	if (RoundNumber % 2 == 0)
		//white player
	{
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; ++j)
			{
				if (array_of_places[j][i].IsThereAMan)
					if (array_of_places[j][i].WhiteTeam)
					{
						if ((j - 1 >= 0) && (i - 1 >= 0) && array_of_places[j - 1][i - 1].IsThereAMan && !array_of_places[j - 1][i - 1].WhiteTeam && (j - 2 >= 0) && (i - 2 >= 0) && !array_of_places[j - 2][i - 2].IsThereAMan)
							
						{
							array_of_places[j][i].CanToBeat = 1;
						}
						if ((j - 1 >= 0) && (i + 1 < 8) && array_of_places[j - 1][i + 1].IsThereAMan && !array_of_places[j - 1][i + 1].WhiteTeam && (j - 2 >= 0) && (i + 2 < 8) && !array_of_places[j - 2][i + 2].IsThereAMan)
						{
							array_of_places[j][i].CanToBeat = 1;
						}
					}
			}
		}
	}
	else
		//black player
	{
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; ++j)
			{
				if (array_of_places[j][i].IsThereAMan)
					if (!array_of_places[j][i].WhiteTeam)
					{
						if ((j + 1 < 8) && (i + 1 < 8) && array_of_places[j + 1][i + 1].IsThereAMan && array_of_places[j + 1][i + 1].WhiteTeam && (j + 2 < 8) && (i + 2 < 8) && !array_of_places[j + 2][i + 2].IsThereAMan)
							
						{
							array_of_places[j][i].CanToBeat = 1;
						}
						if ((j + 1 < 8) && (i - 1 >= 0) && array_of_places[j + 1][i - 1].IsThereAMan && array_of_places[j + 1][i - 1].WhiteTeam && (j + 2 < 8) && (i - 2 >= 0) && !array_of_places[j + 2][i - 2].IsThereAMan)
						{
							array_of_places[j][i].CanToBeat = 1;
						}
					}
			}
		}
	}
}

bool Board::IsManThatCanToBeat()
{
	if (RoundNumber % 2 == 0)
		//white player
	{
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; ++j)
			{
				if (array_of_places[j][i].IsThereAMan && !array_of_places[j][i].IsaKing)
					if (array_of_places[j][i].WhiteTeam)
					{
						if ((j - 1 >= 0) && (i - 1 >= 0) && array_of_places[j - 1][i - 1].IsThereAMan && !array_of_places[j - 1][i - 1].WhiteTeam && j - 2 >= 0 && (i - 2 >= 0) && !array_of_places[j - 2][i - 2].IsThereAMan)
						{
							std::cout << "mo¿e biæ " << j << " " << i << std::endl;
							return true;
						}
						if ((j - 1 >= 0) && (i + 1 < 8) && array_of_places[j - 1][i + 1].IsThereAMan && !array_of_places[j - 1][i + 1].WhiteTeam && (j - 2 >= 0) && (i + 2 < 8) &&  !array_of_places[j - 2][i + 2].IsThereAMan)
						{
							std::cout << "mo¿e biæ " << j << " " << i << std::endl;
							return true;
						}
					}
			}
		}
	}
	else
		//black player
	{
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; ++j)
			{
				if (array_of_places[j][i].IsThereAMan && !array_of_places[j][i].IsaKing)
					if (!array_of_places[j][i].WhiteTeam)
					{
						if (((j + 1 <8) && (i + 1 < 8) && array_of_places[j + 1][i + 1].IsThereAMan && array_of_places[j + 1][i + 1].WhiteTeam && (j + 2 <8) && (i + 2 < 8) && !array_of_places[j + 2][i + 2].IsThereAMan) ||
							(j + 1 < 8) && (i - 1 >= 0) && array_of_places[j + 1][i - 1].IsThereAMan && array_of_places[j + 1][i - 1].WhiteTeam && (j + 2 < 8) && (i - 2 >= 0) && !array_of_places[j + 2][i - 2].IsThereAMan)
						{
							std::cout << "mo¿e biæ " << j << " " << i << std::endl;
							return true;
							
						}
					}
			}
		}
	}
	return false;
}

void Board::markAllKingsThatCanBeMoveForPlayer()
{
			for (int i = 0; i < 8; i++)
			{
				for (int j = 0; j < 8; ++j)
				{
					if (RoundNumber % 2 == 0)
					{
						if (array_of_places[j][i].IsThereAMan && array_of_places[j][i].IsaKing && array_of_places[j][i].WhiteTeam)
						{
							int jl = j, il = i;
							if (--jl >= 0 && --il >= 0 && !array_of_places[jl][il].IsThereAMan) {
								array_of_places[j][i].CanIUseThisMAn = 1;
							}
							jl = j; il = i;
							if (--jl >= 0 && ++il < 8 && !array_of_places[jl][il].IsThereAMan) {
								array_of_places[j][i].CanIUseThisMAn = 1;
							}
							jl = j; il = i;
							if (++jl < 8 && ++il < 8 && !array_of_places[jl][il].IsThereAMan) {
								array_of_places[j][i].CanIUseThisMAn = 1;
							}
							jl = j; il = i;
							if (++jl < 8 && --il >= 0 && !array_of_places[jl][il].IsThereAMan) {
								array_of_places[j][i].CanIUseThisMAn = 1;
							}

						}
					}
					else
					{
						if (array_of_places[j][i].IsThereAMan && array_of_places[j][i].IsaKing && !array_of_places[j][i].WhiteTeam)
						{
							int jl = j, il = i;
							if (--jl >= 0 && --il >= 0 && !array_of_places[jl][il].IsThereAMan) {
								array_of_places[j][i].CanIUseThisMAn = 1;
							}
							jl = j; il = i;
							if (--jl >= 0 && ++il < 8 && !array_of_places[jl][il].IsThereAMan) {
								array_of_places[j][i].CanIUseThisMAn = 1;
							}
							jl = j; il = i;
							if (++jl < 8 && ++il < 8 && !array_of_places[jl][il].IsThereAMan) {
								array_of_places[j][i].CanIUseThisMAn = 1;
							}
							jl = j; il = i;
							if (++jl < 8 && --il >= 0 && !array_of_places[jl][il].IsThereAMan) {
								array_of_places[j][i].CanIUseThisMAn = 1;
							}

						}
					}
				}
			}
}

void Board::markAllFielsdWhereICanPutThisKing()
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; ++j)
		{
			if (RoundNumber % 2 == 0)
			{
				if (array_of_places[j][i].IsThereAMan && array_of_places[j][i].IsaKing && array_of_places[j][i].WhiteTeam && array_of_places[j][i].IsMarkToMoveFROM)
				{
					int jl = j, il = i;
					while (--jl >= 0 && --il >= 0 && !array_of_places[jl][il].IsThereAMan) {
						array_of_places[jl][il].CanIPutMarkedManThere = 1;
					}
					jl = j; il = i;
					while (--jl >= 0 && ++il < 8 && !array_of_places[jl][il].IsThereAMan) {
						array_of_places[jl][il].CanIPutMarkedManThere = 1;
					}
					jl = j; il = i;
					while (++jl < 8 && ++il < 8 && !array_of_places[jl][il].IsThereAMan) {
						array_of_places[jl][il].CanIPutMarkedManThere = 1;
					}
					jl = j; il = i;
					while (++jl < 8 && --il >= 0 && !array_of_places[jl][il].IsThereAMan) {
						array_of_places[jl][il].CanIPutMarkedManThere = 1;
					}

				}
			}
			else
			{
				if (array_of_places[j][i].IsThereAMan && array_of_places[j][i].IsaKing && !array_of_places[j][i].WhiteTeam  && array_of_places[j][i].IsMarkToMoveFROM)
				{
					int jl = j, il = i;
					while (--jl >= 0 && --il >= 0 && !array_of_places[jl][il].IsThereAMan) {
						array_of_places[jl][il].CanIPutMarkedManThere = 1;
					}
					jl = j; il = i;
					while (--jl >= 0 && ++il < 8 && !array_of_places[jl][il].IsThereAMan) {
						array_of_places[jl][il].CanIPutMarkedManThere = 1;
					}
					jl = j; il = i;
					while (++jl < 8 && ++il < 8 && !array_of_places[jl][il].IsThereAMan) {
						array_of_places[jl][il].CanIPutMarkedManThere = 1;
					}
					jl = j; il = i;
					while (++jl < 8 && --il >= 0 && !array_of_places[jl][il].IsThereAMan) {
						array_of_places[jl][il].CanIPutMarkedManThere = 1;
					}

				}
			}
		}
	}
}

