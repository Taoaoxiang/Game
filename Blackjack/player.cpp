#include "player.h"

PLAYER::PLAYER(std::string pN = "Player", long pM = 0)
{
	playerName = pN;
	playerMoney = pM;
	cards = &my_cards;
}

void PLAYER::defName(std::string pN = "Player")
{
	playerName = pN;
}

void PLAYER::defMoney(long pM = 1000000)
{
	playerMoney = pM;
}

std::string PLAYER::getName()
{
	return playerName;
}

long PLAYER::getMoney()
{
	return playerMoney;
}

void PLAYER::makeBet()
{
	std::cout << "SYSTEM: Please make a BET!\n"
		<< "        " << "(1 ~ " << playerMoney << ")\n"
		<< "        ";
	std::cin >> deal;
	playerMoney -= deal;
}

void PLAYER::hit()
{
	//
}

void PLAYER::initCard(CARD c)
{
	cards->push_back(c);
	//std::string s1 = (*cards)[i].front();
}

unsigned PLAYER::getPoints()
{
	RULE r;
	return r.getPoints(*cards);
}
