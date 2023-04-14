//
// Created by Paolo Octoman on 12/15/22.
//

#ifndef CS3APORTFOLIO_PADDLE_H
#define CS3APORTFOLIO_PADDLE_H

#include <SFML/Graphics.hpp>
#include <vector>

class Paddle : public sf::RectangleShape {

public:
    Paddle();
    void movePaddleUp(sf::VideoMode videoMode);
    void movePaddleDown(sf::VideoMode videoMode);
    void setPaddlePos(float x, float y);
    sf::FloatRect getDime();
};
#endif //CS3APORTFOLIO_PADDLE_H
