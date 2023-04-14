//
// Created by Paolo Octoman on 11/7/22.
//

#include "CardHandScorer.h"

bool CardHandScorer::isRoyalFlush(CardHand hand) {
    bool isAllSameSuit = true;

    for (int i = 0; i < hand.getSize()-1; ++i) {
        if (hand.getCardAt(i).getSuit() !=hand.getCardAt(i+1).getSuit()){
            isAllSameSuit = false;
        }
    }

    if (isAllSameSuit == false){
        return false;

    }
    else
    {
        hand.sortByRank();
        if(hand.getCardAt(0).getRank() == TEN
           && hand.getCardAt(1).getRank() == JACK
           && hand.getCardAt(2).getRank() == QUEEN
           && hand.getCardAt(3).getRank() == KING
           && hand.getCardAt(4).getRank() == ACE){
            return true;
        }
    }

}

bool CardHandScorer::isStraightFlush(CardHand hand) {
    bool isAllSameSuit = true;

    for (int i = 0; i < hand.getSize()-1; ++i) {
        if (hand.getCardAt(i).getSuit() !=hand.getCardAt(i+1).getSuit()){
            isAllSameSuit = false;
        }
    }

    if (isAllSameSuit == false){

        return false;
    }
    else
    {
        hand.sortByRank();
        for (int i = 0; i < hand.getSize()-1; ++i) {
            if(hand.getCardAt(i).getRankNumOrder()!=(hand.getCardAt(i+1).getRankNumOrder()-1)){
                return false;
            }
        }
        return true;
    }
}

bool CardHandScorer::isFourOfAKind(CardHand hand) {
    hand.sortByRank();
    int count =0;

    for (int i = 1; i < hand.getSize()-1; ++i) {
        if (hand.getCardAt(i).getRank() == hand.getCardAt(i+1).getRank()){
            count+=1;
        }
    }
    if (count ==3){
        return true;
    }
    return false;
}

bool CardHandScorer::isFullHouse(CardHand hand) {
    hand.sortByRank();// two cases: first 2 and last 3 OR first 3 and last 2
    bool firstTwoRanksEqual = false;
    bool lastThreeRanksEqual = false;
    if (hand.getCardAt(0).getRank() ==hand.getCardAt(1).getRank()){
        firstTwoRanksEqual = true;
    }
    if (hand.getCardAt(2).getRank() ==hand.getCardAt(3).getRank()
        && (hand.getCardAt(3).getRank() ==hand.getCardAt(4).getRank())
        && (hand.getCardAt(2).getRank() ==hand.getCardAt(4).getRank())){
        lastThreeRanksEqual = true;
    }
    if ((firstTwoRanksEqual == true) && (lastThreeRanksEqual== true)){
        return true;
    }

    bool firstThreeRanksEqual = false;
    bool lastTwoRanksEqual = false;
    if (hand.getCardAt(0).getRank() ==hand.getCardAt(1).getRank()
        && (hand.getCardAt(1).getRank() ==hand.getCardAt(2).getRank())
        && (hand.getCardAt(0).getRank() ==hand.getCardAt(2).getRank())){
        firstThreeRanksEqual = true;
    }
    if (hand.getCardAt(3).getRank() ==hand.getCardAt(4).getRank()){
        lastTwoRanksEqual = true;
    }
    if((firstThreeRanksEqual== true)&&(lastTwoRanksEqual== true)){
        return true;
    }

    return false;



}

bool CardHandScorer::isFlush(CardHand hand) {

    for (int i = 0; i < hand.getSize()-1; ++i) {
        if (hand.getCardAt(i).getSuit() !=hand.getCardAt(i+1).getSuit()){
            return false;
        }
    }
    return true;
}

bool CardHandScorer::isStraight(CardHand hand) {
    hand.sortByRank();
    for (int i = 0; i < hand.getSize()-1; ++i) {
        if(hand.getCardAt(i).getRankNumOrder()!=(hand.getCardAt(i+1).getRankNumOrder()-1)){
            return false;
        }
    }
    return true;
}

bool CardHandScorer::isThreeOfAKind(CardHand hand) {
    hand.sortByRank();
    for (int i = 1; i < hand.getSize()-1; ++i) {
        if((hand.getCardAt(i).getRank() == hand.getCardAt(i-1).getRank())&&
           (hand.getCardAt(i).getRank() == hand.getCardAt(i+1).getRank())){
            return true;
        }
    }

    return false;
}

bool CardHandScorer::isTwoPair(CardHand hand) {
    hand.sortByRank(); // both pairs are the first 4; both pairs are last 4; one pair is first 2 and the other is the last 2

    //first case:
    if ((hand.getCardAt(0).getRank() ==hand.getCardAt(1).getRank())
        && hand.getCardAt(2).getRank() ==hand.getCardAt(3).getRank()){
        return true;
    }

    //second case
    if ((hand.getCardAt(1).getRank() ==hand.getCardAt(2).getRank())
        && hand.getCardAt(3).getRank() ==hand.getCardAt(4).getRank()){
        return true;
    }

    //third case
    if ((hand.getCardAt(0).getRank() ==hand.getCardAt(1).getRank())
        && hand.getCardAt(3).getRank() ==hand.getCardAt(4).getRank()){
        return true;
    }

    return false;
}

bool CardHandScorer::isOnePair(CardHand hand) {
    hand.sortByRank();
    for (int i = 0; i < hand.getSize()-1; ++i) {
        if(hand.getCardAt(i).getRank() ==hand.getCardAt(i+1).getRank()){
            return true;
        }
    }

    return false;
}

bool CardHandScorer::isHighCard(CardHand hand) {
    return true;
}

PokerScore CardHandScorer::scoreHand(CardHand hand) {
    PokerScore temp;
    if(isRoyalFlush(hand)){
        temp += ROYAL_FLUSH;
    }
    if(isStraightFlush(hand)){
        temp += STRAIGHT_FLUSH;
    }
    if(isFullHouse(hand)){
        temp += FULL_HOUSE;
    }
    if(isFlush(hand)){
        temp += FLUSH;
    }
    if(isFourOfAKind(hand)){
        temp += FOUR_OF_A_KIND;
    }
    if(isStraight(hand)){
        temp += STRAIGHT;
    }
    if(isThreeOfAKind(hand)){
        temp += THREE_OK_A_KIND;
    }
    if(isTwoPair(hand)){
        temp += TWO_PAIR;
    }
    if(isOnePair(hand)){
        temp += ONE_PAIR;
    }
    if(isHighCard(hand)){
        temp += HIGH_CARD;
    }

    return temp;



}

CardHandScorer::CardHandScorer() {

}






