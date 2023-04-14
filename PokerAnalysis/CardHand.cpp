//
// Created by Paolo Octoman on 11/7/22.
//

#include "CardHand.h"
#include <algorithm>

void CardHand::addCard(Deck& deck) {
    hand.push_back(deck.dealCard());
    // sortByRank();
    //sortBySuit();
}
//

std::ostream &operator<<(std::ostream &out,  CardHand &handPar) {
    for (int i = 0; i < handPar.hand.size(); ++i) {
        out << i+1 << ". " << handPar.hand.at(i);
        out << std::endl;
    }

    return out;
}



CardHand::CardHand() {

}

void CardHand::sortByRank() {
    for (int j = 0; j < hand.size(); ++j) {


        for (int i = 0; i < hand.size() - 1; ++i) {
            if (hand.at(i).getRank() > hand.at(i + 1).getRank()) {
                Card temp = hand.at(i);
                hand.at(i) = hand.at(i + 1);
                hand.at(i + 1) = temp;
            }
        }
    }
}



int CardHand::getSize() {
    return hand.size();
}

Card CardHand::getCardAt(int index) {
    return hand.at(index);
}
