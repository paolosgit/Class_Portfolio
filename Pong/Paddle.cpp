//
// Created by Paolo Octoman on 10/10/22.
//
#include "Paddle.h"

Paddle::Paddle() {
    setSize({50,300});
    setFillColor(sf::Color::Magenta);
    ;
}

void Paddle::movePaddleUp(sf::VideoMode videoMode) {
    float vertSpeed = 0.7;
    if (getGlobalBounds().top > 0) {
        move(0, -vertSpeed);
    }
}
void Paddle::movePaddleDown(sf::VideoMode videoMode) {
    float vertSpeed = 0.7;
    if (getGlobalBounds().top + getGlobalBounds().height < videoMode.height) {
        move(0, vertSpeed);
    }
}

void Paddle::setPaddlePos(float x, float y){
    setPosition(x,y);
}

sf::FloatRect Paddle::getDime(){
    return getGlobalBounds();
}

