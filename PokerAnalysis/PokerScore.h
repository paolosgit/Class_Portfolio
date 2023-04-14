//
// Created by Paolo Octoman on 12/14/22.
//

#ifndef CS3APORTFOLIO_POKERSCORE_H
#define CS3APORTFOLIO_POKERSCORE_H

#include <vector>
#include <iostream>
#include "Scores.h"

class PokerScore {
private:
    int RoyalFLushCount;
    int straightFlushCount;
    int fourKindcount;
    int FHcount;
    int flushCount;
    int straightCount;      //all these count variables are only used when determining probability when drawing the
    int threeKind;          // output
    int twoPairCount;
    int onePairCount;
    int highCardCount;
    std::vector<Scores> scores;

public:

    PokerScore();

    //adds score enums to the scores vector
    void operator+=(const Scores& score);

    //adds one scores vector to another of 2 different PokerScore objects
    void operator+=(const PokerScore& pokerScorePar);


    //prints out the Poker score object (totals) to the console
    friend std::ostream& operator<<(std::ostream& out, PokerScore& scorePar);


    int size();
    int getRoyalFLushCount() const;
    int getStraightFlushCount() const;
    int getFourKindcount() const;
    int getFHcount() const;     //getters
    int getFlushCount() const;
    int getStraightCount() const;
    int getThreeKind() const;
    int getTwoPairCount() const;
    int getOnePairCount() const;

};


#endif //CS3APORTFOLIO_POKERSCORE_H
