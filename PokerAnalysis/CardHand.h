//
// Created by Paolo Octoman on 12/14/22.
//

#ifndef CS3APORTFOLIO_CARDHAND_H
#define CS3APORTFOLIO_CARDHAND_H

#include "Deck.h"
#include <vector>

class CardHand {
private:
    std::vector<Card> hand;
public:
    CardHand();

    //add card to the hand vector while simultaneously uses the deck's dealCard function
    void addCard(Deck& deck);


    int getSize();
    Card getCardAt(int index);
    friend std::ostream& operator<<(std::ostream& out, CardHand& handPar); // prints all of the hand to the console

    //sorts the cards by rank order. lowest = 2 highest = Ace
    void sortByRank();



};


#endif