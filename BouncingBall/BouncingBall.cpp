//
// Created by Paolo Octoman on 12/15/22.
//

#include <SFML/Graphics.hpp>
#include <iostream>
#include "BouncingBall.h"

void bounce(sf::CircleShape & circle,  float&  x, float& y, sf::VideoMode videoMode){

    int width = videoMode.width;
    int height = videoMode.height;

    if((circle.getGlobalBounds().left + circle.getGlobalBounds().width) >= width){
        x = -x;
    }
    if(circle.getGlobalBounds().left <= 0){
        x= -x;
    }
    if((circle.getGlobalBounds().top + circle.getGlobalBounds().height) >= height){
        y = -y ;
    }
    if(circle.getGlobalBounds().top <= 0){
        y= -y;
    }
    circle.move(x,y);


}