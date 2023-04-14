//
// Created by Paolo Octoman on 11/7/22.
//

#include "Card.h"
#include <iostream>


Card::Card() {
    suit = HEARTS;
    rank = ACE;
    setRankString();
    setSuitString();
    setRankNumOrder();
}

Card::Card(suitEnum suitPar, rankEnum rankPar) {
    suit = suitPar;
    rank = rankPar;
    setRankString();
    setSuitString();
    setRankNumOrder();
}

Card::Card(std::string suitPar, std::string rankPar) {
    suitString = suitPar;
    rankString = rankPar;
    setRankNumOrder();


}


void Card::setSuitString() {
    switch (suit) {
        case HEARTS:
            suitString= "Hearts";
            break;
        case CLUBS:
            suitString= "Clubs";
            break;
        case DIAMONDS:
            suitString= "Diamonds";
            break;
        case SPADES:
            suitString= "Spades";
            break;
    }
}

void Card::setRankString() {
    switch (rank) {
        case ACE:
            rankString= "Ace";
            break;
        case TWO:
            rankString= "Two";
            break;
        case THREE:
            rankString= "Three";
            break;
        case FOUR:
            rankString= "Four";
            break;
        case FIVE:
            rankString= "Five";
            break;
        case SIX:
            rankString= "Six";
            break;
        case SEVEN:
            rankString= "Seven";
            break;
        case EIGHT:
            rankString= "Eight";
            break;
        case NINE:
            rankString= "Nine";
            break;
        case TEN:
            rankString= "Ten";
            break;
        case JACK:
            rankString= "Jack";
            break;
        case QUEEN:
            rankString= "Queen";
            break;
        case KING:
            rankString= "King";
            break;
    }
}

void Card::setSuit(suitEnum suitPar) {
    suit = suitPar;
}

void Card::setRank(rankEnum rankPar) {
    rank = rankPar;
}


std::ostream &operator<<(std::ostream &out, const Card &card) {
    out << card.rankString << " of " << card.suitString;
    return out;
}


suitEnum Card::getSuit() const {
    return suit;
}

rankEnum Card::getRank() const {
    return rank;
}

void Card::setRankNumOrder() {
    switch (rank) {
        case ACE:
            rankNumOrder= 14;
            break;
        case TWO:
            rankNumOrder= 2;
            break;
        case THREE:
            rankNumOrder= 3;
            break;
        case FOUR:
            rankNumOrder= 4;
            break;
        case FIVE:
            rankNumOrder= 5;
            break;
        case SIX:
            rankNumOrder= 6;
            break;
        case SEVEN:
            rankNumOrder= 7;
            break;
        case EIGHT:
            rankNumOrder= 8;
            break;
        case NINE:
            rankNumOrder= 9;
            break;
        case TEN:
            rankNumOrder= 10;
            break;
        case JACK:
            rankNumOrder= 11;
            break;
        case QUEEN:
            rankNumOrder= 12;
            break;
        case KING:
            rankNumOrder= 13;
            break;
    }
}

int Card::getRankNumOrder() const {
    return rankNumOrder;
}




