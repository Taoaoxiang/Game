#include "table.h"

TABLE::TABLE()
{
}

TABLE::~TABLE()
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
	std::ostringstream message;
	message << "SYSTEM: Table -> " << tableNumber << '\n'
		<< "        Dealer -> " << dealer->getName() << '\n'
		<< "        Player -> " << player->getName();
	std::cout << message.str() << std::endl;
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

int TABLE::checkBlackjack()
{
	unsigned pPoint = player->getPoints();
	unsigned dPoint = dealer->getPoints();
	RULE r;
	if (pPoint == 21 && dPoint == 21) {
		r.showCards(*dealer);
		std::cout << "SYSTEM: (DEALER)=> Blackjack!\n"
			<< "        " << "(PLAYER)=> Blackjack!\n"
			<< "        " << "Push!" << std::endl;
		*player->money += *player->deal;
		return 2;
	} else if (pPoint != 21 && dPoint == 21) {
		r.showCards(*dealer);
		std::cout << "SYSTEM: (DEALER)=> Blackjack!\n"
			<< "        " << "(PLAYER)=> " << pPoint << ".\n"
			<< "        " << "Dealer wins!" << std::endl;
		*dealer->money += *player->deal;
		return 1;
	} else if (pPoint == 21 && dPoint != 21) {
		r.showCards(*dealer);
		std::cout << "SYSTEM: (DEALER)=> " << dPoint << ".\n"
			<< "        " << "(PLAYER)=> Blackjack!\n"
			<< "        " << "Player wins!" << std::endl;
		*player->money += 2.5 * (*player->deal);
		*dealer->money -= 1.5 * (*player->deal);
		return 1;
	}
	return 0;
}

void TABLE::compare()
{
	unsigned pPoint = player->getPoints();
	unsigned dPoint = dealer->getPoints();
	if (pPoint > 21) {
		std::cout << "SYSTEM: (DEALER)=> " << dPoint << ".\n"
			<< "        " << "(PLAYER)=> Bust!\n"
			<< "        " << "Dealer wins!" << std::endl;
		*dealer->money += *player->deal;
		return;
	} else if (pPoint == 21) {
		if (dPoint != 21) {
			std::cout << "SYSTEM: (DEALER)=> " << dPoint << ".\n"
				<< "        " << "(PLAYER)=> " << pPoint << ".\n"
				<< "        " << "Player wins!" << std::endl;
			*player->money += 2 * (*player->deal);
			*dealer->money -= *player->deal;
			return;
		} else {
			std::cout << "SYSTEM: (DEALER)=> " << dPoint << ".\n"
				<< "        " << "(PLAYER)=> " << pPoint << ".\n"
				<< "        " << "Push!" << std::endl;
			*player->money += *player->deal;
			return;
		}
	} else {
		if (dPoint > 21) {
			std::cout << "SYSTEM: (DEALER)=> Bust!\n"
				<< "        " << "(PLAYER)=> " << pPoint << ".\n"
				<< "        " << "Player wins!" << std::endl;
			*player->money += 2 * (*player->deal);
			*dealer->money -= *player->deal;
			return;
		} else if (dPoint > pPoint && dPoint <= 21) {
			std::cout << "SYSTEM: (DEALER)=> " << dPoint << ".\n"
				<< "        " << "(PLAYER)=> " << pPoint << ".\n"
				<< "        " << "Dealer wins!" << std::endl;
			*dealer->money += *player->deal;
			return;
		} else if (pPoint == dPoint) {
			std::cout << "SYSTEM: (DEALER)=> " << dPoint << ".\n"
				<< "        " << "(PLAYER)=> " << pPoint << ".\n"
				<< "        " << "Push!" << std::endl;
			*player->money += *player->deal;
			return;
		} else {
			std::cout << "SYSTEM: (DEALER)=> " << dPoint << ".\n"
				<< "        " << "(PLAYER)=> " << pPoint << ".\n"
				<< "        " << "Player wins!" << std::endl;
			*player->money += 2 * (*player->deal);
			*dealer->money -= *player->deal;
			return;
		}
	}
}

void TABLE::clear()
{
	player->cards->clear();
	player->splitCards->clear();
	*(player->splitTimes) = 0;
	*player->deal = 0;
	dealer->cards->clear();
	std::cout << "SYSTEM: Table is clear!" << std::endl;
}
