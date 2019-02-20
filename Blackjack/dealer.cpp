#include "dealer.h"
#include "dealer.h"

DEALER::DEALER()
{
	std::cout << "Hello, I'm your dealer." << std::endl;
}

void DEALER::welcome(std::string player)
{
	std::cout << "Welcome, " << player << "!" << std::endl;
}

void DEALER::defDeck()
{
	deck = &this_deck;
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
	std::cout << "The deck of cards is shuffled." << std::endl;
}

CARD DEALER::draw()
{
	CARD card = deck->draw();
	card.front();
	return card;
}