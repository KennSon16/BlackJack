#include <iostream>
#include <string>
#include "card.h"
#include "deck.h"
using namespace std;

void countValueOfHand(Card x[], int size, int arr[])
{
    arr[0] = 0;
    arr[1] = 0;
    // sample array passed {10, A}
    // Case 1: Ace is 1 or 11 when needed to be
    bool isThereAce = false;
    for(int i = 0; i < size; i++)
    {
        if(x[i].getRank() == "Ace")
        {
            isThereAce = true;
        }
        arr[0] += x[i].getValue(); // adds every value in the player's hand, A is added as '1'
    }
    if(isThereAce)
    {
        // specific case: A, 9, A = 14   [11, 21], you cant have more than two aces acting as 11
        arr[1] = arr[0] + 10;
    }
    else{
        arr[1] = arr[0];
    }
}

void printCards(Card x[], int size){
    for(int i = 0; i < size - 1; i++){
        cout << " [" << x[i].getRank() << " of " << x[i].getSuit() << "] " << " + ";
    }
    cout << " [" << x[size - 1].getRank() << " of " << x[size - 1].getSuit() << "] " << endl << endl;

}

void gameOverTxt(){
    cout << "Games Over!!!" << endl;
    cout << "Enter \'q\' to quit. Enter any other character to restart." << endl;
}

int findDealerBestValue(int arr[], int playerValue){
    // example case: playerValue = 17; dealer hand = [11, 21] (A + 10)
    // case 1: dealer win
    // case 2: player win
    // case 3: tie
    if(arr[1] <= 21 && arr[1] >= playerValue){
        return arr[1];
    }
    return arr[0];
}

int findSmaller(int arr[]){
    if(arr[0] < arr[1]){
        return arr[0];
    }
    return arr[1];
}

int main() {
    cout << "Hello, Welcome to Blackjack!!" << "\n" <<"Enter \'q\' to quit. Enter any other character to continue." << endl;
    char gameOver;
    cin >> gameOver;
    Deck myDeck;
    while (gameOver != 'q')
    {
        cout << "Preparing game..." << endl;
        myDeck.shuffle();
        Card playerCard[13];
        int playerCardAmount = 2;
        int dealerCardAmount = 2;
        bool playerLost = false;
        playerCard[0] = myDeck.deal();
        playerCard[1] = myDeck.deal();
        cout << "Your cards:" << endl;
        printCards(playerCard, playerCardAmount);
        Card compCard[10];
        compCard[0] = myDeck.deal();
        compCard[1] = myDeck.deal();
        cout << "Dealer\'s Cards:" << endl;
        cout << " [" << compCard[0].getRank() << " of " << compCard[0].getSuit() << "] " << "+ [???]" << endl << endl;

        char hit;
        int playerArr[] = {0, 0};
        countValueOfHand(playerCard, playerCardAmount, playerArr);
        int dealerArr[]= {0, 0};
        countValueOfHand(compCard, dealerCardAmount, dealerArr);
        int playerValue = findSmaller(playerArr);
        int dealerValue = findDealerBestValue(dealerArr, playerValue);
        // Player and dealer given two cards check
        // dealer has one hidden card check
        // player can hit or stop check
        // after player stops, dealer reveals hands
        // dealer tries to beat the player
        while (playerValue < 21)
        {
            cout << "Enter: \n" << "\'0\' to hit\n" << "\'1\' to stay \n";
            cin >> hit;
            while ( hit != '0' && hit != '1' )
            {
                cout << "Error: value inputed is neither a 0 or 1. Please try again." << endl;
                cin >> hit;
            }

            if (hit == '1') break;
            if (hit == '0')
            {
                playerCardAmount++;
                playerCard[playerCardAmount - 1] = myDeck.deal();
                cout << "Your cards:" << endl;
                printCards(playerCard, playerCardAmount);
                countValueOfHand(playerCard, playerCardAmount, playerArr);
                playerValue = findSmaller(playerArr);

                if(playerArr[0] > 21 && playerArr[1] > 21){
                    playerLost = true;
                    break;
                }
            }
        }
        if(playerLost){
            cout << "The value of your hand is over 21. You lost." << endl;
            gameOverTxt();
        }
        else{
            cout << "Showing Dealers Hand!!!" << endl;
            printCards(compCard, dealerCardAmount);
            dealerValue = findDealerBestValue(dealerArr, playerValue);
            while (dealerValue <= 16)
            {
                dealerCardAmount++;
                compCard[dealerCardAmount - 1] = myDeck.deal();
                countValueOfHand(compCard, dealerCardAmount, dealerArr);
                dealerValue = findDealerBestValue(dealerArr, playerValue);
                printCards(compCard, dealerCardAmount);
                if (dealerValue > 21)
                {
                    cout << "You win!" << endl;
                    gameOverTxt();
                    break;
                }
                else if (dealerValue > playerValue)
                {
                    cout << "The value of the dealer hand is larger than yours. You lost." << endl;
                    gameOverTxt();
                    break;
                }
                else if (dealerValue == playerValue)
                {
                    cout << "The value of the dealer hand is equal to yours. You tied." << endl;
                    gameOverTxt();
                    break;
                }
            }
        }
        cin >> gameOver;
    }
    cout << "Thanks for playing!" << endl;
    return 0;
}
