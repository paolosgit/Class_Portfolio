//
// Created by Paolo Octoman on 12/14/22.
//

#ifndef CS3APORTFOLIO_CARD_H
#define CS3APORTFOLIO_CARD_H

#include "rankEnum.h"
#include "suitEnum.h"
#include <string>

class Card {
private:
    suitEnum suit;
    rankEnum rank;
    std::string suitString;
    std::string rankString;
    int rankNumOrder;      //set according to the rank enum, used for determining consecutiveness
public:

    //a switch case that sets the suitString var in respect to the given suit enum var
    void setSuitString();

    //a getter for rankNumOrder
    int getRankNumOrder() const;

    //a switch case that sets the rankString var in respect to the given rank enum var
    void setRankString();

    //a switch case that sets the rankNumOrder var in respect to the given rank enum var
    void setRankNumOrder();


    void setSuit(suitEnum suitPar);

    //rank getter
    rankEnum getRank() const;

    //suit getter
    suitEnum getSuit() const;

    void setRank(rankEnum rankPar);

    //overloaded exertion operator
    friend std::ostream& operator<<(std::ostream& out, const Card& card) ;

    Card(std::string suitPar, std::string rankPar);
    Card(suitEnum suitPar, rankEnum rankPar);
    Card();
};


#endif  //CS3APORTFOLIO_CARD_H
