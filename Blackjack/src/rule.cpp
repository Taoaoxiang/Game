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

unsigned RULE::recursive21(PLAYER player, DEALER dealer, 
	std::vector<unsigned> vec_P, std::vector<CARD> vec_C)
{
	PLAYER *pP = &player;
	DEALER *dD = &dealer;
	std::vector<unsigned> *vP = &vec_P;
	std::vector<CARD> *vC = &vec_C;
	unsigned points = getPoints(*pP);
	if (points >= 21) {
		vP->push_back(points);
		playerPushToHand(*pP, *(pP->deal));
		if (vC->size() != 0) {
			nextAndShow(*pP, *dD, *vC);
			points = recursive21(*pP, *dD, *vP, *vC);
			return points;
		}
		else { return points; }
	}
	else { return points; }	
}

void RULE::nextAndShow(PLAYER &p, DEALER &d, 
	std::vector<CARD> &v1)
{
	p.cards->clear();
	p.initCard(v1.back());
	p.initCard(d.draw());
	v1.pop_back();
	p.showCards();
}

unsigned RULE::playerHit(PLAYER p, DEALER d)
{
	p.initCard(d.draw());
	p.showCards();
	return getPoints(p);
}

unsigned RULE::playerStand(PLAYER p)
{
	return getPoints(p);
}

void RULE::playerPushToHand(PLAYER p, long l)
{
	std::vector<CARD> current_cards = *p.cards;
	unsigned current_points = getPoints(current_cards);
	long current_deal = l;

	p.hand->vecCards->push_back(current_cards);
	p.hand->vecPoints->push_back(current_points);
	p.hand->vecDeals->push_back(current_deal);
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
				std::cout << "SYSTEM: You choose to double your bet." << std::endl
					<< "        " << "Your bet is: $" << *p.deal << ".\n"
					<< "        " << "You have $" << *p.money << " left." << std::endl;
				p.initCard(d.draw());
				p.showCards();
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
	
	// This is the temp stack of splited cards
	std::vector<CARD> tmpCards;

	// This temporary points will be pushed to p.hand->vecPoints
	unsigned points = 0; 
	std::string letter;

	while (true) {
		// if player has money to get double
		if (*p.deal <= *p.money && p.cards->size() == 2) {
			// if the initial cards splitable
			if (true || splitable((*p.cards)[0], (*p.cards)[1])) {
				std::cout << msg.str() << '\n'
					<< "        " << "Double: (D) or (d)\n"
					<< "        " << "Split:  (P) or (p)\n"
					<< "        " << "Please choose, default stand: ";
				std::cin >> letter;
				switch (letter[0]) {
				case 'P': case 'p':
				{
					// to be able to declare variable within switch
					// we have to use parenthesis 
					*p.splitTimes += 1;
					CARD tmpA1 = p.cards->back();
					*p.money -= *p.deal;
					tmpCards.push_back(tmpA1);
					p.cards->pop_back();
					p.initCard(d.draw());
					std::cout << "SYSTEM: You choose to split." << std::endl;
					p.showCards();
					break;
				}
				case 'H': case 'h':
					points = playerHit(p, d);
					if ((points = recursive21(p, d, v_P, tmpCards)) >= 21) { return v_P; }
					else { break; }
				case 'S': case 's':
					points = playerStand(p);
					v_P.push_back(points);
					playerPushToHand(p, *p.deal);
					std::cout << "SYSTEM: You choose to stand." << std::endl;
					if (tmpCards.size() != 0) {
						nextAndShow(p, d, tmpCards);
						if ((points = recursive21(p, d, v_P, tmpCards)) >= 21) { return v_P; }
						else { break; }
					}
					else { return v_P; }
				case 'D': case 'd':
					*p.money -= *p.deal;
					std::cout << "SYSTEM: You choose to double your bet." << std::endl
						<< "        " << "Your bet is: $" << (2 * (*p.deal)) << ".\n"
						<< "        " << "You have $" << *p.money << " left." << std::endl;
					points = playerHit(p, d);
					v_P.push_back(points);
					playerPushToHand(p, (2*(*p.deal)));
					if (tmpCards.size() != 0) {
						nextAndShow(p, d, tmpCards);
						if ((points = recursive21(p, d, v_P, tmpCards)) >= 21) { return v_P; }
						else { break; }
					}
					else { return v_P; }
				default:
					points = playerStand(p);
					v_P.push_back(points);
					playerPushToHand(p, *p.deal);
					std::cout << "SYSTEM: You choose to stand." << std::endl;
					if (tmpCards.size() != 0) {
						nextAndShow(p, d, tmpCards);
						if ((points = recursive21(p, d, v_P, tmpCards)) >= 21) { return v_P; }
						else { break; }
					}
					else { return v_P; }
				} 
				// end of one decision
			} 
			// end of splitable cards
			else {
				std::cout << msg.str() << '\n'
					<< "        " << "Double: (D) or (d)\n"
					<< "        " << "Please choose, default stand: ";
				std::cin >> letter;
				switch (letter[0]) {
				case 'H': case 'h':
					points = playerHit(p, d);
					if ((points = recursive21(p, d, v_P, tmpCards)) >= 21) { return v_P; }
					else { break; }
				case 'S': case 's':
					points = playerStand(p);
					v_P.push_back(points);
					playerPushToHand(p, *p.deal);
					std::cout << "SYSTEM: You choose to stand." << std::endl;
					if (tmpCards.size() != 0) {
						nextAndShow(p, d, tmpCards);
						if ((points = recursive21(p, d, v_P, tmpCards)) >= 21) { return v_P; }
						else { break; }
					}
					else { return v_P; }
				case 'D': case 'd':
					*p.money -= *p.deal;
					std::cout << "SYSTEM: You choose to double your bet." << std::endl
						<< "        " << "Your bet is: $" << (2 * (*p.deal)) << ".\n"
						<< "        " << "You have $" << *p.money << " left." << std::endl;
					points = playerHit(p, d);
					v_P.push_back(points);
					playerPushToHand(p, (2 * (*p.deal)));
					if (tmpCards.size() != 0) {
						nextAndShow(p, d, tmpCards);
						if ((points = recursive21(p, d, v_P, tmpCards)) >= 21) { return v_P; }
						else { break; }
					}
					else { return v_P; }
				default:
					points = playerStand(p);
					v_P.push_back(points);
					playerPushToHand(p, *p.deal);
					std::cout << "SYSTEM: You choose to stand." << std::endl;
					if (tmpCards.size() != 0) {
						nextAndShow(p, d, tmpCards);
						if ((points = recursive21(p, d, v_P, tmpCards)) >= 21) { return v_P; }
						else { break; }
					}
					else { return v_P; }
				}
			}
		} 
		// if player doesn't have money to get double
		else {
			std::cout << msg.str() << "\n"
				<< "        " << "Please choose, default stand: ";
			std::cin >> letter;
			switch (letter[0]) {
			case 'H': case 'h':
				points = playerHit(p, d);
				if ((points = recursive21(p, d, v_P, tmpCards)) >= 21) { return v_P; }
				else { break; }
			case 'S': case 's':
				points = playerStand(p);
				v_P.push_back(points);
				playerPushToHand(p, *p.deal);
				std::cout << "SYSTEM: You choose to stand." << std::endl;
				if (tmpCards.size() != 0) {
					nextAndShow(p, d, tmpCards);
					if ((points = recursive21(p, d, v_P, tmpCards)) >= 21) { return v_P; }
					else { break; }
				} 
				else { return v_P; }
			default:
				points = playerStand(p);
				v_P.push_back(points);
				playerPushToHand(p, *p.deal);
				std::cout << "SYSTEM: You choose to stand." << std::endl;
				if (tmpCards.size() != 0) {
					nextAndShow(p, d, tmpCards);
					if ((points = recursive21(p, d, v_P, tmpCards)) >= 21) { return v_P; }
					else { break; }
				}
				else { return v_P; }
			}
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

unsigned RULE::dealerTurnWSplit(DEALER d, std::vector<unsigned> ps)
{
	unsigned points;
	if (ps.size() == 1) { points = dealerTurn(d, ps[0]); }
	else if (ps.size() > 1 ) {
		auto minPP = std::min_element(ps.begin(), ps.end());
		if (*minPP > 21) { points = dealerTurn(d, *minPP); }
		else { points = dealerTurn(d, 21); }
	}
	else {
		std::cout << "SYSERR: No Points of Player's Cards." << std::endl;
		return 0;
	}
	return points;
}
