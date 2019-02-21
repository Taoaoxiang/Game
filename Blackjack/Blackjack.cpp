#include <iostream>
#include <vector>
#include <array>
#include <string>
#include "card.h"
#include "deck.h"
#include "dealer.h"
#include "player.h"

class TABLE
{
public:
	TABLE();
	void defNumber(unsigned);
	void defDealer(DEALER);
	//void defPlayer();
private:
	unsigned tableNumber;
	DEALER *dealer;
	//PLAYER 
	// We have to serve many players at one table.
};

void TABLE::defNumber(unsigned n)
{
	tableNumber = n;
}

void TABLE::defDealer(DEALER d)
{
	dealer = &d;
}

int main()
{
	using namespace std;
    DEALER dealer1;
    dealer1.welcome("millionaire");
    CARD card1(7, 's');
	DECK deck1(1) ;
	dealer1.defDeck(deck1);
	dealer1.shuffle();
	dealer1.draw();
	deck1.printCurrentDeck();
	dealer1.draw();
	dealer1.draw();

	PLAYER player1("Millionaire", 1000000);

	string name = player1.getName();
	cout << name << endl;
	cout << player1.getMoney() << endl;

	//cout << card1.front() << endl;
/*    while (true){
    }
*/
	cout << "END of GAME!" << endl;
    return 0;
}


