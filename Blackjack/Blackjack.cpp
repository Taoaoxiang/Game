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
	CARD draw(DECK);
//private:

};

CARD DEALER::draw(DECK deck)
{
	CARD card = deck.draw();
	return card;
}

class PLAYER
{
public:
	//void stand();
	//void hit();
	PLAYER();
	PLAYER(std::string playerName = "Player");
	PLAYER(std::string playerName = "Player", long playerMoney = 100000);
	void defName(std::string playerName = "Player");
	void defMoney(long playerMoney = 100000);
    std::string getName();
    long getMoney();
private:
	long playerMoney;
	std::string playerName;
};

PLAYER::PLAYER()
{
	playerName = "Player";
	playerMoney = 100000;
    cout << playerMoney<< endl;
}

PLAYER::PLAYER(std::string pN)
{
	playerName = pN;
}

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

int main()
{
    DEALER dealer1;
    dealer1.welcome("millionaire");
    CARD card1(7, 's');
	DECK deck1(1) ;
	PLAYER pa();
    //long pm = pa.getMoney();
    //cout << pm << endl;
	
	//cout << card1.front() << endl;
/*    while (true){
    }
*/
    return 0;
}


