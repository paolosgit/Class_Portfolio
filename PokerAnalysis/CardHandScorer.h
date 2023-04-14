//
// Created by Paolo Octoman on 12/14/22.
//

#ifndef CS3APORTFOLIO_CARDHANDSCORER_H
#define CS3APORTFOLIO_CARDHANDSCORER_H

#include "CardHand.h"
#include "PokerScore.h"

class CardHandScorer {
private:
    CardHandScorer();
public:
    static bool isRoyalFlush(CardHand hand);//A, K, Q, J, 10, all the same suit.
    static bool isStraightFlush(CardHand hand); //five cards of the same suit and consecutive ranking
    static bool isFourOfAKind(CardHand hand);//four cards of the same ranking
    static bool isFullHouse(CardHand hand);//three cards of the same rank along with two cards of the same rank
    static bool isFlush(CardHand hand);//five cards of the same suit
    static bool isStraight(CardHand hand);//five cards in consecutive ranking
    static bool isThreeOfAKind(CardHand hand); //three cards of the same rank
    static bool isTwoPair(CardHand hand); //two cards of the same rank along with another two cards of the same rank
    static bool isOnePair(CardHand hand); //two cards of the same rank
    static bool isHighCard(CardHand hand); //highest card in the player’s hand

    static PokerScore scoreHand(CardHand hand);




};


#endif