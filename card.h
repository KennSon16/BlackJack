#include <iostream>
#include <string>
using namespace std;

#ifndef CARD_H
#define CARD_H

class Card{
private:
    string rank;
    string suit;
    int value;

public:
    Card(){
        rank = "0";
        suit = "0";
        value = 0;
    };
    void setValue();
    Card(string r, string s);
    void setCard(string r, string s);
    int getValue();
    string getRank();
    string getSuit();
    void showCard();
};


#endif
