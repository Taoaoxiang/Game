#include "deck.h"

std::vector<CARD> getDeck(int n)
{
	std::vector<CARD> vecCard;
	for (int i = 0; i < n; ++i) {
		for (const char &suit : SUITS) {
			for (const unsigned &value : VALUES) {
				CARD card(value, suit);
				vecCard.push_back(card);
			}
		}
	}
	return vecCard;
}

DECK::DECK()
{
}

DECK::DECK(int n)
{
	amountDeck = n;
	this_deck = getDeck(n);
	deck = &this_deck;
}

DECK::~DECK()
{
}

void DECK::open(int n)
{
	amountDeck = n;
	this_deck = getDeck(n);
	deck = &this_deck;
}

void DECK::shuffle()
{
	if (deck == NULL) {
		this_deck = getDeck(amountDeck);
		deck = &this_deck;
	}
	std::srand(std::time(0));
	unsigned int r = std::rand() % 19;
	//Shuffle the cards random time(s)
	for (int i = 0; i <= r; ++i) {
		std::random_shuffle(deck->begin(), deck->end());
	}
}

CARD DECK::draw()
{
	CARD card = deck->back();
	deck->pop_back();
	return card;
}

void DECK::printCurrentDeck()
{
	std::ostringstream message;
	message << "SYSTEM: ";
	for (std::vector <CARD> ::iterator id = deck->begin(); 
		id != deck->end(); ++id) {
		message << id->front() << "    ";
	}
	std::cout << message.str() << std::endl;
}

std::vector<CARD> DECK::getCurrentDeck()
{
	return this_deck;
}
 
CARD DECK::getLastCard()
{
	CARD card = deck->back();
	return card;
}

int DECK::getAmountDeck()
{
	return amountDeck;
}

int DECK::getAmountCard()
{
	return (*deck).size();
}
