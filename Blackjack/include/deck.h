#ifndef DECK_H
#define DECK_H

#include "card.h"
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <ctime>
#include <array>

class CARD;

const std::array<unsigned, 13> VALUES = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13 };
const std::array<char, 4> SUITS = { 'c', 'd', 'h', 's' };

std::vector<CARD> getDeck(int);

class DECK
{
public:
	DECK();
	DECK(int n);
	~DECK();
	void open(int);
	void shuffle();
	CARD draw();
	void printCurrentDeck();
	std::vector<CARD> getCurrentDeck();
	CARD getLastCard();
	int getAmountDeck();
private:
	std::vector<CARD> *deck = NULL;
	std::vector<CARD> this_deck;
	int amountDeck = 2;
};

#endif // !DECK_H