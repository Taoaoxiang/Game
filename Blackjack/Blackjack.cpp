#include <iostream>
#include <vector>
#include <array>
#include <string>
#include "card.h"
#include "deck.h"

using namespace std;


const array<unsigned, 13> VALUES = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
const array<char, 4> SUITS = {'c', 'd', 'h', 's'};






/*
class DECK 
{
public:
	DECK(int);
	void open(int);
	void shuffle();
    int draw(){ return 1; }
//private:
    
};
*/

class DEALER
{
public:
    void welcome() { cout << "Hello player!" << endl;}
    void welcome(string player) { cout << "Hello " << player << "!" << endl;}
};

int main()
{
    DEALER dealer1;
    dealer1.welcome();
    dealer1.welcome("millionaire");
    CARD card1(7, 's');
	DECK deck1(1) ;
	deck1.tep();
	
    //cout << card1.front() << endl;
/*    while (true){
    }
*/
    return 0;
}
