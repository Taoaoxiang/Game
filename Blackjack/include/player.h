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
	//void split();
	long getDeal();
	void makeBet();
	void initCard(CARD);
	void showCards();
	unsigned getPoints();
	unsigned turn(DEALER);
	std::vector<unsigned> turnWSplit(DEALER);
private:
	float playerMoney = 0;
	float *money = &playerMoney;
	std::string playerName;
	float *deal = &myDeal;
	float myDeal = 0;
	std::vector<CARD> *cards = &my_cards;
	std::vector<CARD> my_cards;
	unsigned mySplitTimes = 0;
	unsigned *splitTimes = &mySplitTimes;
	std::vector<std::vector <CARD>> mySplitCards;
	std::vector<std::vector <CARD>> *splitCards = &mySplitCards;
};

#endif // !PLAYER_H
