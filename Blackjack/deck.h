#ifndef DECK_H
#define DECK_H

#include "card.h"
#include <string>



class CARD
{
public:
	std::string back();
	std::string front();
	unsigned get_value();
	CARD(unsigned, char);
private:
	unsigned value;
	char suit;
protected:
	std::string get_string();
};

#endif // !DECK_H
