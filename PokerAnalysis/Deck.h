//
// Created by Paolo Octoman on 12/14/22.
//

#ifndef CS3APORTFOLIO_DECK_H
#define CS3APORTFOLIO_DECK_H


#include <iostream>
#include <cstdlib>
#include <vector>
#include "Card.h"
#include <random>
class Deck {
private:
    std::vector<Card>deckVec;

public:
    static std::linear_congruential_engine<unsigned int, 48271, 0, 2147483647> rd;

public:

    Deck(); // this is the constructor
    void shuffle(); // puts cards in random order
    int getSize();
    friend std::ostream& operator<<(std::ostream& out, Deck& deck); // prints all the cards to the console

    Card dealCard(); // returns the next card in the deck
};


#endif