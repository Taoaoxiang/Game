#ifndef DECK_H
#define DECK_H

#include "card.h"
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <array>

const std::array<unsigned, 13> VALUES = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
const std::array<char, 4> SUITS = {'c', 'd', 'h', 's'};

std::vector<CARD> getDeck(int);

class DECK
{
public:
	DECK(int n);
	void open(int n);
	void shuffle();
	CARD draw();
	void tep();
	std::vector<CARD> getCurrentDeck();
	CARD getLastCard();
private:
	std::vector<CARD> deck;

};




#endif // !DECK_H
