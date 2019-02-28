#ifndef CARD_H
#define CARD_H

#include <string>

class CARD
{
public:
	std::string back();
	std::string front();
	unsigned get_value();
	CARD(unsigned, char);
	CARD();
	void defCard(unsigned, char);
	~CARD();
private:
	unsigned value;
	char suit;
protected:
	std::string get_string();
};

#endif // !CARD_H