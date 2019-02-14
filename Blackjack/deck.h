#ifndef DECK_H
#define DECK_H

#include "card.h"
#include <string>
#include <vector>
#include <algorithm>

std::vector<CARD> getDeck(int);
class DECK
{
public:
	DECK(int);
	void open(int);
	void shuffle();
	int draw() { return 1; }
	void tep();
private:
	std::vector<CARD> deck;

};




#endif // !DECK_H
