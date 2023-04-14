//
// Created by Paolo Octoman on 11/7/22.
//
#include <algorithm>
#include <random>
#include "Deck.h"


auto Deck::rd = std::default_random_engine (time(NULL));


Deck::Deck() {
    for (suitEnum suitPar: {HEARTS, DIAMONDS, CLUBS, SPADES}) {
        for (rankEnum rankPar: { TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING,ACE}) {
            deckVec.push_back({suitPar,rankPar});
        }
    }

    shuffle();


}





void Deck::shuffle() { //found this from stack overflow when searching on how to shuffle a vector

    std::shuffle(deckVec.begin(), deckVec.end(), rd);

//    std::random_shuffle(deckVec.begin(), deckVec.end(),
//                        [&](int i) {
//                            return std::rand() % i;
//                        }
//                        );
}

std::ostream &operator<<(std::ostream &out,  Deck &deck) {
    for (int i = 0; i < deck.getSize(); ++i) {
        out << i+1 << ". " << deck.deckVec.at(i);
        out << std::endl;
    }

    return out;
}



Card Deck::dealCard() { //essentially just pops the front
    Card get = deckVec.back();
    deckVec.pop_back();

    return get;
}



int Deck::getSize() {
    return deckVec.size();
}


