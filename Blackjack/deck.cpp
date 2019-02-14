#include "deck.h"

//const array<unsigned, 13> VALUES = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
//const array<char, 4> SUITS = {'c', 'd', 'h', 's'};


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

void DECK::tep()
{
	for (std::vector <CARD> ::iterator id = deck.begin(); id != deck.end(); ++id) {
		std::cout << id->front() << std::endl;
	}
}

