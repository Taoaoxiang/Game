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

DECK::open(int n)
{
	deck = getDeck(n);
}

DECK::shuffle()
{
	std::random_shuffle(deck.begin(), deck.end());
}

DECK::tep()
{
	for (std::vector <CARD> ::iterator id = deck.begin(); id != deck.end(); ++id) {
		cout << id->front() << endl;
	}
}

