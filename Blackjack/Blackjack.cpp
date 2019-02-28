#include <iostream>
#include <vector>
#include <array>
#include <string>
#include "card.h"
#include "deck.h"
#include "dealer.h"
#include "player.h"
#include "table.h"
#include "rule.h"


int main()
{
	using namespace std;
	// A player comes to table #9.
	DEALER dealer1("Oliver");
	PLAYER player1("Millionaire", 1000000);
	TABLE table1;
	table1.defAll(9, dealer1, player1);
    dealer1.welcome(player1.getName());
    
	cout << "\nSYSTEM: START" << endl;
	// Dealer gets two decks of cards.
	// He then shuffles them.
	DECK deck1(2);
	dealer1.defDeck(deck1);
	while (true) {
		dealer1.shuffle();

		// 1. player makes a bet															 
		player1.makeBet();
		//cout << "\r" << endl;
		// 2. player and dealer initilize cards
		//	2.1 draw: player -> dealer -> player -> dealer 
		player1.initCard(dealer1.draw());
		dealer1.initCard(dealer1.draw());
		player1.initCard(dealer1.draw());
		dealer1.initCard(dealer1.draw());
		//	2.2 show cards
		dealer1.showInitCards();
		player1.showCards();

		std::vector<unsigned> v = player1.turnWSplit(dealer1);
		cout << "Test: " << v[0] << endl;

		if (table1.checkBlackjack() == 0) {
			// 3. player's turn
			//	(auto) Blackjack (==21, player turn ends)
			//	A. stand (no change, player turn ends)
			//	B. hit (one draw, next)
			//	C. double (one draw, player turn ends)
			//	(auto) Bust (>21, player turn ends)
			//	TODO: (opt) split #TODO: this one we will consider later.
			unsigned playerPoints = 0;
			playerPoints = player1.turn(dealer1);

			// 4. dealer choose to ()
			//	(auto) Blackjack (==21, dealer turn ends)
			//	(auto) player bust (dealer turn ends)
			//	(auto) dealer points > player points (dealer turn ends)
			//	A. stand (>=17, dealer turn ends)
			//	B. hit (<17, until >=17)
			//	(auto) Bust (>21, dealer turn ends)
			unsigned dealerPoints = 0;
			dealerPoints = dealer1.turn(playerPoints);

			// 5. compare
			table1.compare();
		}
		
		// 6. clear the table
		table1.clear();
		

		cout << "SYSTEM: End of round.\n" << endl;
	}


	// 
	



/*    while (true){
    }
*/
	cout << "END of GAME!" << endl;
    return 0;
}


