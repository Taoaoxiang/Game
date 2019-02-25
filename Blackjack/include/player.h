#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <limits>
#include <vector>
#include <string>
#include "card.h"
#include "deck.h"
#include "rule.h"
#include "table.h"
#include "dealer.h"

class CARD;
class DECK;
class RULE;
class TABLE;
class DEALER;

class PLAYER
{
	friend class RULE;
public:
	PLAYER(std::string, long);
	~PLAYER();
	void defName(std::string);
	void defMoney(long);
	std::string getName();
	long getMoney();
	//void stand();
	//void split();
	long deal = 0;
	void makeBet();
	void hit();
	void initCard(CARD);
	void showCards();
	unsigned getPoints();
	unsigned turn(DEALER);
private:
	long playerMoney;
	std::string playerName;
	std::vector<CARD> *cards = NULL;
	std::vector<CARD> my_cards;
};

#endif // !PLAYER_H
