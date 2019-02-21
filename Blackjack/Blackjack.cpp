#include <iostream>
#include <vector>
#include <array>
#include <string>
#include "card.h"
#include "deck.h"
#include "dealer.h"
#include "player.h"
#include "table.h"


int main()
{
	using namespace std;
	// A player comes to table #9.
	DEALER dealer1("Oliver");
	PLAYER player1("Millionaire", 1000000);
	TABLE table1;
	table1.defAll(9, dealer1, player1);
    dealer1.welcome(player1.getName());
    
	// Dealer gets two decks of cards.
	// He then shuffles them.
	DECK deck1(2);
	dealer1.defDeck(deck1);
	dealer1.shuffle();

	dealer1.draw();
	//deck1.printCurrentDeck();
	dealer1.draw();


/*    while (true){
    }
*/
	cout << "END of GAME!" << endl;
    return 0;
}


