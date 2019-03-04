#ifndef TABLE_H
#define TABLE_H

#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include "card.h"
#include "deck.h"
#include "dealer.h"
#include "player.h"
#include "rule.h"

class CARD;
class DECK;
class DEALER;
class PLAYER;
class RULE;

class TABLE
{
	friend class DEALER;
	friend class PLAYER;
public:
	TABLE();
	~TABLE();
	void defNumber(unsigned);
	void defDealer(DEALER);
	void defPlayer(PLAYER);
	void defAll(unsigned, DEALER, PLAYER);
	unsigned getTableNumber();
	std::string getPlayerName();
	long getPlayerMoney();
	int checkBlackjack();
	void compare();
	void compareWSplit();
	void clear();
private:
	unsigned tableNumber;
	DEALER *dealer;
	PLAYER *player;
	// We have to serve multiple players online at one table.
};

#endif // !TABLE_H