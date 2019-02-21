#include "table.h"

TABLE::TABLE()
{
}

void TABLE::defNumber(unsigned n)
{
	tableNumber = n;
}

void TABLE::defDealer(DEALER d)
{
	dealer = &d;
}

void TABLE::defPlayer(PLAYER p)
{
	player = &p;
}

void TABLE::defAll(unsigned t, DEALER d, PLAYER p)
{
	tableNumber = t;
	dealer = &d;
	player = &p;
}

unsigned TABLE::getTableNumber()
{
	return tableNumber;
}

std::string TABLE::getPlayerName()
{
	return player->getName();
}

long TABLE::getPlayerMoney()
{
	return player->getMoney();
}
