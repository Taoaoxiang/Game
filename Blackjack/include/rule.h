#ifndef RULE_H
#define RULE_H

#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include "card.h"
#include "deck.h"
#include "dealer.h"
#include "player.h"
#include "table.h"

class RULE
{
	friend class DEALER;
	friend class PLAYER;
public:
	RULE();
	unsigned getPoints(std::vector<CARD>);
	unsigned getPoints(DEALER);
	unsigned getPoints(PLAYER);
	void showInitCards(DEALER);
	//void showCards(DEALER);
	void showCards(PLAYER);
	//long getDeal(PLAYER);
//private:

};


#endif // !RULE_H