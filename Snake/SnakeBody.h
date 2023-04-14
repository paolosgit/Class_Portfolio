//
// Created by Paolo Octoman on 12/14/22.
//

#ifndef CS3APORTFOLIO_SNAKEBODY_H
#define CS3APORTFOLIO_SNAKEBODY_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <deque>
#include "SingleCell.h"

class SnakeBody : public sf::RectangleShape{
private:
    std::deque<SingleCell> snake;
    bool GoingRight = false;
    bool GoingLeft = false;
    bool GoingUp = false;
    bool GoingDown = false;
    bool Dead = false;




public:
    void toggleDirection(char letter);
    SnakeBody(sf::VideoMode videoMode);
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;

    void grow();
    bool isGoingRight() const;

    void move();

    bool isGoingLeft() const;


    bool isGoingUp() const;

    bool isGoingDown() const;

    int getLength();
    sf::FloatRect getLeadCellGB();
    std::deque<SingleCell> getSnake();
    SingleCell& operator[] (unsigned int index);
    bool OutOfBounds(sf::VideoMode videoMode);
    bool isSelfCollide();

    bool isDead();

    void restart(sf::VideoMode videoMode);



};


#endif //CS3APORTFOLIO_SNAKEBODY_H
