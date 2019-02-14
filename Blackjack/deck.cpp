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

DECK::DECK(int n)
{
	deck = getDeck(n);
}

void DECK::open(int n)
{
	deck = getDeck(n);
}

void DECK::shuffle()
{
	std::random_shuffle(deck.begin(), deck.end());
}

CARD DECK::draw()
{
	CARD card = deck.back();
	deck.pop_back();
	return card;
}

void DECK::tep()
{
	for (std::vector <CARD> ::iterator id = deck.begin(); id != deck.end(); ++id) {
		std::cout << id->front() << std::endl;
	}
}

std::vector<CARD> DECK::getCurrentDeck()
{
	return deck;
}

CARD DECK::getLastCard()
{
	CARD card = deck.back();
	return card;
}
