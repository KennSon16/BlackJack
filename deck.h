#include <iostream>

#include <string>

using namespace std;

#include "card.h"
#include <string>
#ifndef DECK_H
#define DECK_H

class Deck{
private:
    static const int NUMBER_OF_CARDS = 52;
    static const int NUMBER_OF_SUITS = 4;
    static const int NUMBER_OF_RANKS = 13;
    int cardsRemaining;

    Card deck[NUMBER_OF_CARDS];
    string suits[NUMBER_OF_SUITS] = {"Spades", "Hearts" , "Diamond" , "Clubs"};
    string ranks[NUMBER_OF_RANKS] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};

public:
    Deck(){
        for(int i = 0; i < NUMBER_OF_CARDS; i++){
            deck[i] = Card(ranks[i % NUMBER_OF_RANKS], suits[i / NUMBER_OF_RANKS]);
        }
        cardsRemaining = NUMBER_OF_CARDS;
    };
    void refreshDeck();
    Card deal();
    void shuffle();
    int cardsLeft();
    void showDeck();
};


#endif