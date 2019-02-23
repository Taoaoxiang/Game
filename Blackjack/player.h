#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <vector>
#include <string>
#include "card.h"
#include "deck.h"
#include "rule.h"
#include "table.h"

class PLAYER
{
	friend class RULE;
public:
	PLAYER(std::string, long);
	void defName(std::string);
	void defMoney(long);
	std::string getName();
	long getMoney();
	//void stand();
	//void split();
	void hit();
	void initCard(CARD);
	unsigned getPoints();
private:
	long playerMoney;
	std::string playerName;
	std::vector<CARD> *cards = NULL;
	std::vector<CARD> my_cards;
};

#endif // !PLAYER_H
