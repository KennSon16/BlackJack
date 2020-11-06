#include <iostream>
#include <string>

using namespace std;

#include "card.h"

void Card::setValue()
{
    if(rank == "Ace")
    {
        value = 1;
    }
    else if (rank == "Jack" || rank == "Queen" || rank == "King")
    {
        value = 10;
    }
    else
    {
        value = stoi(rank);
    }
}

Card::Card(string r, string s)
{
    rank = r;
    suit = s;
    this->setValue();
}

void Card::setCard(string r, string s)
{
    rank = r;
    suit = s;
    this->setValue();
}
int Card::getValue()
{
    return value;
}
string Card::getRank()
{
    return rank;
}
string Card::getSuit()
{
    return suit;
}
void Card::showCard()
{
    cout << this->getRank() << suit << ", ";
}