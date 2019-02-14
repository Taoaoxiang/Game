#include <iostream>
#include <vector>
#include <array>
#include <string>
#include "card.h"

using namespace std;


const array<unsigned, 13> VALUES = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
const array<char, 4> SUITS = {'c', 'd', 'h', 's'};





std::vector<CARD> getDeck(int n)
{
	std::vector<CARD> vecCard;
	for (int i = 0; i < n; ++i) {
		for (const char &suit : SUITS) {
			for (const unsigned &value : VALUES) {
				CARD card(value, suit);
				vecCard.push_back(card);
			}
		}
	}
	return vecCard;
}
/*
class DECK 
{
public:
	DECK(int);
	void open(int);
	void shuffle();
    int draw(){ return 1; }
private:
    
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
	std::vector<CARD> deck = getDeck(1);
	for (std::vector <CARD> ::iterator id = deck.begin(); id != deck.end(); ++id) {
		cout << id->front() <<endl;
	}
    cout << card1.front() << endl;
/*    while (true){
    }
*/
    return 0;
}
