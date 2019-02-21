#include "player.h"

PLAYER::PLAYER(std::string pN = "Player", long pM = 0)
{
	playerName = pN;
	playerMoney = pM;
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

void PLAYER::hit()
{
	//
}