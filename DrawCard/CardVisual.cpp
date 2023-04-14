//
// Created by Paolo Octoman on 11/9/22.
//

#include "CardVisual.h"
#include <string>



CardVisual::CardVisual() : CardVisual(HEARTS, ACE) {

    initialize();

}

CardVisual::CardVisual(suitEnum suit, rankEnum rank) : _suit(suit) , _rank(rank){

    initialize();
}

CardVisual::CardVisual(suitEnum suit, rankEnum rank, float x, float y) : _suit(suit) , _rank(rank) {
    setupBackground(x,y);
    setupRank();
    setupSuit();
}

void CardVisual::setupBackground(float x, float y) {
    background.setSize({68, 108.8});
    background.setPosition({x,y});
}


void CardVisual::initialize() {

    setupBackground();
    setupRank();
    setupSuit();
}

void CardVisual::draw(sf::RenderTarget& window, sf::RenderStates states) const{
    states.transform = getTransform();
    window.draw(background, states);
    window.draw(suit, states);
    window.draw(rank, states);
    window.draw(udrank, states);
}

std::string CardVisual::rankToString() {
    switch (_rank) {
        case ACE:
            return "A";
        case TWO:
            return "2";
        case THREE:
            return "3";
        case FOUR:
            return "4";
        case FIVE:
            return "5";
        case SIX:
            return "6";
        case SEVEN:
            return "7";
        case EIGHT:
            return "8";
        case NINE:
            return "9";
        case TEN:
            return "10";
        case JACK:
            return "J";
        case QUEEN:
            return "Q";
        case KING:
            return "K";
    }
}

std::string CardVisual::suitToString() {
    switch (_suit) {
        case HEARTS:
            return "Images/heart.png";
        case CLUBS:
            return "Images/club.png";
        case DIAMONDS:
            return "Images/diamonds.png";
        case SPADES:
            return "Images/spades.png";
    }
}

void CardVisual::setupBackground() {
    background.setSize({68, 108.8});
    background.setPosition({500,100});
}

void CardVisual::setupRank() {
    if(!font.loadFromFile("Fonts/OpenSans-Bold.ttf"))
        exit(20);
    rank.setFont(font);
    rank.setString(rankToString());
    rank.setCharacterSize(23);
    udrank.setFont(font);
    udrank.setString(rankToString());
    udrank.setCharacterSize(23);

    if((_suit == HEARTS) || (_suit == DIAMONDS)){
        rank.setFillColor(sf::Color::Red);
        udrank.setFillColor(sf::Color::Red);
    }
    else{
        rank.setFillColor(sf::Color::Black);
        udrank.setFillColor(sf::Color::Black);
    }

    rank.setPosition(background.getGlobalBounds().left, background.getGlobalBounds().top-5);
    udrank.rotate(180);
    udrank.setPosition((background.getGlobalBounds().left+background.getGlobalBounds().width),(background.getGlobalBounds().top+background.getGlobalBounds().height+5));
}






void CardVisual::setupSuit() {
    if(!texture.loadFromFile(suitToString()))
        exit (21);
    suit.setTexture(texture);
    if(_suit == DIAMONDS){ //some of the pngs are different sizes and so all these just resize and place accordingly
        suit.setScale(0.08,0.08);
        suit.setPosition((background.getGlobalBounds().left+background.getGlobalBounds().left+background.getGlobalBounds().width)/2 -20, (background.getGlobalBounds().top+background.getGlobalBounds().top+background.getGlobalBounds().height)/2 -20);
    }
    if(_suit == HEARTS){
        suit.setScale(0.35,0.35);
        suit.setPosition((background.getGlobalBounds().left+background.getGlobalBounds().left+background.getGlobalBounds().width)/2 -15, (background.getGlobalBounds().top+background.getGlobalBounds().top+background.getGlobalBounds().height)/2 -15);
    }
    if(_suit == CLUBS){
        suit.setScale(0.4,0.4);
        suit.setPosition((background.getGlobalBounds().left+background.getGlobalBounds().width +background.getGlobalBounds().left)/2 -15, (background.getGlobalBounds().top+background.getGlobalBounds().top+background.getGlobalBounds().height)/2 -15);
    }
    if(_suit == SPADES){
        suit.setScale(0.4,0.4);
        suit.setPosition((background.getGlobalBounds().left+background.getGlobalBounds().left+background.getGlobalBounds().width)/2 -15, (background.getGlobalBounds().top+background.getGlobalBounds().top+background.getGlobalBounds().height)/2 - 15);
    }
}

CardVisual::CardVisual(suitEnum suit, rankEnum rank, std::string big) : _suit(suit) , _rank(rank){
    initializeBIG();
}

void CardVisual::setupRankBIG() {
    if(!font.loadFromFile("Fonts/OpenSans-Bold.ttf"))
        exit(20);
    rank.setFont(font);
    rank.setString(rankToString());
    rank.setCharacterSize(65);
    udrank.setFont(font);
    udrank.setString(rankToString());
    udrank.setCharacterSize(65);

    if((_suit == HEARTS) || (_suit == DIAMONDS)){
        rank.setFillColor(sf::Color::Red);
        udrank.setFillColor(sf::Color::Red);
    }
    else{
        rank.setFillColor(sf::Color::Black);
        udrank.setFillColor(sf::Color::Black);
    }

    rank.setPosition(background.getGlobalBounds().left, background.getGlobalBounds().top-10);
    udrank.rotate(180);
    udrank.setPosition((background.getGlobalBounds().left+background.getGlobalBounds().width),(background.getGlobalBounds().top+background.getGlobalBounds().height+10));
}

void CardVisual::setupSuitBIG() {
    if(!texture.loadFromFile(suitToString()))
        exit (21);
    suit.setTexture(texture);
    if(_suit == DIAMONDS){ //some of the pngs are different sizes and so all these just resize and place accordingly
        suit.setScale(0.25,0.25);
        suit.setPosition((background.getGlobalBounds().left+background.getGlobalBounds().width)/2, (background.getGlobalBounds().top+background.getGlobalBounds().height)/2);
    }
    if(_suit == HEARTS){
        suit.setScale(1.1,1.1);
        suit.setPosition((background.getGlobalBounds().left+background.getGlobalBounds().width)/2 + 15, (background.getGlobalBounds().top+background.getGlobalBounds().height)/2 + 15);
    }
    if(_suit == CLUBS){
        suit.setPosition((background.getGlobalBounds().left+background.getGlobalBounds().width)/2, (background.getGlobalBounds().top+background.getGlobalBounds().height)/2);
    }
    if(_suit == SPADES){
        suit.setPosition((background.getGlobalBounds().left+background.getGlobalBounds().width)/2 + 15, (background.getGlobalBounds().top+background.getGlobalBounds().height)/2 + 10);
    }

}

void CardVisual::setupBackgroundBIG() {
    background.setSize({200, 320});
    background.setPosition({100,100});
}

void CardVisual::initializeBIG() {
    setupBackgroundBIG();
    setupRankBIG();
    setupSuitBIG();
}







