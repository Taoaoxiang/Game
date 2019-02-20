#include <iostream>
#include <vector>
#include <array>
#include <string>
#include "card.h"
#include "deck.h"
#include "dealer.h"









/*
class PLAYER
{
public:
	//void stand();
	//void hit();
	PLAYER(std::string playerName = "Player", long playerMoney = 0);
	void defName(std::string playerName = "Player");
	void defMoney(long playerMoney = 100000);
    std::string getName();
    long getMoney();
private:
	long playerMoney;
	std::string playerName;
};

PLAYER::PLAYER(std::string pN, long pM) 
{
	playerName = pN;
	playerMoney = pM;
}

void PLAYER::defName(std::string pN) 
{
	playerName = pN;
}

void PLAYER::defMoney(long pM) 
{ 
	playerMoney = pM; 
}

std::string PLAYER::getName()
{
    return playerName;
}

long PLAYER::getMoney()
{
    return playerMoney;
}
*/

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
	//cout << card1.front() << endl;
/*    while (true){
    }
*/
	cout << "END of GAME!" << endl;
    return 0;
}


