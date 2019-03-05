#ifndef RULE_H
#define RULE_H

#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include "card.h"
#include "deck.h"
#include "dealer.h"
#include "player.h"
#include "table.h"

class CARD;
class DECK;
class DEALER;
class PLAYER;
class TABLE;

class RULE
{
	friend class DEALER;
	friend class PLAYER;
public:
	RULE();
	~RULE();
	unsigned getPoints(std::vector<CARD>);
	unsigned getPoints(DEALER);
	unsigned getPoints(PLAYER);
	void showInitCards(DEALER);
	void showCards(DEALER);
	void showCards(PLAYER);
	bool splitable(CARD, CARD);
	unsigned recursive21(PLAYER, DEALER, 
		std::vector<unsigned>, std::vector<CARD>);
	void nextAndShow(PLAYER&, DEALER&, std::vector<CARD>&);
	unsigned playerHit(PLAYER, DEALER);
	unsigned playerStand(PLAYER);
	void playerPushToHand(PLAYER, long);
	unsigned playerTurn(PLAYER, DEALER);
	std::vector<unsigned> playerTurnWSplit(PLAYER, DEALER);
	unsigned dealerTurn(DEALER, unsigned);
	unsigned dealerTurnWSplit(DEALER, std::vector<unsigned>);
//private:

};


#endif // !RULE_H
