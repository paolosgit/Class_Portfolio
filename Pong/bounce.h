//
// Created by Paolo Octoman on 12/15/22.
//

#ifndef CS3APORTFOLIO_BOUNCE_H
#define CS3APORTFOLIO_BOUNCE_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Paddle.h"

class Ball : public sf::CircleShape {
private:
    float ballx = 0.25;
    float bally = 0.25;

public:
    void bounce( sf::VideoMode videoMode);
    void bounce( sf::FloatRect leftPad,sf::FloatRect rightPad,sf::VideoMode videoMode);
    Ball(sf::VideoMode videoMode);
    bool isOutOfBounds(sf::VideoMode videoMode);
    void reset(sf::VideoMode videoMode);
};


#endif //CS3APORTFOLIO_BOUNCE_H
