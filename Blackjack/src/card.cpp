#include "card.h"

std::string CARD::back()
{
	return "X";
}

std::string CARD::front()
{
	return CARD::get_string();
}

unsigned CARD::get_value()
{
	return value;
}

CARD::CARD(unsigned v, char c)
{
	value = v;
	suit = c;
}

CARD::CARD()
{
}

void CARD::defCard(unsigned v, char c)
{
	value = v;
	suit = c;
}

CARD::~CARD()
{
}

std::string CARD::get_string()
{
	return std::to_string(value) + " of " + suit;
}