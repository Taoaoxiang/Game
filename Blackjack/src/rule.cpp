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
		if (p2 <= 21) {
			p = p2;
		} else {
			p = p1;
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

bool RULE::splitable(CARD c1, CARD c2)
{
	unsigned v1 = c1.get_value();
	unsigned v2 = c2.get_value();
	if (v1 == v2 || (v1 >= 10 && v2 >= 10)) {
		return true;
	}
	return false;
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
	std::string letter;
	while ((points = getPoints(p)) < 21) {
		if (*p.deal <= *p.money && p.cards->size() == 2) {
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
				*p.money -= *p.deal;
				*p.deal *= 2;
				std::cout << "SYSTEM: You choose to double your bet." << std::endl;
				p.initCard(d.draw());
				p.showCards();
				std::cout << "        " << "Your bet is: $" << *p.deal << ".\n"
					<< "        " << "You have $" << *p.money << " left." << std::endl;
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
	return points;
}

std::vector<unsigned> RULE::playerTurnWSplit(PLAYER p, DEALER d)
{
	std::vector<unsigned> v_P;
	std::ostringstream msg;
	msg << "        " << "Hit:    (H) or (h)\n"
		<< "        " << "Stand:  (S) or (s)";
	std::cout << "SYSTEM: Player's turn." << std::endl;
	unsigned points = 0;
	std::string letter;
	// This is the temp stack of splited cards.
	// Excludes the current playing cards and played cards.
	// The played cards will be pushed back to p.splitCards.
	std::vector<CARD> tmpCards;
	while ((points = getPoints(p)) < 21) {
		std::vector<CARD> tmpS;
		CARD tmpA1 = p.cards->back();
		if (*p.deal <= *p.money && p.cards->size() == 2) {
			if (true || splitable((*p.cards)[0], (*p.cards)[1])) {
				std::cout << msg.str() << '\n'
					<< "        " << "Double: (D) or (d)\n"
					<< "        " << "Split:  (P) or (p)\n"
					<< "        " << "Please choose, default stand: ";
				std::cin >> letter;
				switch (letter[0]) {
				case 'P': case 'p':
					*p.splitTimes += 1;
					// needs to get a deal vector
					*p.deal *= 2;
					tmpCards.push_back(tmpA1);
					p.cards->pop_back();
					p.initCard(d.draw());
					std::cout << "SYSTEM: You choose to split." << std::endl;
					p.showCards();
					break;
				case 'H': case 'h':
					p.initCard(d.draw());
					p.showCards();
					if (p.getPoints() >= 21) {
						
					}
					break;
				case 'S': case 's':
					tmpS = *p.cards;
					v_P.push_back(getPoints(tmpS));
					p.splitCards->push_back(tmpS);
					std::cout << "SYSTEM: You choose to stand." << std::endl;
					return v_P;
				case 'D': case 'd':
					*p.money -= *p.deal;
					*p.deal *= 2;
					std::cout << "SYSTEM: You choose to double your bet." << std::endl;
					p.initCard(d.draw());
					p.showCards();
					tmpS = *p.cards;
					v_P.push_back(getPoints(tmpS));
					p.splitCards->push_back(tmpS);
					std::cout << "        " << "Your bet is: $" << *p.deal << ".\n"
						<< "        " << "You have $" << *p.money << " left." << std::endl;
					return v_P;
				default:
					// allocate new memory for new vector 
					// and then push it into splitCards
					// return the same points
					tmpS = *p.cards;
					v_P.push_back(getPoints(tmpS));
					p.splitCards->push_back(tmpS);
					std::cout << "SYSTEM: You choose to stand." << std::endl;
					if (tmpCards.size() != 0) {
						p.cards->clear();
						//CARD c = tmpCards.pop_back();
						//p.initCard(c);
						p.initCard(d.draw());
						break;
					} else {
						return v_P;
					}
				} // end of one decision
			} // end of splitable cards
			/*
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
				p.playerMoney -= *p.deal;
				*p.deal *= 2;
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
		}
		else {
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
			}*/
		}
	}
	return v_P;
}

unsigned RULE::dealerTurn(DEALER d, unsigned pPoint)
{
	std::cout << "SYSTEM: Dealer's turn." << std::endl;
	showCards(d);
	unsigned points = getPoints(d);
	if (pPoint > 21) {
		return points;
	}
	while (points < 17 ) {
		if (points > pPoint) {
			return points;
		} else {
			d.initCard(d.draw());
			points = getPoints(d);	
			showCards(d);
		}
	}
	return points;
}
