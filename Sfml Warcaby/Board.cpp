#include "Board.h"
#include "Calculation.h"
#include <iostream>
#include <random>
#include <time.h>




Board::Board()
{
	array_of_places = new place*[8];
	for (int i = 0; i < 8; i++)
	{
		array_of_places[i] = new place[8];
	}

}

void Board::selectRandomBEtingKing() {
	srand(time(NULL));
	int i = rand() % 8;
	int j = rand() % 8;
	bool done = 0;
	while (!done)
	{
		std::cout << "losujemy bijacego";
		while (i < 8 && !done) {
			while (j < 8 && !done) {
				if (array_of_places[j][i].CanToBeat && array_of_places[j][i].IsaKing) {
					array_of_places[j][i].IsMarkToMoveFROM = 1;
					array_of_places[j][i].BeastMode = 1;
					done = 1;
				}
				++j;
			}
			++i;
		}
		i = rand() % 8;
		j = rand() % 8;
	}
	std::cout << "nie losujemy";
}

void Board::selectRandomBEatingMan() {
	srand(time(NULL));
	int i = rand() % 8;
	int j = rand() % 8;
	bool done = 0;
	while (!done)
	{
		std::cout << "losujemy bijacego";
		while (i < 8 && !done) {
			while (j < 8 && !done) {
				if (array_of_places[j][i].CanToBeat && !array_of_places[j][i].IsaKing) {
					array_of_places[j][i].IsMarkToMoveFROM = 1;
					array_of_places[j][i].BeastMode = 1;
					done = 1;
				}
				++j;
			}
			++i;
		}
		i = rand() % 8;
		j = rand() % 8;
	}
	std::cout << "nie losujemy";
}

void Board::selectRandomMAnThatWOntDie() {
	bool Ucan = true;
		srand(time(NULL));
		int i = rand() % 8;
		int j = rand() % 8;
		int pj, pi;
		bool done = 0;
		while (!done)
		{
			std::cout << "losujemy!!!!";
			while (i < 8 && !done) {
				while (j < 8 && !done) {
					if (RoundNumber % 2 == 0) 
						{
							if (array_of_places[j][i].IsThereAMan && !array_of_places[j][i].IsaKing  && array_of_places[j][i].CanIUseThisMAn)
								if (array_of_places[j][i].WhiteTeam && !done)
								{
									if (((j - 1 >= 0) && (i - 1 >= 0) && !array_of_places[j - 1][i - 1].IsThereAMan) || (j - 1 >= 0) && (i + 1 < 8) && !array_of_places[j - 1][i + 1].IsThereAMan)
									{
										if (j - 2 >= 0 && i - 2 >= 0 && array_of_places[j - 2][i - 2].IsThereAMan && !done)
										{
											if (array_of_places[j - 2][i - 2].WhiteTeam)
												if (!done)
												{
													array_of_places[j - 1][i - 1].IsMArkToMoveTO = 1;
													array_of_places[j][i].IsMarkToMoveFROM = 1;
													array_of_places[j-1][i-1].CanIPutMarkedManThere = 1;
													done = 1;
												}
										}
										else
											if (!done)
											{
												array_of_places[j - 1][i - 1].IsMArkToMoveTO = 1;
												array_of_places[j][i].IsMarkToMoveFROM = 1;
												array_of_places[j-1][i-1].CanIPutMarkedManThere = 1;
												done = 1;
											}
									}
									if (j - 2 >= 0 && i + 2 < 8 && array_of_places[j - 2][i + 2].IsThereAMan && !done)
									{
										if (!done)
										{
											array_of_places[j - 1][i + 1].IsMArkToMoveTO = 1;
											array_of_places[j][i].IsMarkToMoveFROM = 1;
											array_of_places[j-1][i+1].CanIPutMarkedManThere = 1;
											done = 1;
										}
									}
									else
										if (!done)
										{
											array_of_places[j - 1][i + 1].IsMArkToMoveTO = 1;
											array_of_places[j][i].IsMarkToMoveFROM = 1;
											array_of_places[j-1][i+1].CanIPutMarkedManThere = 1;
											done = 1;
										}

								}
					}
					else 	//black player
					{						

						if (array_of_places[j][i].IsThereAMan)
							if (!array_of_places[j][i].WhiteTeam)
							{
								
								if (((j + 1 < 8) && (i + 1 < 8) && !array_of_places[j + 1][i + 1].IsThereAMan))
								{
									Ucan = true;
									int jh = j + 1;
									int ih = i + 1;
									if (jh + 1 < 8 && ih + 1 < 8 && array_of_places[jh + 1][ih + 1].IsThereAMan && array_of_places[jh + 1][ih + 1].WhiteTeam && !done) {
										Ucan = false;
									}
									if (jh - 1 >= 0 && ih + 1 < 8 && array_of_places[jh - 1][ih + 1].IsThereAMan && !done && array_of_places[jh - 1][ih + 1].WhiteTeam) {
										Ucan = false;
									}
									if (jh + 1 < 8 && ih - 1 >= 0 && array_of_places[jh + 1][ih - 1].IsThereAMan && !done && array_of_places[jh + 1][ih - 1].WhiteTeam) {
										Ucan = false;
									}
									if (jh - 1 >= 0 && ih - 1 >= 0 && array_of_places[jh - 1][ih - 1].IsThereAMan && !done && array_of_places[jh - 1][ih - 1].WhiteTeam) {
										Ucan = false;
									}
									//damka
									if (jh + 1 < 8 && ih + 1 < 8 && !array_of_places[jh + 1][ih + 1].IsThereAMan &&  !done) {
										pj = jh - 1;
										pi = ih - 1;
										while (pj >0 && pi>0 && !array_of_places[pj][pi].IsThereAMan)
										{
											--pj;
											--pi;
										}
										if (array_of_places[pj][pi].IsThereAMan && array_of_places[pj][pi].WhiteTeam && array_of_places[pj][pi].IsaKing)
										{
											Ucan = false;
										}
									}
									if (jh - 1 >= 0 && ih + 1 < 8 && !array_of_places[jh - 1][ih + 1].IsThereAMan && !done ) {
										pj = jh + 1;
										pi = ih - 1;
										while (pj <7 && pi>0 && !array_of_places[pj][pi].IsThereAMan)
										{
											++pj;
											--pi;
										}
										if (array_of_places[pj][pi].IsThereAMan && array_of_places[pj][pi].WhiteTeam && array_of_places[pj][pi].IsaKing)
										{
											Ucan = false;
										}
									}
									if (jh + 1 < 8 && ih - 1 >= 0 && array_of_places[jh + 1][ih - 1].IsThereAMan && !done ) {
										pj = jh - 1;
										pi = ih + 1;
										while (pj >0 && pi<7 && !array_of_places[pj][pi].IsThereAMan)
										{
											--pj;
											++pi;
										}
										if (array_of_places[pj][pi].IsThereAMan && array_of_places[pj][pi].WhiteTeam && array_of_places[pj][pi].IsaKing)
										{
											Ucan = false;
										}
									}
									if (jh - 1 >= 0 && ih - 1 >= 0 && array_of_places[jh - 1][ih - 1].IsThereAMan && !done) {
										pj = jh + 1;
										pi = ih + 1;
										while (pj <7 && pi<7 && !array_of_places[pj][pi].IsThereAMan)
										{
											++pj;
											++pi;
										}
										if (array_of_places[pj][pi].IsThereAMan && array_of_places[pj][pi].WhiteTeam && array_of_places[pj][pi].IsaKing)
										{
											Ucan = false;
										}
									}
									if (Ucan && !done) {
										array_of_places[jh][ih].IsMArkToMoveTO = 1;
										array_of_places[j][i].IsMarkToMoveFROM = 1;
										array_of_places[jh][ih].CanIPutMarkedManThere = 1;
										done = 1;
									}
								}
								if ((j + 1 < 8) && (i - 1 >= 0) && !array_of_places[j + 1][i - 1].IsThereAMan)
								{
									Ucan = true;
									int jh = j + 1;
									int ih = i - 1;
									if (jh + 1 < 8 && ih + 1 < 8 && array_of_places[jh + 1][ih + 1].IsThereAMan && array_of_places[jh + 1][ih + 1].WhiteTeam && !done) {
										Ucan = false;
									}
									if (jh - 1 >= 0 && ih + 1 < 8 && array_of_places[jh - 1][ih + 1].IsThereAMan && !done && array_of_places[jh - 1][ih + 1].WhiteTeam) {
										Ucan = false;
									}
									if (jh + 1 < 8 && ih - 1 >= 0 && array_of_places[jh + 1][ih - 1].IsThereAMan && !done && array_of_places[jh + 1][ih - 1].WhiteTeam) {
										Ucan = false;
									}
									if (jh - 1 >= 0 && ih - 1 >= 0 && array_of_places[jh - 1][ih - 1].IsThereAMan && !done && array_of_places[jh - 1][ih - 1].WhiteTeam) {
										Ucan = false;
									}
									//damka
									if (jh + 1 < 8 && ih + 1 < 8 && !array_of_places[jh + 1][ih + 1].IsThereAMan && !done) {
										pj = jh - 1;
										pi = ih - 1;
										while (pj >0 && pi>0 && !array_of_places[pj][pi].IsThereAMan)
										{
											--pj;
											--pi;
										}
										if (array_of_places[pj][pi].IsThereAMan && array_of_places[pj][pi].WhiteTeam && array_of_places[pj][pi].IsaKing)
										{
											Ucan = false;
										}
									}
									if (jh - 1 >= 0 && ih + 1 < 8 && !array_of_places[jh - 1][ih + 1].IsThereAMan && !done) {
										pj = jh + 1;
										pi = ih - 1;
										while (pj <7 && pi>0 && !array_of_places[pj][pi].IsThereAMan)
										{
											++pj;
											--pi;
										}
										if (array_of_places[pj][pi].IsThereAMan && array_of_places[pj][pi].WhiteTeam && array_of_places[pj][pi].IsaKing)
										{
											Ucan = false;
										}
									}
									if (jh + 1 < 8 && ih - 1 >= 0 && array_of_places[jh + 1][ih - 1].IsThereAMan && !done) {
										pj = jh - 1;
										pi = ih + 1;
										while (pj >0 && pi<7 && !array_of_places[pj][pi].IsThereAMan)
										{
											--pj;
											++pi;
										}
										if (array_of_places[pj][pi].IsThereAMan && array_of_places[pj][pi].WhiteTeam && array_of_places[pj][pi].IsaKing)
										{
											Ucan = false;
										}
									}
									if (jh - 1 >= 0 && ih - 1 >= 0 && array_of_places[jh - 1][ih - 1].IsThereAMan && !done) {
										pj = jh + 1;
										pi = ih + 1;
										while (pj <7 && pi<7 && !array_of_places[pj][pi].IsThereAMan)
										{
											++pj;
											++pi;
										}
										if (array_of_places[pj][pi].IsThereAMan && array_of_places[pj][pi].WhiteTeam && array_of_places[pj][pi].IsaKing)
										{
											Ucan = false;
										}
									}
									if (Ucan && !done) {
										array_of_places[jh][ih].IsMArkToMoveTO = 1;
										array_of_places[j][i].IsMarkToMoveFROM = 1;
										array_of_places[jh][ih].CanIPutMarkedManThere = 1;
										done = 1;
									}
								}
							}

					}
					
					++j;
				}
				++i;
			}
			i = rand() % 8;
			j = rand() % 8;
		}
		std::cout << "nie losujemy";
	}

bool Board::isAmanThatAfterMoveWontDie()
{
	int pj, pi;
	bool Ucan = true;
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
						if (((j - 1 >= 0) && (i - 1 >= 0) && !array_of_places[j - 1][i - 1].IsThereAMan) || (j - 1 >= 0) && (i + 1 <8) && !array_of_places[j - 1][i + 1].IsThereAMan)
						{
							if (j - 2 >= 0 && i -2>= 0 && array_of_places[j - 2][i - 2].IsThereAMan)
							{
								if (array_of_places[j - 2][i - 2].WhiteTeam)
									return true;
							}
							else
							{
								return true;
							}
						}
							if (j - 2 >= 0 && i + 2 <8 && array_of_places[j - 2][i + 2].IsThereAMan)
							{
								if (array_of_places[j - 2][i + 2].WhiteTeam)
									return true;
							}
							else
							{
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
				Ucan = true;
				if (array_of_places[j][i].IsThereAMan)
					if (!array_of_places[j][i].WhiteTeam)
					{
						if (((j + 1 < 8) && (i + 1 < 8) && !array_of_places[j + 1][i + 1].IsThereAMan))
						{
							Ucan = true;
							int jh = j + 1;
							int ih = i + 1;
							if (jh + 1 < 8 && ih + 1 < 8 && array_of_places[jh + 1][ih + 1].IsThereAMan && array_of_places[jh + 1][ih + 1].WhiteTeam) {
								Ucan = false;
							}
							if (jh - 1 >= 0 && ih + 1 < 8 && array_of_places[jh - 1][ih + 1].IsThereAMan && array_of_places[jh - 1][ih + 1].WhiteTeam) {
								Ucan = false;
							}
							if (jh + 1 < 8 && ih - 1 >= 0 && array_of_places[jh + 1][ih - 1].IsThereAMan  && array_of_places[jh + 1][ih - 1].WhiteTeam) {
								Ucan = false;
							}
							if (jh - 1 >= 0 && ih - 1 >= 0 && array_of_places[jh - 1][ih - 1].IsThereAMan  && array_of_places[jh - 1][ih - 1].WhiteTeam) {
								Ucan = false;
							}
							//damka
							if (jh + 1 < 8 && ih + 1 < 8 && !array_of_places[jh + 1][ih + 1].IsThereAMan) {
								pj = jh - 1;
								pi = ih - 1;
								while (pj >0 && pi>0 && !array_of_places[pj][pi].IsThereAMan)
								{
									--pj;
									--pi;
								}
								if (array_of_places[pj][pi].IsThereAMan && array_of_places[pj][pi].WhiteTeam && array_of_places[pj][pi].IsaKing)
								{
									Ucan = false;
								}
							}
							if (jh - 1 >= 0 && ih + 1 < 8 && !array_of_places[jh - 1][ih + 1].IsThereAMan) {
								pj = jh + 1;
								pi = ih - 1;
								while (pj <7 && pi>0 && !array_of_places[pj][pi].IsThereAMan)
								{
									++pj;
									--pi;
								}
								if (array_of_places[pj][pi].IsThereAMan && array_of_places[pj][pi].WhiteTeam && array_of_places[pj][pi].IsaKing)
								{
									Ucan = false;
								}
							}
							if (jh + 1 < 8 && ih - 1 >= 0 && array_of_places[jh + 1][ih - 1].IsThereAMan) {
								pj = jh - 1;
								pi = ih + 1;
								while (pj >0 && pi<7 && !array_of_places[pj][pi].IsThereAMan)
								{
									--pj;
									++pi;
								}
								if (array_of_places[pj][pi].IsThereAMan && array_of_places[pj][pi].WhiteTeam && array_of_places[pj][pi].IsaKing)
								{
									Ucan = false;
								}
							}
							if (jh - 1 >= 0 && ih - 1 >= 0 && array_of_places[jh - 1][ih - 1].IsThereAMan) {
								pj = jh + 1;
								pi = ih + 1;
								while (pj <7 && pi<7 && !array_of_places[pj][pi].IsThereAMan)
								{
									++pj;
									++pi;
								}
								if (array_of_places[pj][pi].IsThereAMan && array_of_places[pj][pi].WhiteTeam && array_of_places[pj][pi].IsaKing)
								{
									Ucan = false;
								}
							}
							if (Ucan)
							{
								return true;
							}
							if ((j + 1 < 8) && (i - 1 >= 0) && !array_of_places[j + 1][i - 1].IsThereAMan)
							{
								Ucan = true;
								int jh = j + 1;
								int ih = i - 1;
								if (jh + 1 < 8 && ih + 1 < 8 && array_of_places[jh + 1][ih + 1].IsThereAMan && array_of_places[jh + 1][ih + 1].WhiteTeam) {
									Ucan = false;
								}
								if (jh - 1 >= 0 && ih + 1 < 8 && array_of_places[jh - 1][ih + 1].IsThereAMan && array_of_places[jh - 1][ih + 1].WhiteTeam) {
									Ucan = false;
								}
								if (jh + 1 < 8 && ih - 1 >= 0 && array_of_places[jh + 1][ih - 1].IsThereAMan  && array_of_places[jh + 1][ih - 1].WhiteTeam) {
									Ucan = false;
								}
								if (jh - 1 >= 0 && ih - 1 >= 0 && array_of_places[jh - 1][ih - 1].IsThereAMan  && array_of_places[jh - 1][ih - 1].WhiteTeam) {
									Ucan = false;
								}
								//damka
								if (jh + 1 < 8 && ih + 1 < 8 && !array_of_places[jh + 1][ih + 1].IsThereAMan) {
									pj = jh - 1;
									pi = ih - 1;
									while (pj >0 && pi>0 && !array_of_places[pj][pi].IsThereAMan)
									{
										--pj;
										--pi;
									}
									if (array_of_places[pj][pi].IsThereAMan && array_of_places[pj][pi].WhiteTeam && array_of_places[pj][pi].IsaKing)
									{
										Ucan = false;
									}
								}
								if (jh - 1 >= 0 && ih + 1 < 8 && !array_of_places[jh - 1][ih + 1].IsThereAMan) {
									pj = jh + 1;
									pi = ih - 1;
									while (pj <7 && pi>0 && !array_of_places[pj][pi].IsThereAMan)
									{
										++pj;
										--pi;
									}
									if (array_of_places[pj][pi].IsThereAMan && array_of_places[pj][pi].WhiteTeam && array_of_places[pj][pi].IsaKing)
									{
										Ucan = false;
									}
								}
								if (jh + 1 < 8 && ih - 1 >= 0 && array_of_places[jh + 1][ih - 1].IsThereAMan) {
									pj = jh - 1;
									pi = ih + 1;
									while (pj >0 && pi<7 && !array_of_places[pj][pi].IsThereAMan)
									{
										--pj;
										++pi;
									}
									if (array_of_places[pj][pi].IsThereAMan && array_of_places[pj][pi].WhiteTeam && array_of_places[pj][pi].IsaKing)
									{
										Ucan = false;
									}
								}
								if (jh - 1 >= 0 && ih - 1 >= 0 && array_of_places[jh - 1][ih - 1].IsThereAMan) {
									pj = jh + 1;
									pi = ih + 1;
									while (pj <7 && pi<7 && !array_of_places[pj][pi].IsThereAMan)
									{
										++pj;
										++pi;
									}
									if (array_of_places[pj][pi].IsThereAMan && array_of_places[pj][pi].WhiteTeam && array_of_places[pj][pi].IsaKing)
									{
										Ucan = false;
									}
								}
								if (Ucan) {
									return true;
								}
							}
						}
					}

			}
		}

	}
	return false;
}

bool Board::isAMAnThatAfterBEtingWontDie() {
	if (RoundNumber % 2 == 0)
		//white player
	{
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; ++j)
			{
				if (array_of_places[j][i].IsThereAMan)
					if (array_of_places[j][i].WhiteTeam && !array_of_places[j][i].IsaKing)
					{
						if ((j - 1 >= 0) && (i - 1 >= 0) && array_of_places[j - 1][i - 1].IsThereAMan && !array_of_places[j - 1][i - 1].WhiteTeam && (j - 2 >= 0) && (i - 2 >= 0) && !array_of_places[j - 2][i - 2].IsThereAMan)
						{
							if (j - 3 >= 0 && i -3>= 0 && array_of_places[j - 3][i - 3].IsThereAMan)
							{
								if (array_of_places[j - 3][i - 3].WhiteTeam)
									return true;
							}
							else
							{
								return true;
							}
						}
						if ((j - 1 >= 0) && (i + 1 < 8) && array_of_places[j - 1][i + 1].IsThereAMan && !array_of_places[j - 1][i + 1].WhiteTeam && (j - 2 >= 0) && (i + 2 < 8) && !array_of_places[j - 2][i + 2].IsThereAMan)
						{
							if (j - 3 >= 0 && i +3 < 8 && array_of_places[j - 3][i + 3].IsThereAMan)
							{
								if (array_of_places[j - 3][i + 3].WhiteTeam)
									return true;
							}
							else
							{
								return true;
							}
						}
						if ((j + 1 <8) && (i - 1 >= 0) && array_of_places[j + 1][i - 1].IsThereAMan && !array_of_places[j + 1][i - 1].WhiteTeam && (j + 2 < 8) && (i - 2 >= 0) && !array_of_places[j + 2][i - 2].IsThereAMan)
						{
							if (j +3 < 8 && i -3 >= 0 && array_of_places[j + 3][i - 3].IsThereAMan)
							{
								if (array_of_places[j + 3][i - 3].WhiteTeam)
									return true;
							}
							else
							{
								return true;
							}
						}
						if ((j + 1<8) && (i + 1 < 8) && array_of_places[j + 1][i + 1].IsThereAMan && !array_of_places[j + 1][i + 1].WhiteTeam && (j + 2 < 8) && (i + 2 < 8) && !array_of_places[j + 2][i + 2].IsThereAMan)
						{
							if (j + 3 < 8 && i + 3 < 8 && array_of_places[j + 3][i + 3].IsThereAMan)
							{
								if (array_of_places[j + 3][i + 3].WhiteTeam)
									return true;
							}
							else
							{
								return true;
							}
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
					if (!array_of_places[j][i].WhiteTeam && !array_of_places[j][i].IsaKing)
					{
						if ((j + 1 < 8) && (i + 1 < 8) && array_of_places[j + 1][i + 1].IsThereAMan && array_of_places[j + 1][i + 1].WhiteTeam && (j + 2 < 8) && (i + 2 < 8) && !array_of_places[j + 2][i + 2].IsThereAMan)
						{
							if (j + 3 < 8 && i + 3 < 8 && array_of_places[j + 3][i + 3].IsThereAMan)
							{
								if (!array_of_places[j + 3][i + 3].WhiteTeam)
									return true;
							}
							else
							{
								return true;
							}
						}
						if ((j + 1 < 8) && (i - 1 >= 0) && array_of_places[j + 1][i - 1].IsThereAMan && array_of_places[j + 1][i - 1].WhiteTeam && (j + 2 < 8) && (i - 2 >= 0) && !array_of_places[j + 2][i - 2].IsThereAMan)
						{
							if (j + 3 < 8 && i - 3 >= 0 && array_of_places[j + 3][i - 3].IsThereAMan)
							{
								if (!array_of_places[j + 3][i - 3].WhiteTeam)
									return true;
							}
							else
							{
								return true;
							}
						}
						if ((j - 1 >= 0) && (i + 1 < 8) && array_of_places[j - 1][i + 1].IsThereAMan && array_of_places[j - 1][i + 1].WhiteTeam && (j - 2 >= 0) && (i + 2 < 8) && !array_of_places[j - 2][i + 2].IsThereAMan)
						{
							if (j -3 >= 0 && i + 3 < 8 && array_of_places[j - 3][i + 3].IsThereAMan)
							{
								if (!array_of_places[j - 3][i + 3].WhiteTeam)
									return true;
							}
							else
							{
								return true;
							}
						}
						if ((j - 1 >= 0) && (i - 1 >= 0) && array_of_places[j - 1][i - 1].IsThereAMan && array_of_places[j - 1][i - 1].WhiteTeam && (j - 2 >= 0) && (i - 2 >= 0) && !array_of_places[j - 2][i - 2].IsThereAMan)
						{
							if (j -3 >= 0 && i - 3 >=0 && array_of_places[j - 3][i - 3].IsThereAMan)
							{
								if (!array_of_places[j - 3][i - 3].WhiteTeam)
									return true;
							}
							else
							{
								return true;
							}
						}
					}
			}
		}
	}
	return false;
}

void Board::unmarkAllToFields() {
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; ++j)
		{
			array_of_places[j][i].IsMArkToMoveTO = 0;
		}
	}
}

sf::Vector2i Board::WhereIGOTo()
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; ++j)
		{
			if (array_of_places[j][i].IsMArkToMoveTO)
			{
				return sf::Vector2i((i+1)*boxSize + boxSize / 2, (j+1)*boxSize + boxSize / 2);
			}
		}
	}
}

void Board::SelectRandomManThat()
{
	srand(time(NULL));
	int i = rand() % 8;
	int j = rand() % 8;
	bool done = 0;
	while (!done)
	{
		std::cout << "losujemy";
		while (i < 8 && !done) {
			while (j < 8 && !done) {
				if (array_of_places[j][i].CanIUseThisMAn) {
					array_of_places[j][i].IsMarkToMoveFROM = 1;
					done = 1;
				}
				++j;
			}
			++i;
		}
	i = rand() % 8;
	j = rand() % 8;
	}
	std::cout << "nie losujemy";
	}

void Board::SelectRandomPlaceToGo() {
		srand(time(NULL));
		int i = rand() % 8;
		int j = rand() % 8;
		bool done = 0;
		while (!done)
		{
			std::cout << "randomowe miejsce do TO losujemy"<<std::endl;
			while (i < 8 && !done) {
				while (j < 8 && !done) {
					if (array_of_places[j][i].CanIPutMarkedManThere) {
						array_of_places[j][i].IsMArkToMoveTO = 1;
						done = 1;
					}
					++j;
				}
				++i;
			}
			i = rand() % 8;
			j = rand() % 8;
		}
		std::cout << "nie losujemy";
}

bool Board::isManThatCanMove()
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
						if (((j - 1 >= 0) && (i - 1 >= 0) && !array_of_places[j - 1][i - 1].IsThereAMan) || (j - 1 >= 0) && (i + 1 <8) && !array_of_places[j - 1][i + 1].IsThereAMan)
						{
							return	true;
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
						if (((j + 1 <8) && (i + 1 < 8) && !array_of_places[j + 1][i + 1].IsThereAMan) || (j + 1 < 8) && (i - 1 >= 0) && !array_of_places[j + 1][i - 1].IsThereAMan)
						{
							return true;
						}
					}
			}
		}
	}
	return false;
}

bool Board::isKnigThatCanMove()
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
						return true;
					}
					jl = j; il = i;
					if (--jl >= 0 && ++il < 8 && !array_of_places[jl][il].IsThereAMan) {
						return true;
					}
					jl = j; il = i;
					if (++jl < 8 && ++il < 8 && !array_of_places[jl][il].IsThereAMan) {
						return true;
					}
					jl = j; il = i;
					if (++jl < 8 && --il >= 0 && !array_of_places[jl][il].IsThereAMan) {
						return true;
					}

				}
			}
			else
			{
				if (array_of_places[j][i].IsThereAMan && array_of_places[j][i].IsaKing && !array_of_places[j][i].WhiteTeam)
				{
					int jl = j, il = i;
					if (--jl >= 0 && --il >= 0 && !array_of_places[jl][il].IsThereAMan) {
						return true;
					}
					jl = j; il = i;
					if (--jl >= 0 && ++il < 8 && !array_of_places[jl][il].IsThereAMan) {
						return true;
					}
					jl = j; il = i;
					if (++jl < 8 && ++il < 8 && !array_of_places[jl][il].IsThereAMan) {
						return true;
					}
					jl = j; il = i;
					if (++jl < 8 && --il >= 0 && !array_of_places[jl][il].IsThereAMan) {
						return true;
					}

				}
			}
		}
	}
	return false;
}

bool Board::waspalcepress(place place, sf::Vector2i mouse_position)
{
	if ((place.broders.left < mouse_position.x) && (place.broders.right > mouse_position.x) && (place.broders.up < mouse_position.y) && (place.broders.down > mouse_position.y))
	{
		return true;
	}
	return false;
}

void Board::SetBoardOnStartPoint()
{
	white_player_mans = 12;
	black_player_mans = 12;
	RoundNumber = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; ++j) {
			array_of_places[j][i].HaveIAcces = 0;
			array_of_places[j][i].IsThereAMan = 0;
			array_of_places[j][i].WhiteTeam = 1;
			array_of_places[j][i].IsaKing = 0;
			array_of_places[j][i].IsMarkToMoveFROM = 0;
			array_of_places[j][i].IsMArkToMoveTO = 0;
			array_of_places[j][i].CanIPutMarkedManThere = 0;
			array_of_places[j][i].CanToBeat = 0;
			array_of_places[j][i].BeastMode = 0;
		}
	}
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
	saveB.broders.down = boxSize * 9;
	saveB.broders.up = boxSize * 8;
	saveB.broders.left = boxSize * 9;
	saveB.broders.right = boxSize * (167.0f / 10);

	loadB.broders.down = boxSize * 7.5f;
	loadB.broders.up = boxSize * 6.5f;
	loadB.broders.left = boxSize * 9;
	loadB.broders.right = boxSize * (167.0f / 10);

	resetB.broders.down = boxSize *6.0f;
	resetB.broders.up = boxSize * 5.0f;
	resetB.broders.left = boxSize * 9;
	resetB.broders.right = boxSize * (167.0f / 10);

	botB.broders.down = boxSize *4.5f;
	botB.broders.up = boxSize * 3.4;
	botB.broders.left = boxSize * 9;
	botB.broders.right = boxSize * (167.0f / 10);
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
					if (array_of_places[j][i].CanToBeat && !array_of_places[j][i].IsaKing)
					{
						if ((j - 2 >= 0) && (i - 2 >= 0) && !array_of_places[j - 2][i - 2].IsThereAMan && array_of_places[j - 1][i - 1].IsThereAMan && !array_of_places[j - 1][i - 1].WhiteTeam)
						{
							array_of_places[j - 2][i - 2].CanIPutMarkedManThere = 1;
						}
						if ((j - 2 >= 0) && (i + 2 <8) && !array_of_places[j - 2][i + 2].IsThereAMan && array_of_places[j - 1][i + 1].IsThereAMan && !array_of_places[j - 1][i + 1].WhiteTeam)
						{
							array_of_places[j - 2][i + 2].CanIPutMarkedManThere = 1;
						}
						if ((j + 1 <8) && (i - 1 >= 0) && array_of_places[j + 1][i - 1].IsThereAMan && !array_of_places[j + 1][i - 1].WhiteTeam && (j + 2 < 8) && (i - 2 >= 0) && !array_of_places[j + 2][i - 2].IsThereAMan)
						{
							array_of_places[j + 2][i - 2].CanIPutMarkedManThere = 1;
						}
						if ((j + 1<8) && (i + 1 < 8) && array_of_places[j + 1][i + 1].IsThereAMan && !array_of_places[j + 1][i + 1].WhiteTeam && (j + 2 < 8) && (i + 2 < 8) && !array_of_places[j + 2][i + 2].IsThereAMan)
						{
							array_of_places[j + 2][i + 2].CanIPutMarkedManThere = 1;
						}
					}
					else
					{
						if(!array_of_places[j][i].IsaKing)
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
					if (array_of_places[j][i].CanToBeat && !array_of_places[j][i].IsaKing)
					{
						if ((j + 2 <8) && (i + 2 < 8) && !array_of_places[j + 2][i + 2].IsThereAMan && array_of_places[j + 1][i + 1].IsThereAMan && array_of_places[j + 1][i + 1].WhiteTeam)
						{
							array_of_places[j + 2][i + 2].CanIPutMarkedManThere = 1;
						}
						if ((j + 2 < 8) && (i - 2 >= 0) && !array_of_places[j + 2][i - 2].IsThereAMan && array_of_places[j + 1][i - 1].IsThereAMan && array_of_places[j + 1][i - 1].WhiteTeam)
						{
							array_of_places[j + 2][i - 2].CanIPutMarkedManThere = 1;
						}
						if ((j - 2 >=0) && (i + 2 < 8) && !array_of_places[j - 2][i + 2].IsThereAMan && array_of_places[j - 1][i + 1].IsThereAMan && array_of_places[j - 1][i + 1].WhiteTeam)
						{
							array_of_places[j - 2][i + 2].CanIPutMarkedManThere = 1;
						}
						if ((j - 2 >= 0) && (i - 2 >= 0) && !array_of_places[j - 2][i - 2].IsThereAMan && array_of_places[j - 1][i - 1].IsThereAMan && array_of_places[j - 1][i - 1].WhiteTeam)
						{
							array_of_places[j - 2][i - 2].CanIPutMarkedManThere = 1;
						}
					}
					else
					{
						if (!array_of_places[j][i].IsaKing)
						{
							if (((j + 1 < 8) && (i + 1 < 8) && !array_of_places[j + 1][i + 1].IsThereAMan))
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
}

bool Board::isThereManinBestMode()
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; ++j)
		{
			if (array_of_places[j][i].IsThereAMan && !array_of_places[j][i].IsaKing && array_of_places[j][i].BeastMode)
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
}

void Board::BeatingMan(sf::RenderWindow &gameWindow) {
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; ++j)
		{
			array_of_places[j][i].BeastMode = 0;
		}
	}
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

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; ++j)
		{
			if (array_of_places[j][i].IsMArkToMoveTO)
			{
				jto = j;
				ito = i;
				get = true;
			}
		}
	}

	while (!get)
	{
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; ++j)
			{
				if (waspalcepress(array_of_places[j][i], position) && array_of_places[j][i].CanIPutMarkedManThere)
				{
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

	std::cout << "jan PAPAJ";
	array_of_places[jto][ito].IsThereAMan= 1;
	array_of_places[jto][ito].WhiteTeam = array_of_places[jfrom][ifrom].WhiteTeam;
	unmarkAllFields();
	if (RoundNumber % 2 == 0)
	{
		if (jto <jfrom && ito > ifrom)
		{
			array_of_places[jfrom - 1][ifrom + 1].IsThereAMan = 0;
			array_of_places[jfrom - 1][ifrom + 1].IsaKing = 0;
		}
		if (jto <jfrom && ito < ifrom)
		{
			array_of_places[jfrom - 1][ifrom - 1].IsThereAMan = 0;
			array_of_places[jfrom - 1][ifrom - 1].IsaKing = 0;
		}
		if (jto >jfrom && ito > ifrom)
		{
			array_of_places[jfrom + 1][ifrom + 1].IsThereAMan = 0;
			array_of_places[jfrom + 1][ifrom + 1].IsaKing = 0;
		}
		if (jto >jfrom && ito < ifrom)
		{
			array_of_places[jfrom + 1][ifrom - 1].IsThereAMan = 0;
			array_of_places[jfrom + 1][ifrom - 1].IsaKing = 0;
		}
		--black_player_mans;
	}
	else
	{
		if (jto >jfrom && ito > ifrom)
			array_of_places[jfrom + 1][ifrom + 1].IsThereAMan = 0;
		if (jto >jfrom && ito < ifrom)
			array_of_places[jfrom + 1][ifrom - 1].IsThereAMan = 0;
		if (jto <jfrom && ito > ifrom)
			array_of_places[jfrom - 1][ifrom + 1].IsThereAMan = 0;
		if (jto <jfrom && ito < ifrom)
			array_of_places[jfrom - 1][ifrom - 1].IsThereAMan = 0;
		--white_player_mans;
	}


	int j = jto, i = ito;
	if (RoundNumber % 2 == 0)
		//white player
	{
		if (j+2<7)
			if (array_of_places[j][i].IsThereAMan && !array_of_places[j][i].IsaKing)
				if (array_of_places[j][i].WhiteTeam)
				{
					if ((j - 1 >= 0) && (i - 1 >= 0) && array_of_places[j - 1][i - 1].IsThereAMan && !array_of_places[j - 1][i - 1].WhiteTeam && j - 2 >= 0 && (i - 2 >= 0) && !array_of_places[j - 2][i - 2].IsThereAMan)
					{

						array_of_places[j][i].IsMarkToMoveFROM = 1;
						array_of_places[j][i].CanToBeat = 1;
						array_of_places[j][i].BeastMode = 1;
						array_of_places[j - 2][i - 2].CanIPutMarkedManThere = 1;
					}
					if ((j - 1 >= 0) && (i + 1 < 8) && array_of_places[j - 1][i + 1].IsThereAMan && !array_of_places[j - 1][i + 1].WhiteTeam && (j - 2 >= 0) && (i + 2 < 8) && !array_of_places[j - 2][i + 2].IsThereAMan)
					{
						array_of_places[j][i].IsMarkToMoveFROM = 1;
						array_of_places[j][i].CanToBeat = 1;
						array_of_places[j][i].BeastMode = 1;
						array_of_places[j - 2][i + 2].CanIPutMarkedManThere = 1;
					}
					if ((j + 1 <8) && (i - 1 >= 0) && array_of_places[j + 1][i - 1].IsThereAMan && !array_of_places[j + 1][i - 1].WhiteTeam && (j + 2 < 8) && (i - 2 >= 0) && !array_of_places[j + 2][i - 2].IsThereAMan)
					{
						array_of_places[j][i].IsMarkToMoveFROM = 1;
						array_of_places[j][i].CanToBeat = 1;
						array_of_places[j][i].BeastMode = 1;
						array_of_places[j + 2][i - 2].CanIPutMarkedManThere = 1;
					}
					if ((j + 1<8) && (i + 1 < 8) && array_of_places[j + 1][i + 1].IsThereAMan && !array_of_places[j + 1][i + 1].WhiteTeam && (j + 2 < 8) && (i + 2 < 8) && !array_of_places[j + 2][i + 2].IsThereAMan)
					{
						array_of_places[j][i].IsMarkToMoveFROM = 1;
						array_of_places[j][i].CanToBeat = 1;
						array_of_places[j][i].BeastMode = 1;
						array_of_places[j + 2][i + 2].CanIPutMarkedManThere = 1;
					}

				}

	}
	else
		//black player
	{
		if (j-2>0)
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
					if ((j - 1 >= 0) && (i + 1 < 8) && array_of_places[j - 1][i + 1].IsThereAMan && array_of_places[j - 1][i + 1].WhiteTeam && (j - 2 >= 0) && (i + 2 < 8) && !array_of_places[j - 2][i + 2].IsThereAMan)
					{
						array_of_places[j][i].IsMarkToMoveFROM = 1;
						array_of_places[j][i].CanToBeat = 1;
						array_of_places[j][i].BeastMode = 1;
						array_of_places[j - 2][i + 2].CanIPutMarkedManThere = 1;

					}
					if ((j - 1 >= 0) && (i - 1 >= 0) && array_of_places[j - 1][i - 1].IsThereAMan && array_of_places[j - 1][i - 1].WhiteTeam && (j - 2 >= 0) && (i - 2 >= 0) && !array_of_places[j - 2][i - 2].IsThereAMan)
					{
						array_of_places[j][i].IsMarkToMoveFROM = 1;
						array_of_places[j][i].CanToBeat = 1;
						array_of_places[j][i].BeastMode = 1;
						array_of_places[j - 2][i - 2].CanIPutMarkedManThere = 1;
					}
				}
		}
	}
	std::cout << "kunic" << std::endl;
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
					if (array_of_places[j][i].WhiteTeam && !array_of_places[j][i].IsaKing)
					{
						if ((j - 1 >= 0) && (i - 1 >= 0) && array_of_places[j - 1][i - 1].IsThereAMan && !array_of_places[j - 1][i - 1].WhiteTeam && (j - 2 >= 0) && (i - 2 >= 0) && !array_of_places[j - 2][i - 2].IsThereAMan)
						{
							array_of_places[j][i].CanToBeat = 1;
						}
						if ((j - 1 >= 0) && (i + 1 < 8) && array_of_places[j - 1][i + 1].IsThereAMan && !array_of_places[j - 1][i + 1].WhiteTeam && (j - 2 >= 0) && (i + 2 < 8) && !array_of_places[j - 2][i + 2].IsThereAMan)
						{
							array_of_places[j][i].CanToBeat = 1;
						}
						if ((j + 1 <8) && (i - 1 >= 0) && array_of_places[j + 1][i - 1].IsThereAMan && !array_of_places[j + 1][i - 1].WhiteTeam && (j + 2 < 8) && (i - 2 >= 0) && !array_of_places[j + 2][i - 2].IsThereAMan)
						{
							array_of_places[j][i].CanToBeat = 1;
						}
						if ((j + 1<8) && (i + 1 < 8) && array_of_places[j + 1][i + 1].IsThereAMan && !array_of_places[j + 1][i + 1].WhiteTeam && (j + 2 < 8) && (i + 2 < 8) && !array_of_places[j + 2][i + 2].IsThereAMan)
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
					if (!array_of_places[j][i].WhiteTeam && !array_of_places[j][i].IsaKing)
					{
						if ((j + 1 < 8) && (i + 1 < 8) && array_of_places[j + 1][i + 1].IsThereAMan && array_of_places[j + 1][i + 1].WhiteTeam && (j + 2 < 8) && (i + 2 < 8) && !array_of_places[j + 2][i + 2].IsThereAMan)
							
						{
							array_of_places[j][i].CanToBeat = 1;
						}
						if ((j + 1 < 8) && (i - 1 >= 0) && array_of_places[j + 1][i - 1].IsThereAMan && array_of_places[j + 1][i - 1].WhiteTeam && (j + 2 < 8) && (i - 2 >= 0) && !array_of_places[j + 2][i - 2].IsThereAMan)
						{
							array_of_places[j][i].CanToBeat = 1;
						}
						if ((j -1 >=0) && (i + 1 < 8) && array_of_places[j - 1][i + 1].IsThereAMan && array_of_places[j - 1][i + 1].WhiteTeam && (j -2 >=0) && (i + 2 < 8) && !array_of_places[j -2 ][i + 2].IsThereAMan)

						{
							array_of_places[j][i].CanToBeat = 1;
						}
						if ((j - 1 >=0) && (i - 1 >= 0) && array_of_places[j - 1][i - 1].IsThereAMan && array_of_places[j - 1][i - 1].WhiteTeam && (j - 2 >=0) && (i - 2 >= 0) && !array_of_places[j - 2][i - 2].IsThereAMan)
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
							return true;
						}
						if ((j - 1 >= 0) && (i + 1 < 8) && array_of_places[j - 1][i + 1].IsThereAMan && !array_of_places[j - 1][i + 1].WhiteTeam && (j - 2 >= 0) && (i + 2 < 8) &&  !array_of_places[j - 2][i + 2].IsThereAMan)
						{
							return true;
						}
						if ((j + 1 <8) && (i - 1 >= 0) && array_of_places[j + 1][i - 1].IsThereAMan && !array_of_places[j + 1][i - 1].WhiteTeam && (j + 2 < 8) && (i - 2 >= 0) && !array_of_places[j + 2][i - 2].IsThereAMan)
						{
							return true;
						}
						if ((j + 1<8) && (i + 1 < 8) && array_of_places[j + 1][i + 1].IsThereAMan && !array_of_places[j + 1][i + 1].WhiteTeam && (j + 2 < 8) && (i + 2 < 8) && !array_of_places[j + 2][i + 2].IsThereAMan)
						{
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
						if ((j + 1 <8) && (i + 1 < 8) && array_of_places[j + 1][i + 1].IsThereAMan && array_of_places[j + 1][i + 1].WhiteTeam && (j + 2 <8) && (i + 2 < 8) && !array_of_places[j + 2][i + 2].IsThereAMan)
						{
							return true;
							
						}
						if ((j + 1 < 8) && (i - 1 >= 0) && array_of_places[j + 1][i - 1].IsThereAMan && array_of_places[j + 1][i - 1].WhiteTeam && (j + 2 < 8) && (i - 2 >= 0) && !array_of_places[j + 2][i - 2].IsThereAMan)
						{
						return true;
						}
						if ((j -1>=0) && (i + 1 < 8) && array_of_places[j - 1][i + 1].IsThereAMan && array_of_places[j - 1][i + 1].WhiteTeam && (j -2>=0) && (i + 2 < 8) && !array_of_places[j - 2][i + 2].IsThereAMan)
						{
							return true;

						}
						if ((j -1>=0) && (i - 1 >= 0) && array_of_places[j - 1][i - 1].IsThereAMan && array_of_places[j - 1][i - 1].WhiteTeam && (j -2>=0) && (i - 2 >= 0) && !array_of_places[j - 2][i - 2].IsThereAMan)
						{
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
				if (array_of_places[j][i].IsThereAMan && array_of_places[j][i].IsaKing && array_of_places[j][i].WhiteTeam && array_of_places[j][i].CanToBeat && array_of_places[j][i].IsMarkToMoveFROM)
				{
					int jh = j + 1, ih = i + 1;
					while (jh < 7 && ih < 7)
					{
						if (array_of_places[jh][ih].IsThereAMan && !array_of_places[jh][ih].WhiteTeam && !array_of_places[jh + 1][ih + 1].IsThereAMan)
						{
							jh++;
							ih++;
							while (jh<=7&& ih <= 7 && !array_of_places[jh][ih].IsThereAMan)
							{
								array_of_places[jh][ih].CanIPutMarkedManThere = 1;
								++jh;
								++ih;
							}
							break;
						}
						++ih;
						++jh;
					}
					jh = j + 1; ih = i - 1;
					while (jh < 7 && ih >0)
					{
						if (array_of_places[jh][ih].IsThereAMan && !array_of_places[jh][ih].WhiteTeam && !array_of_places[jh + 1][ih - 1].IsThereAMan)
						{
							jh++;
							ih--;
							while (jh<=7 && ih >=0 && !array_of_places[jh][ih].IsThereAMan)
							{
								array_of_places[jh][ih].CanIPutMarkedManThere = 1;
								++jh;
								--ih;
							}
							break;
						}
						++jh;
						--ih;
					}
					jh = j - 1; ih = i + 1;
					while (jh > 0 && ih < 7)
					{
						if (array_of_places[jh][ih].IsThereAMan && !array_of_places[jh][ih].WhiteTeam && !array_of_places[jh - 1][ih + 1].IsThereAMan)
						{
							jh--;
							ih++;
							while (jh>=0 && ih <= 7 && !array_of_places[jh][ih].IsThereAMan)
							{
								array_of_places[jh][ih].CanIPutMarkedManThere = 1;
								--jh;
								++ih;
							}
							break;
						}
						jh--;
						ih++;
					}
					jh = j - 1; ih = i - 1;
					while (jh > 0 && ih > 0)
					{
						if (array_of_places[jh][ih].IsThereAMan && !array_of_places[jh][ih].WhiteTeam && !array_of_places[jh - 1][ih - 1].IsThereAMan)
						{
							jh--;
							ih--;
							while (jh>=0 && ih >=0 && !array_of_places[jh][ih].IsThereAMan)
							{
								array_of_places[jh][ih].CanIPutMarkedManThere = 1;
								--jh;
								--ih;
							}
							break;
						}
						jh--;
						ih--;
					}
				}
				else
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
				if (array_of_places[j][i].IsThereAMan && array_of_places[j][i].IsaKing && !array_of_places[j][i].WhiteTeam && array_of_places[j][i].CanToBeat && array_of_places[j][i].IsMarkToMoveFROM)
				{
					int jh = j + 1, ih = i + 1;
					while (jh < 7 && ih < 7)
					{
						if (array_of_places[jh][ih].IsThereAMan && array_of_places[jh][ih].WhiteTeam && !array_of_places[jh + 1][ih + 1].IsThereAMan)
						{
							jh++;
							ih++;
							while (jh <=7 && ih <=7 && !array_of_places[jh][ih].IsThereAMan)
							{
								std::cout << jh << ih;
								array_of_places[jh][ih].CanIPutMarkedManThere = 1;
								++jh;
								++ih;
							}
							break;
						}
						++ih;
						++jh;
					}
					jh = j + 1; ih = i - 1;
					while (jh < 7 && ih >0)
					{
						if (array_of_places[jh][ih].IsThereAMan && array_of_places[jh][ih].WhiteTeam && !array_of_places[jh + 1][ih - 1].IsThereAMan)
						{
							jh++;
							ih--;
							while (jh <=7 && ih >= 0 && !array_of_places[jh][ih].IsThereAMan)
							{
								std::cout << jh << ih;
								array_of_places[jh][ih].CanIPutMarkedManThere = 1;
								++jh;
								--ih;
							}
							break;
						}
						++jh;
						--ih;
					}
					jh = j - 1; ih = i + 1;
					while (jh > 0 && ih < 7)
					{
						if (array_of_places[jh][ih].IsThereAMan && array_of_places[jh][ih].WhiteTeam && !array_of_places[jh - 1][ih + 1].IsThereAMan)
						{
							jh--;
							ih++;
							while (jh >= 0 && ih <= 7 && !array_of_places[jh][ih].IsThereAMan)
							{
								array_of_places[jh][ih].CanIPutMarkedManThere = 1;
								--jh;
								++ih;
							}
							break;
						}
						jh--;
						ih++;
					}
					jh = j - 1; ih = i - 1;
					while (jh > 0 && ih > 0)
					{
						if (array_of_places[jh][ih].IsThereAMan && array_of_places[jh][ih].WhiteTeam && !array_of_places[jh - 1][ih - 1].IsThereAMan)
						{
							jh--;
							ih--;
							while (jh >= 0 && ih >= 0 && !array_of_places[jh][ih].IsThereAMan)
							{
								array_of_places[jh][ih].CanIPutMarkedManThere = 1;
								--jh;
								--ih;
							}
							break;
						}
						jh--;
						ih--;
					}
				}
				else
				if (array_of_places[j][i].IsThereAMan && array_of_places[j][i].IsaKing && !array_of_places[j][i].WhiteTeam && !array_of_places[j][i].CanToBeat && array_of_places[j][i].IsMarkToMoveFROM)
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

bool Board::isKingThatCanToBeat()
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; ++j)
		{
			if (RoundNumber % 2 == 0)
			{
				if (array_of_places[j][i].IsThereAMan && array_of_places[j][i].IsaKing && array_of_places[j][i].WhiteTeam)
				{
					int jh = j + 1, ih = i + 1;
					while (jh < 7 && ih < 7)
					{
						if (array_of_places[jh][ih].IsThereAMan && array_of_places[jh + 1][ih + 1].IsThereAMan)
							break;
						if (array_of_places[jh][ih].IsThereAMan && !array_of_places[jh][ih].WhiteTeam && !array_of_places[jh + 1][ih + 1].IsThereAMan)
						{
							std::cout << "####" << jh << " " << ih << std::endl;
							return true;
						}
						++ih;
						++jh;
					}
					jh = j + 1; ih = i - 1;
					while (jh < 7 && ih >0)
					{
						if (array_of_places[jh][ih].IsThereAMan && array_of_places[jh + 1][ih - 1].IsThereAMan)
							break;
						if (array_of_places[jh][ih].IsThereAMan && !array_of_places[jh][ih].WhiteTeam && !array_of_places[jh + 1][ih - 1].IsThereAMan)
						{
							std::cout << "####" << jh << " " << ih << std::endl;
							return true;
						}
						++jh;
						--ih;
					}
					jh = j - 1; ih = i + 1;
					while (jh > 0 && ih < 7)
					{
						if (array_of_places[jh][ih].IsThereAMan && array_of_places[jh - 1][ih + 1].IsThereAMan)
							break;
						if (array_of_places[jh][ih].IsThereAMan && !array_of_places[jh][ih].WhiteTeam && !array_of_places[jh - 1][ih + 1].IsThereAMan)
						{
							std::cout << "####" << jh << " " << ih << std::endl;
							return true;
						}
						jh--;
						ih++;
					}
					jh = j - 1; ih = i - 1;
					while (jh > 0 && ih > 0)
					{
						if (array_of_places[jh][ih].IsThereAMan && array_of_places[jh - 1][ih + 1].IsThereAMan)
							break;
						if (array_of_places[jh][ih].IsThereAMan && !array_of_places[jh][ih].WhiteTeam && !array_of_places[jh - 1][ih - 1].IsThereAMan)
						{
							std::cout << "####" << jh << " " << ih << std::endl;
							return true;
						}
						jh--;
						ih--;
					}
				}
			}
			else
			{
				if (array_of_places[j][i].IsThereAMan && array_of_places[j][i].IsaKing && !array_of_places[j][i].WhiteTeam)
				{
					int jh = j + 1, ih = i + 1;
					while (jh < 7 && ih < 7)
					{
						if (array_of_places[jh][ih].IsThereAMan && array_of_places[jh + 1][ih + 1].IsThereAMan)
							break;
						if (array_of_places[jh][ih].IsThereAMan && array_of_places[jh][ih].WhiteTeam && !array_of_places[jh + 1][ih + 1].IsThereAMan)
						{
							std::cout << "####" << jh << " " << ih << std::endl;
							return true;
						}
						++ih;
						++jh;
					}
					jh = j + 1; ih = i - 1;
					while (jh < 7 && ih >0)
					{
						if (array_of_places[jh][ih].IsThereAMan && array_of_places[jh + 1][ih - 1].IsThereAMan)
							break;
						if (array_of_places[jh][ih].IsThereAMan && array_of_places[jh][ih].WhiteTeam && !array_of_places[jh + 1][ih - 1].IsThereAMan)
						{
							std::cout <<"####"<< jh << " " << ih << std::endl;
							return true;
						}
						++jh;
						--ih;
					}
					jh = j - 1; ih = i + 1;
					while (jh > 0 && ih < 7)
					{
						if (array_of_places[jh][ih].IsThereAMan && array_of_places[jh - 1][ih + 1].IsThereAMan)
							break;
						if (array_of_places[jh][ih].IsThereAMan && array_of_places[jh][ih].WhiteTeam && !array_of_places[jh - 1][ih + 1].IsThereAMan)
						{
							std::cout << "####" << jh << " " << ih << std::endl;
							return true;
						}
						jh--;
						ih++;
					}
					jh = j - 1; ih = i - 1;
					while (jh > 0 && ih > 0)
					{
						if (array_of_places[jh][ih].IsThereAMan && array_of_places[jh - 1][ih - 1].IsThereAMan)
							break;
						if (array_of_places[jh][ih].IsThereAMan && array_of_places[jh][ih].WhiteTeam && !array_of_places[jh - 1][ih - 1].IsThereAMan)
						{
							std::cout << "####" << jh << " " << ih << std::endl;
							return true;
						}
						jh--;
						ih--;
					}
				}
				}
			}
		}

	return false;
}

void Board::MarkAllKingsThatCanTOBeat()
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; ++j)
		{
			if (RoundNumber % 2 == 0)
			{
				if (array_of_places[j][i].IsThereAMan && array_of_places[j][i].IsaKing && array_of_places[j][i].WhiteTeam)
				{
					int jh = j + 1, ih = i + 1;
					while (jh < 7 && ih < 7)
					{
						if (array_of_places[jh][ih].IsThereAMan && array_of_places[jh + 1][ih + 1].IsThereAMan)
							break;
						if (array_of_places[jh][ih].IsThereAMan && !array_of_places[jh][ih].WhiteTeam && !array_of_places[jh + 1][ih + 1].IsThereAMan)
						{
							array_of_places[j][i].CanToBeat = 1;
							std::cout << "####" << jh << " " << ih << std::endl;
						}
						++ih;
						++jh;
					}
					jh = j + 1; ih = i - 1;
					while (jh < 6 && ih >0)
					{
						if (array_of_places[jh][ih].IsThereAMan && array_of_places[jh + 1][ih - 1].IsThereAMan)
							break;
						if (array_of_places[jh][ih].IsThereAMan && !array_of_places[jh][ih].WhiteTeam && !array_of_places[jh + 1][ih - 1].IsThereAMan)
						{
							array_of_places[j][i].CanToBeat = 1;
							std::cout << "####" << jh << " " << ih << std::endl;
						}
						++jh;
						--ih;
					}
					jh = j - 1; ih = i + 1;
					while (jh > 0 && ih < 7)
					{
						if (array_of_places[jh][ih].IsThereAMan && array_of_places[jh - 1][ih + 1].IsThereAMan)
							break;
						if (array_of_places[jh][ih].IsThereAMan && !array_of_places[jh][ih].WhiteTeam && !array_of_places[jh - 1][ih + 1].IsThereAMan)
						{
							array_of_places[j][i].CanToBeat = 1;
							std::cout << "####" << jh << " " << ih << std::endl;
						}
						jh--;
						ih++;
					}
					jh = j - 1; ih = i - 1;
					while (jh > 0 && ih > 0)
					{
						if (array_of_places[jh][ih].IsThereAMan && array_of_places[jh - 1][ih - 1].IsThereAMan)
							break;
						if (array_of_places[jh][ih].IsThereAMan && !array_of_places[jh][ih].WhiteTeam && !array_of_places[jh - 1][ih - 1].IsThereAMan)
						{
							array_of_places[j][i].CanToBeat = 1;
							std::cout << "####" << jh << " " << ih << std::endl;
						}
						jh--;
						ih--;
					}
				}
			}
				else
				{
					if (array_of_places[j][i].IsThereAMan && array_of_places[j][i].IsaKing && !array_of_places[j][i].WhiteTeam)
					{
						int jh = j + 1, ih = i + 1;
						while (jh < 7 && ih < 7)
						{
							if (array_of_places[jh][ih].IsThereAMan && array_of_places[jh + 1][ih + 1].IsThereAMan)
								break;
							if (array_of_places[jh][ih].IsThereAMan && array_of_places[jh][ih].WhiteTeam && !array_of_places[jh + 1][ih + 1].IsThereAMan)
							{
								array_of_places[j][i].CanToBeat = 1;
								std::cout << "####" << jh << " " << ih << std::endl;
							}
							++ih;
							++jh;
						}
						jh = j + 1; ih = i - 1;
						while (jh < 7 && ih >0)
						{
							if (array_of_places[jh][ih].IsThereAMan && array_of_places[jh + 1][ih - 1].IsThereAMan)
								break;
							if (array_of_places[jh][ih].IsThereAMan && array_of_places[jh][ih].WhiteTeam && !array_of_places[jh + 1][ih - 1].IsThereAMan)
							{
								array_of_places[j][i].CanToBeat = 1;
								std::cout << "####" << jh << " " << ih << std::endl;
							}
							++jh;
							--ih;
						}
						jh = j - 1; ih = i + 1;
						while (jh > 0 && ih < 7)
						{
							if (array_of_places[jh][ih].IsThereAMan && array_of_places[jh - 1][ih + 1].IsThereAMan)
								break;
							if (array_of_places[jh][ih].IsThereAMan && array_of_places[jh][ih].WhiteTeam && !array_of_places[jh - 1][ih + 1].IsThereAMan)
							{
								array_of_places[j][i].CanToBeat = 1;
								std::cout << "####" << jh << " " << ih << std::endl;
							}
							jh--;
							ih++;
						}
						jh = j - 1; ih = i - 1;
						while (jh > 0 && ih > 0)
						{
							if (array_of_places[jh][ih].IsThereAMan && array_of_places[jh - 1][ih - 1].IsThereAMan)
								break;
							if (array_of_places[jh][ih].IsThereAMan && array_of_places[jh][ih].WhiteTeam && !array_of_places[jh - 1][ih - 1].IsThereAMan)
							{
								array_of_places[j][i].CanToBeat = 1;
								std::cout << "####" << jh << " " << ih << std::endl;
							}
							jh--;
							ih--;
						}
					}
				}
			}
		}
	}

bool Board::isThereKinginBestMode() {
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; ++j)
		{
			if (array_of_places[j][i].IsThereAMan && array_of_places[j][i].IsaKing && array_of_places[j][i].BeastMode)
			{
				return true;
			}
		}
	}
	return false;
	}
	
void Board::BeatingKing(sf::RenderWindow &gameWindow)
	{
		std::cout << "endered";
		sf::Vector2i position;
		int jfrom, ifrom;
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; ++j)
			{
				if (array_of_places[j][i].IsMarkToMoveFROM)
				{
					jfrom = j;
					ifrom = i;
				}
			}
		}
		array_of_places[jfrom][ifrom].IsThereAMan = 0;
		array_of_places[jfrom][ifrom].BeastMode = 0;
		array_of_places[jfrom][ifrom].IsMarkToMoveFROM = 0;
		array_of_places[jfrom][ifrom].IsaKing = 0;
		int jto, ito;
		bool get = false;

		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; ++j)
			{
				if (array_of_places[j][i].IsMArkToMoveTO)
				{
					jto = j;
					ito = i;
					get = true;
				}
			}
		}

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
		array_of_places[jto][ito].IsThereAMan = 1;
		array_of_places[jto][ito].WhiteTeam = array_of_places[jfrom][ifrom].WhiteTeam;
		array_of_places[jto][ito].IsaKing = 1;
		unmarkAllFields();
		int jholder, iholder;
			if (jto <jfrom && ito > ifrom)
			{
				jholder = jfrom;
				iholder = ifrom;
				while (iholder<ito && jholder > jto) {
					if (array_of_places[jholder][iholder].IsThereAMan)
					{
						array_of_places[jholder][iholder].IsThereAMan = 0;
						array_of_places[jholder][iholder].IsaKing = 0;
					}
					jholder--;
					iholder++;
					}
			}
			if (jto <jfrom && ito < ifrom)
			{
				jholder = jfrom;
				iholder = ifrom;
				while (jholder > jto && iholder > ito) {
					if (array_of_places[jholder][iholder].IsThereAMan)
					{
						array_of_places[jholder][iholder].IsThereAMan = 0;
						array_of_places[jholder][iholder].IsaKing = 0;
					}
					jholder--;
					iholder--;
				}
			}
			if (jto >jfrom && ito > ifrom)
			{
				jholder = jfrom;
				iholder = ifrom;
				while (jholder < jto && iholder < ito) {
					if (array_of_places[jholder][iholder].IsThereAMan)
					{
						array_of_places[jholder][iholder].IsThereAMan = 0;
						array_of_places[jholder][iholder].IsaKing = 0;
					}
					jholder++;
					iholder++;
				}
			}
			if (jto >jfrom && ito < ifrom)
			{
				jholder = jfrom;
				iholder = ifrom;
				while (jholder < jto && iholder > ito) {
					if (array_of_places[jholder][iholder].IsThereAMan)
					{
						array_of_places[jholder][iholder].IsThereAMan = 0;
						array_of_places[jholder][iholder].IsaKing = 0;
					}
					jholder++;
					iholder--;
				}
			}
		if (RoundNumber % 2 ==0)
			--black_player_mans;
		else
			--white_player_mans;
		

		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; ++j)
			{
				array_of_places[j][i].BeastMode = 0;
			}
		}
		int i = ito, j = jto;
		if (RoundNumber % 2 == 0)
		{
			{
				int jh = j + 1, ih = i + 1;
				while (jh < 7 && ih < 7)
				{
					if (array_of_places[jh][ih].IsThereAMan && array_of_places[jh + 1][ih + 1].IsThereAMan)
						break;
					if (array_of_places[jh][ih].IsThereAMan && !array_of_places[jh][ih].WhiteTeam && !array_of_places[jh + 1][ih + 1].IsThereAMan)
					{
						jh++;
						ih++;
						while (jh <= 7 && ih <= 7 && !array_of_places[jh][ih].IsThereAMan)
						{
							array_of_places[jh][ih].CanIPutMarkedManThere = 1;
							array_of_places[jto][ito].IsMarkToMoveFROM = 1;
							array_of_places[jto][ito].BeastMode = 1;
							++jh;
							++ih;
						}
						break;
					}
					++ih;
					++jh;
				}
				jh = j + 1; ih = i - 1;
				while (jh < 7 && ih >0)
				{
					if (array_of_places[jh][ih].IsThereAMan && array_of_places[jh + 1][ih - 1].IsThereAMan)
						break;
					if (array_of_places[jh][ih].IsThereAMan && !array_of_places[jh][ih].WhiteTeam && !array_of_places[jh + 1][ih - 1].IsThereAMan)
					{
						jh++;
						ih--;
						while (jh <= 7 && ih >= 0 && !array_of_places[jh][ih].IsThereAMan)
						{
							array_of_places[jh][ih].CanIPutMarkedManThere = 1;
							array_of_places[jto][ito].IsMarkToMoveFROM = 1;
							array_of_places[jto][ito].BeastMode = 1;
							++jh;
							--ih;
						}
						break;
					}
					++jh;
					--ih;
				}
				jh = j - 1; ih = i + 1;
				while (jh > 0 && ih < 7)
				{
					if (array_of_places[jh][ih].IsThereAMan && array_of_places[jh - 1][ih + 1].IsThereAMan)
						break;
					if (array_of_places[jh][ih].IsThereAMan && !array_of_places[jh][ih].WhiteTeam && !array_of_places[jh - 1][ih + 1].IsThereAMan)
					{
						jh--;
						ih++;
						while (jh >= 0 && ih <= 7 && !array_of_places[jh][ih].IsThereAMan)
						{
							array_of_places[jh][ih].CanIPutMarkedManThere = 1;
							array_of_places[jto][ito].IsMarkToMoveFROM = 1;
							array_of_places[jto][ito].BeastMode = 1;
							--jh;
							++ih;
						}
						break;
					}
					jh--;
					ih++;
				}
				jh = j - 1; ih = i - 1;
				while (jh > 0 && ih > 0)
				{
					if (array_of_places[jh][ih].IsThereAMan && array_of_places[jh - 1][ih - 1].IsThereAMan)
						break;
					if (array_of_places[jh][ih].IsThereAMan && !array_of_places[jh][ih].WhiteTeam && !array_of_places[jh - 1][ih - 1].IsThereAMan)
					{
						jh--;
						ih--;
						while (jh >= 0 && ih >= 0 && !array_of_places[jh][ih].IsThereAMan)
						{
							array_of_places[jh][ih].CanIPutMarkedManThere = 1;
							array_of_places[jto][ito].IsMarkToMoveFROM = 1;
							array_of_places[jto][ito].BeastMode = 1;
							--jh;
							--ih;
						}
						break;
					}
					jh--;
					ih--;
				}
			}
		}
		else
		{
			int jh = j + 1, ih = i + 1;
			while (jh < 7 && ih < 7)
			{
				if (array_of_places[jh][ih].IsThereAMan && array_of_places[jh + 1][ih + 1].IsThereAMan)
					break;
				if (array_of_places[jh][ih].IsThereAMan && array_of_places[jh][ih].WhiteTeam && !array_of_places[jh + 1][ih + 1].IsThereAMan)
				{
					jh++;
					ih++;
					while (jh <= 7 && ih <= 7 && !array_of_places[jh][ih].IsThereAMan)
					{
						std::cout << jh << ih;
						array_of_places[jh][ih].CanIPutMarkedManThere = 1;
						array_of_places[jto][ito].IsMarkToMoveFROM = 1;
						array_of_places[jto][ito].BeastMode = 1;
						++jh;
						++ih;
					}
					break;
				}
				++ih;
				++jh;
			}
			jh = j + 1; ih = i - 1;
			while (jh < 7 && ih >0)
			{
				if (array_of_places[jh][ih].IsThereAMan && array_of_places[jh + 1][ih - 1].IsThereAMan)
					break;
				if (array_of_places[jh][ih].IsThereAMan && array_of_places[jh][ih].WhiteTeam && !array_of_places[jh + 1][ih - 1].IsThereAMan)
				{
					jh++;
					ih--;
					while (jh <= 7 && ih >= 0 && !array_of_places[jh][ih].IsThereAMan)
					{
						std::cout << jh << ih;
						array_of_places[jh][ih].CanIPutMarkedManThere = 1;
						array_of_places[jto][ito].IsMarkToMoveFROM = 1;
						array_of_places[jto][ito].BeastMode = 1;
						++jh;
						--ih;
					}
					break;
				}
				++jh;
				--ih;
			}
			jh = j - 1; ih = i + 1;
			while (jh > 0 && ih < 7)
			{
				if (array_of_places[jh][ih].IsThereAMan && array_of_places[jh - 1][ih + 1].IsThereAMan)
					break;
				if (array_of_places[jh][ih].IsThereAMan && array_of_places[jh][ih].WhiteTeam && !array_of_places[jh - 1][ih + 1].IsThereAMan)
				{
					jh--;
					ih++;
					while (jh >= 0 && ih <= 7 && !array_of_places[jh][ih].IsThereAMan)
					{
						array_of_places[jh][ih].CanIPutMarkedManThere = 1;
						array_of_places[jto][ito].IsMarkToMoveFROM = 1;
						array_of_places[jto][ito].BeastMode = 1;
						--jh;
						++ih;
					}
					break;
				}
				jh--;
				ih++;
			}
			jh = j - 1; ih = i - 1;
			while (jh > 0 && ih > 0)
			{
				if (array_of_places[jh][ih].IsThereAMan && array_of_places[jh - 1][ih - 1].IsThereAMan)
					break;
				if (array_of_places[jh][ih].IsThereAMan && array_of_places[jh][ih].WhiteTeam && !array_of_places[jh - 1][ih - 1].IsThereAMan)
				{
					jh--;
					ih--;
					while (jh >= 0 && ih >= 0 && !array_of_places[jh][ih].IsThereAMan)
					{
						array_of_places[jh][ih].CanIPutMarkedManThere = 1;
						array_of_places[jto][ito].IsMarkToMoveFROM = 1;
						array_of_places[jto][ito].BeastMode = 1;
						--jh;
						--ih;
					}
					break;
				}
				jh--;
				ih--;
			}
		}

	}

void Board::displayAllBeast()
	{
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				if (array_of_places[j][i].BeastMode)
				{
					std::cout << "BM " << j << " " << i << std::endl;
				}
			}
		}
}