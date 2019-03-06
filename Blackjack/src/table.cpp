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

int TABLE::compare(unsigned dP, unsigned pP)
{
	if (dP > 21) {
		if (pP <= 21) {	return 1; }
		else if (pP > 21) { return -1; }
	}
	else if (dP == 21) {
		if (pP == 21) { return 0; }
		else if (pP != 21) { return -1; }
	}
	else if (dP < 21) {
		if (pP < dP || pP>21) { return -1; }
		else if (pP == dP) { return 0; }
		else if (pP > dP && pP <= 21) { return 1; }
	}
	return -2;
}

void TABLE::playerHandPop()
{
	player->cards->clear();
	std::vector<CARD> cards = player->hand->vecCards->back();
	for (std::vector<CARD> ::iterator i = cards.begin();
		i != cards.end(); ++i) {
		player->initCard(*i);
	}

	player->hand->vecCards->pop_back();
	player->hand->vecDeals->pop_back();
	player->hand->vecPoints->pop_back();
}

int TABLE::compareWSplit()
{

	unsigned dP = dealer->getPoints();
	dealer->showCards();

	if (player->hand->vecPoints->size() == player->hand->vecDeals->size()
		&& player->hand->vecPoints->size() == player->hand->vecCards->size()) {

		while (player->hand->vecPoints->size()!=0) {
			unsigned pP = player->hand->vecPoints->back();
			long pDeal = player->hand->vecDeals->back();
			// get and pop the last hand
			playerHandPop();
			player->showCards();

			int r = compare(dP, pP);
			if (r == 1) {
				*player->money += 2 * pDeal;
				*dealer->money -= pDeal;
				std::cout << "        Win $" << pDeal << std::endl;
				std::cout << "        You have $" << *player->money << std::endl;
			}
			else if (r == 0) { 
				*player->money += pDeal; 
				std::cout << "        Push!" << std::endl;
				std::cout << "        You have $" << *player->money << std::endl;
			}
			else if (r == -1) { 
				*dealer->money += pDeal; 
				std::cout << "        Lose $" << pDeal << std::endl;
				std::cout << "        You have $" << *player->money << std::endl;
			}
			else { std::cout << "SYSERR: ERROR!" << std::endl; }
		}
		return 1;
	}
	else { return 0; }
}

void TABLE::clear()
{
	*player->deal = 0;
	player->cards->clear();
	*player->splitTimes = 0;
	player->hand->vecCards->clear();
	player->hand->vecDeals->clear();
	player->hand->vecPoints->clear();
	dealer->cards->clear();
	std::cout << "SYSTEM: Table is clear!" << std::endl;
}
