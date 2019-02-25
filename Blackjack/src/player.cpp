#include "player.h"

PLAYER::PLAYER(std::string pN = "Player", long pM = 0)
{
	playerName = pN;
	playerMoney = pM;
	cards = &my_cards;
}

PLAYER::~PLAYER()
{
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
	unsigned long t = 0;
	std::cin >> t;
	while (!t || t<1 || t>playerMoney) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "SYSERR: Your input is invalid. Try it again.\n" 
			<< "        " << "(1 ~ " << playerMoney << ")\n"
			<< "        "; 
		std::cin >> t;
	} 
	deal = t;
	playerMoney -= deal;
	std::cout << "SYSTEM: Your bet is: $" << deal << ".\n"
		<< "        You have $" << playerMoney << " left." << std::endl;
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

void PLAYER::showCards()
{
	RULE r;
	r.showCards(*this);
}

unsigned PLAYER::getPoints()
{
	RULE r;
	return r.getPoints(*this);
}

unsigned PLAYER::turn(DEALER d)
{
	RULE r;
	return r.playerTurn(*this, d);
}
