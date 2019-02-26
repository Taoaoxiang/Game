#ifndef DEALER_H
#define DEALER_H

#include "card.h"
#include "deck.h"
#include "rule.h"
#include "table.h"
#include "player.h"
#include <string>
#include <vector>
#include <iostream>

class CARD;
class DECK;
class RULE;
class TABLE;
class PLAYER;

class DEALER
{
	friend class RULE;
	friend class TABLE;
public:	
	DEALER();
	DEALER(std::string);
	~DEALER();
	void welcome(std::string);
	void defName(std::string);
	std::string getName();
	void defDeck();
	void defDeck(DECK);
	void setNumberDeck(int);
	int getCurrentNumberDeck();
	void shuffle();
	CARD draw();
	void initCard(CARD);
	void showInitCards();
	unsigned getPoints();
	unsigned turn(unsigned);
private:
	DECK *deck;
	DECK this_deck;
	std::vector<CARD> *cards = NULL;
	std::vector<CARD> my_cards;
	std::string name;
	long money = 0;
	int currentNumberDeck = 2;
	int nextNumberDeck = 2;
	bool deckPlayed = false;
};

#endif // !DEALER_H