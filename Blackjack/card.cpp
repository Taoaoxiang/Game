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

std::string CARD::get_string()
{
	return std::to_string(value) + " of " + suit;
}