#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <vector>
#include <string>
#include "card.h"
#include "deck.h"

class PLAYER
{
public:
	PLAYER(std::string, long);
	void defName(std::string);
	void defMoney(long);
	std::string getName();
	long getMoney();
	//void stand();
	void hit();
private:
	long playerMoney;
	std::string playerName;
};

#endif // !PLAYER_H
