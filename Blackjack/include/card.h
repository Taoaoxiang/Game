#ifndef CARD_H
#define CARD_H

#include <string>
#include "deck.h"
#include "rule.h"
#include "table.h"
#include "player.h"
#include "dealer.h"

class DECK;
class RULE;
class TABLE;
class DEALER;
class PLAYER;

class CARD
{
public:
	std::string back();
	std::string front();
	unsigned get_value();
	CARD(unsigned, char);
	CARD();
	void defCard(unsigned, char);
	CARD operator=(const CARD&);
	~CARD();
private:
	unsigned value;
	char suit;
protected:
	std::string get_string();
};

#endif // !CARD_H