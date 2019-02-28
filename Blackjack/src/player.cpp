#include "player.h"

PLAYER::PLAYER(std::string pN = "Player", float pM = 0)
{
	playerName = pN;
	playerMoney = pM;
	//cards = &my_cards;
}

PLAYER::~PLAYER()
{
}

void PLAYER::defName(std::string pN = "Player")
{
	playerName = pN;
}

void PLAYER::defMoney(float pM = 1000000)
{
	playerMoney = pM;
}

std::string PLAYER::getName()
{
	return playerName;
}

float PLAYER::getMoney()
{
	return playerMoney;
}

long PLAYER::getDeal()
{
	return myDeal;
}

void PLAYER::makeBet()
{
	std::cout << "SYSTEM: Please make a BET!\n"
		<< "        " << "(1 ~ "  
		<< std::fixed 
		<< std::setprecision(0) 
		<< *money
		<< ")\n"
		<< "        ";
	float t = 0;
	std::cin >> t;
	while (!t || t<1 || t>*money) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "SYSERR: Your input is invalid. Try it again.\n" 
			<< "        " << "(1 ~ "
			<< std::fixed
			<< std::setprecision(0) << *money << ")\n"
			<< "        "; 
		std::cin >> t;
	} 
	*deal = t;
	*money -= *deal;
	std::cout << "SYSTEM: Your bet is: $" 
		<< std::fixed
		<< std::setprecision(1) << *deal << ".\n"
		<< "        You have $" << *money << " left." << std::endl;
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

std::vector<unsigned> PLAYER::turnWSplit(DEALER d)
{
	RULE r;
	// TEST
	std::vector<unsigned> t1 = r.playerTurnWSplit(*this, d);
	for (std::vector<std::vector <CARD>>::iterator i = splitCards->begin();
		i != splitCards->end(); ++i) {
		std::cout << "\nTEST3: START OF THIS TEST!" << std::endl;
		for (std::vector <CARD>::iterator a = i->begin();
			a != i->end(); ++a) {
			std::string s1= a->front();
			unsigned i1 = a->get_value();
			std::cout << "TEST: " << s1 << "\n" << "TEST2: " << i1 << std::endl;
		}
		std::cout << "TEST3: END OF THIS TEST!\n" << std::endl;
	}
	return t1;
	// END of TEST

	//return r.playerTurnWSplit(*this, d);
}
