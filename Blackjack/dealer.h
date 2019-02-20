#ifndef DEALER_H
#define DEALER_H

#include "card.h"
#include "deck.h"
#include <string>
#include <vector>
#include <iostream>

class DEALER
{
public:
	DEALER();
	void welcome(std::string);
	void defDeck();
	void defDeck(DECK);
	void setNumberDeck(int);
	int getCurrentNumberDeck();
	void shuffle();
	CARD draw();
private:
	DECK *deck;
	DECK this_deck;
	int currentNumberDeck = 2;
	int nextNumberDeck = 2;
	bool deckPlayed = false;
};

#endif // !DEALER_H