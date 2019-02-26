#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <iomanip>
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
	friend class TABLE;
public:
	PLAYER(std::string, float);
	~PLAYER();
	void defName(std::string);
	void defMoney(float);
	std::string getName();
	float getMoney();
	//void stand();
	//void split();
	long getDeal();
	void makeBet();
	void hit();
	void initCard(CARD);
	void showCards();
	unsigned getPoints();
	unsigned turn(DEALER);
private:
	float playerMoney = 0;
	float *money = &playerMoney;
	std::string playerName;
	float *deal = &myDeal;
	float myDeal = 0;
	std::vector<CARD> *cards = NULL;
	std::vector<CARD> my_cards;
};

#endif // !PLAYER_H
