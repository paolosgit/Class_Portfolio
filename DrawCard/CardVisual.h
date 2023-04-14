//
// Created by Paolo Octoman on 12/14/22.
//

#ifndef CS3APORTFOLIO_CARDVISUAL_H
#define CS3APORTFOLIO_CARDVISUAL_H
#include <SFML/Graphics.hpp>
#include "../PokerAnalysis/rankEnum.h"
#include "../PokerAnalysis/suitEnum.h"
#include <string>


class CardVisual : public sf::Drawable, public sf::Transformable{
private:
    sf::RectangleShape background;
    sf::Text rank;
    sf::Text udrank;
    sf::Sprite suit;
    sf::Texture texture;
    sf::Font font;
    suitEnum _suit;
    rankEnum _rank;
    std::string rankToString();
    std::string suitToString();
    void initialize();
    void initializeBIG();

public:
    CardVisual();
    CardVisual(suitEnum suit, rankEnum rank);
    CardVisual(suitEnum suit, rankEnum rank, float x, float y);

    void setupBackground(float x, float y);
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;

    void setupRank();
    void setupSuit();
    void setupBackground();


    CardVisual(suitEnum suit, rankEnum rank, std::string big);
    void setupRankBIG();
    void setupSuitBIG();
    void setupBackgroundBIG();




};


#endif //CS3APORTFOLIO_CARDVISUAL_H
