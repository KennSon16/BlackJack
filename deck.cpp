#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include "deck.h"

using namespace std;

void Deck::refreshDeck()
{
    for(int i = 0; i < NUMBER_OF_CARDS; i++)
    {
        deck[i] = Card(ranks[i % NUMBER_OF_RANKS], suits[i / NUMBER_OF_RANKS]);
    }
    cardsRemaining = NUMBER_OF_CARDS;
}
Card Deck::deal()
{
    Card topCard = deck[0];
    for(int i = 0; i < NUMBER_OF_CARDS - 1; i++){
        deck[i] = deck[i+1];
    }
    cardsRemaining--;
    return topCard;
}
void Deck::shuffle()
{
    srand(time(0));

    for (int i = 0; i < NUMBER_OF_CARDS; i++)
    {
        int num = rand() % NUMBER_OF_CARDS;
        Card temp = deck[i];
        deck[i] = deck[num];
        deck[num] = temp;
    }
}
int Deck::cardsLeft(){
    return cardsRemaining;
}
void Deck::showDeck()
{
    for(int r = 0; r < NUMBER_OF_SUITS; r++)
    {
        for(int c = 0 + (NUMBER_OF_RANKS * r); c < NUMBER_OF_RANKS + (NUMBER_OF_RANKS * r); c++)
        {
            cout << deck[c].getRank() << deck[c].getSuit() << " ";
        }
        cout << endl;
    }
}