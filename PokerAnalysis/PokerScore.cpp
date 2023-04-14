//
// Created by Paolo Octoman on 11/8/22.
//

#include "PokerScore.h"


void PokerScore::operator+=(const Scores &score) {
    scores.push_back(score);
}

int PokerScore::size() {
    return scores.size();
}

PokerScore::PokerScore() {

}

std::ostream &operator<<(std::ostream &out, PokerScore &scorePar) {
    scorePar.RoyalFLushCount = 0;
    out << "Royal Flush count: ";
    for (int i = 0; i < scorePar.size(); ++i) {
        if (scorePar.scores.at(i) == ROYAL_FLUSH){
            scorePar.RoyalFLushCount +=1;
        }
    }
    out << scorePar.RoyalFLushCount << std::endl;



    scorePar.straightFlushCount =0;
    out << "Straight Flush count: ";
    for (int i = 0; i < scorePar.size(); ++i) {
        if (scorePar.scores.at(i) == STRAIGHT_FLUSH){
            scorePar.straightFlushCount +=1;
        }
    }
    out << scorePar.straightFlushCount << std::endl;

    scorePar.fourKindcount =0;
    out << "Four of a Kind count: ";
    for (int i = 0; i < scorePar.size(); ++i) {
        if (scorePar.scores.at(i) == FOUR_OF_A_KIND){
            scorePar.fourKindcount +=1;
        }
    }
    out << scorePar.fourKindcount << std::endl;

    scorePar.FHcount =0;
    out << "Full House count: ";
    for (int i = 0; i < scorePar.size(); ++i) {
        if (scorePar.scores.at(i) == FULL_HOUSE){
            scorePar.FHcount +=1;
        }
    }
    out << scorePar.FHcount << std::endl;

    scorePar.flushCount =0;
    out << "Flush count: ";
    for (int i = 0; i < scorePar.size(); ++i) {
        if (scorePar.scores.at(i) == FLUSH){
            scorePar.flushCount +=1;
        }
    }
    out << scorePar.flushCount << std::endl;

    scorePar.straightCount =0;
    out << "Straight count: ";
    for (int i = 0; i < scorePar.size(); ++i) {
        if (scorePar.scores.at(i) == STRAIGHT){
            scorePar.straightCount +=1;
        }
    }
    out << scorePar.straightCount << std::endl;

    scorePar.threeKind =0;
    out << "Three of a Kind count: ";
    for (int i = 0; i < scorePar.size(); ++i) {
        if (scorePar.scores.at(i) == THREE_OK_A_KIND){
            scorePar.threeKind +=1;
        }
    }
    out << scorePar.threeKind<< std::endl;

    scorePar.twoPairCount =0;
    out << "Two Pair count: ";
    for (int i = 0; i < scorePar.size(); ++i) {
        if (scorePar.scores.at(i) == TWO_PAIR){
            scorePar.twoPairCount +=1;
        }
    }
    out << scorePar.twoPairCount<< std::endl;

    scorePar.onePairCount=0;
    out << "One Pair count: ";
    for (int i = 0; i < scorePar.size(); ++i) {
        if (scorePar.scores.at(i) == ONE_PAIR){
            scorePar.onePairCount +=1;
        }
    }
    out << scorePar.onePairCount << std::endl;

    scorePar.highCardCount =0;
    out << "High Card count: ";
    for (int i = 0; i < scorePar.size(); ++i) {
        if (scorePar.scores[i] == HIGH_CARD){
            scorePar.highCardCount +=1;
        }
    }
    out << scorePar.highCardCount << std::endl;


    return out;
}

void PokerScore::operator+=(const PokerScore &pokerScorePar) {
    for (int i = 0; i < pokerScorePar.scores.size(); ++i) {
        scores.push_back(pokerScorePar.scores.at(i));
    }
}

int PokerScore::getRoyalFLushCount() const {
    return RoyalFLushCount;
}

int PokerScore::getStraightFlushCount() const {
    return straightFlushCount;
}

int PokerScore::getFourKindcount() const {
    return fourKindcount;
}

int PokerScore::getFHcount() const {
    return FHcount;
}

int PokerScore::getFlushCount() const {
    return flushCount;
}

int PokerScore::getStraightCount() const {
    return straightCount;
}

int PokerScore::getThreeKind() const {
    return threeKind;
}

int PokerScore::getTwoPairCount() const {
    return twoPairCount;
}

int PokerScore::getOnePairCount() const {
    return onePairCount;
}



