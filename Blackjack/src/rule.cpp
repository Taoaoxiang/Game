#include "rule.h"

RULE::RULE()
{
}

RULE::~RULE()
{
}

unsigned RULE::getPoints(std::vector<CARD> c)
{
	unsigned p = 0, p1 = 0, p2 = 0;
	for (std::vector <CARD> ::iterator i = c.begin();
		i != c.end(); ++i) {
		unsigned v = i->get_value();
		switch (v) {
		case 1:	
			if (p > 10) {
				p1 += 1;
				p2 += 1;
			} else {
				p1 += 1;
				p2 += 11;
			}
			break;
		case 11: case 12: case 13:
			p1 += 10;
			p2 += 10;
			break;
		default:
			p1 += v;
			p2 += v;
			break;
		}
		if (p1 >= 21) {
			p = p1;
		} else if (p2 <= 21) {
			p = p2;
		}
	}
	return p;
}

unsigned RULE::getPoints(DEALER d)
{
	return getPoints(*d.cards);
}

unsigned RULE::getPoints(PLAYER p)
{
	return getPoints(*p.cards);
}

void RULE::showInitCards(DEALER d)
{
	std::ostringstream msg;
	msg << "SYSTEM: (Dealer)=> [ X ] " ;
	std::string c1 = (*d.cards)[0].front();
	std::string c2 = (*d.cards)[1].front();
	msg << "[ " << c2 << " ] ";
	std::cout << msg.str() << std::endl;
}

void RULE::showCards(PLAYER p)
{
	std::ostringstream msg;
	std::string c;
	msg << "SYSTEM: (Player)=> ";
	for (std::vector <CARD> ::iterator i = p.cards->begin();
		i != p.cards->end(); ++i) {
		c = i->front();
		msg << "[ " << c << " ] ";
	}
	std::cout << msg.str() << std::endl;
	std::cout << "        " << getPoints(*p.cards) << " points."<< std::endl;
}

void RULE::showCards(DEALER d)
{
	std::ostringstream msg;
	std::string c;
	msg << "SYSTEM: (Dealer)=> ";
	for (std::vector <CARD> ::iterator i = d.cards->begin();
		i != d.cards->end(); ++i) {
		c = i->front();
		msg << "[ " << c << " ] ";
	}
	std::cout << msg.str() << std::endl;
	std::cout << "        " << getPoints(*d.cards) << " points." << std::endl;
}

unsigned RULE::playerTurn(PLAYER p, DEALER d)
{
	std::ostringstream msg;
	msg << "        " << "Hit:    (H) or (h)\n"
		<< "        " << "Stand:  (S) or (s)";
	std::cout << "SYSTEM: Player's turn." << std::endl;
	unsigned points = 0;
	if ((points = getPoints(p)) == 21) {
		std::cout << "        " << "Blackjack!" << std::endl;
		return points;
	}
	std::string letter;
	while ((points = getPoints(p)) < 21) {
		if (p.deal <= p.playerMoney && p.cards->size() == 2) {
			std::cout << msg.str() << '\n'
				<< "        " << "Double: (D) or (d)\n" 
				<< "        " << "Please choose, default stand: ";
			std::cin >> letter;
			switch (letter[0]) {
			case 'H': case 'h':
				p.initCard(d.draw());
				p.showCards();
				break;
			case 'S': case 's':
				std::cout << "SYSTEM: You choose to stand." << std::endl;
				return points;
			case 'D': case 'd':
				p.playerMoney -= p.deal;
				p.deal *= 2;
				std::cout << "SYSTEM: You choose to double your bet." << std::endl;
				p.initCard(d.draw());
				p.showCards();
				std::cout << "        " << "Your bet is: $" << p.deal << ".\n"
					<< "        " << "You have $" << p.playerMoney << " left." << std::endl;
				return getPoints(p);
			default:
				std::cout << "SYSTEM: You choose to stand." << std::endl;
				return points;
			}
		} else {
			std::cout << msg.str() << "\n"
				<< "        " << "Please choose, default stand: ";
			std::cin >> letter;
			switch (letter[0]) {
			case 'H': case 'h':
				p.initCard(d.draw());
				p.showCards();
				break;
			case 'S': case 's':
				std::cout << "SYSTEM: You choose to stand." << std::endl;
				return points;
			default:
				std::cout << "SYSTEM: You choose to stand." << std::endl;
				return points;
			}
		}
	}
	std::cout << "        " << "Bust!" << std::endl;
	return points;
}

unsigned RULE::dealerTurn(DEALER d, unsigned pPoint)
{
	std::cout << "SYSTEM: Dealer's turn." << std::endl;
	showCards(d);
	unsigned points = getPoints(d);
	if (points == 21) {
		std::cout << "        " << "Blackjack!" << std::endl;
		return points;
	} else if (pPoint >= 21) {
		return points;
	}
	// TODO : 
	/*
	while (points < 17 ) {

	}
	*/
	return points;
}
