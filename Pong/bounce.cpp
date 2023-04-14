//
// Created by Paolo Octoman on 10/7/22.
//
#include <SFML/Graphics.hpp>
#include <iostream>
#include "bounce.h"
#include "Paddle.h"

void Ball::bounce( sf::VideoMode videoMode){

    int width = videoMode.width;
    int height = videoMode.height;

    if((getGlobalBounds().left + getGlobalBounds().width) >= width){
        ballx = -ballx;
    }
    if(getGlobalBounds().left <= 0){
        ballx= -ballx;
    }
    if((getGlobalBounds().top + getGlobalBounds().height) >= height){
        bally = -bally ;
    }
    if(getGlobalBounds().top <= 0){
        bally= -bally;
    }
    move(ballx,bally);


}

Ball::Ball(sf::VideoMode videoMode){
    setPosition(videoMode.width /2,videoMode.height/2);
    setFillColor(sf::Color::Magenta);
    setRadius(50);

}

void Ball::bounce( sf::FloatRect leftPad,sf::FloatRect rightPad,sf::VideoMode videoMode){
    int height = videoMode.height;
    int width = videoMode.width;

    if((getGlobalBounds().top + getGlobalBounds().height) >= height){
        bally = -bally ;
    }
    if(getGlobalBounds().top <= 0){
        bally= -bally;
    }

    if((getGlobalBounds().intersects(rightPad))){
        ballx = -ballx;
    }
    if((getGlobalBounds().intersects(leftPad))){
        ballx = -ballx;
    }


    move(ballx,bally);

}

bool Ball::isOutOfBounds(sf::VideoMode videoMode) {

    int width = videoMode.width;


    if((getGlobalBounds().left + getGlobalBounds().width) >= width){
        return true;
    }
    if(getGlobalBounds().left <= 0){
        return true;
    }

    return false;
}

void Ball::reset(sf::VideoMode videoMode) {
    int width = videoMode.width;
    int height = videoMode.height;

    setPosition(videoMode.width/2, videoMode.height/2);
}



