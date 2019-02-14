#include <iostream>
#include <vector>
#include <array>
#include <string>
#include "card.h"
#include "deck.h"

using namespace std;



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
	deck1.shuffle();
	cout << "-------------------" << endl;
	deck1.tep();
	cout << "Last: " << deck1.getLastCard().front() << endl;
	deck1.draw();
	cout << "Last: " << deck1.getLastCard().front() << endl;
	//cout << card1.front() << endl;
/*    while (true){
    }
*/
    return 0;
}
