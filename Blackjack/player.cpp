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

void PLAYER::hit()
{
	//
}

void PLAYER::initCard(CARD c)
{
	cards->push_back(c);
	++numberCard;
	//std::string s1 = (*cards)[i].front() ;
	//TODO: We have to introduce rule.h
	unsigned v = c.get_value();
	if (v > 10) {
		v = 10;
	}

	if (numberCard == 1) {
		if (v == 1) {
			v = 11;
		}
		points += v;
	} else if (numberCard == 2) {
		if (v == 1) {
			if (points == 11) {
				points += v;
			} else {
				v = 11;
				points += v;
			}
		}
	}
	std::string s = c.front();
	std::cout << "PLAYER: (Card) ->" << s << '\n'
		<< "        Points: " << points << std::endl;

}
