#include "dealer.h"

DEALER::DEALER()
{
	cards = &my_cards;
}

DEALER::DEALER(std::string s)
{
	cards = &my_cards;
	name = s;
}

DEALER::~DEALER()
{
}

void DEALER::welcome(std::string player)
{
	std::cout << "DEALER: Welcome, " << player << "!" << '\n'
		<< "        " << "I'm " << name << "." << std::endl;
}

void DEALER::defName(std::string s)
{
	name = s;
}

std::string DEALER::getName()
{
	return name;
}

void DEALER::defDeck()
{
	deck = &this_deck;
	deck->open(currentNumberDeck);
}

void DEALER::defDeck(DECK d)
{
	deck = &d;
	currentNumberDeck = deck->getAmountDeck();
	nextNumberDeck = currentNumberDeck;

}

void DEALER::setNumberDeck(int n)
{
	if (deckPlayed == false) {
		currentNumberDeck = n;
		if (deck == NULL) {
			deck = &this_deck;
		}
		deck->open(currentNumberDeck);
		nextNumberDeck = n;
	} else {
		nextNumberDeck = n;
	}
}

int DEALER::getCurrentNumberDeck()
{
	return currentNumberDeck;
}

void DEALER::shuffle()
{
	if (deckPlayed == false && currentNumberDeck == nextNumberDeck) {
		deck->shuffle();
	}
	else {
		deck->open(nextNumberDeck);
		deck->shuffle();
		currentNumberDeck = nextNumberDeck;
		deckPlayed = false;
	}
	std::cout << "DEALER: The deck of cards is shuffled." << std::endl;
}

CARD DEALER::draw()
{
	CARD card = deck->draw();
	//std::cout << "DEALER [Draw]: " << card.front() << std::endl;
	return card;
}

void DEALER::initCard(CARD c)
{
	cards->push_back(c);
}

void DEALER::showInitCards()
{
	RULE r;
	r.showInitCards(*this);
}

unsigned DEALER::getPoints()
{
	RULE r;
	return r.getPoints(*this);
}

unsigned DEALER::turn(unsigned pP)
{
	RULE r;
	return r.dealerTurn(*this, pP);
}
