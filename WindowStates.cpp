//
// Created by Paolo Octoman on 12/15/22.
//

#include "WindowStates.h"

void WindowStates::toggleState(int state) {
    switch (state) {
        case 1:
            menuShowing = true;
            snakeShowing = false;
            pokerShowing = false;
            pongShowing = false;
            THGShowing = false;
            drawCardShowing = false;
            GCShowing = false;
            bouncingBallShowing = false;
            break;
        case 2:
            menuShowing = false;
            snakeShowing = true;
            pokerShowing = false;
            pongShowing = false;
            THGShowing = false;
            drawCardShowing = false;
            GCShowing = false;
            bouncingBallShowing = false;
            break;

        case 3:
            menuShowing = false;
            snakeShowing = false;
            pokerShowing = true;
            pongShowing = false;
            THGShowing = false;
            drawCardShowing = false;
            GCShowing = false;
            bouncingBallShowing = false;
            break;

        case 4:
            menuShowing = false;
            snakeShowing = false;
            pokerShowing = false;
            pongShowing = true;
            THGShowing = false;
            drawCardShowing = false;
            GCShowing = false;
            bouncingBallShowing = false;
            break;

        case 5:
            menuShowing = false;
            snakeShowing = false;
            pokerShowing = false;
            pongShowing = false;
            THGShowing = true;
            drawCardShowing = false;
            GCShowing = false;
            bouncingBallShowing = false;
            break;

        case 6:
            menuShowing = false;
            snakeShowing = false;
            pokerShowing = false;
            pongShowing = false;
            THGShowing = false;
            drawCardShowing = true;
            GCShowing = false;
            bouncingBallShowing = false;
            break;

        case 7:
            menuShowing = false;
            snakeShowing = false;
            pokerShowing = false;
            pongShowing = false;
            THGShowing = false;
            drawCardShowing = false;
            GCShowing = true;
            bouncingBallShowing = false;
            break;

        case 8:
            menuShowing = false;
            snakeShowing = false;
            pokerShowing = false;
            pongShowing = false;
            THGShowing = false;
            drawCardShowing = false;
            GCShowing = false;
            bouncingBallShowing = true;
            break;


    }

}

bool WindowStates::isMenuShowing() const {
    return menuShowing;
}

bool WindowStates::isSnakeShowing() const {
    return snakeShowing;
}

bool WindowStates::isPokerShowing() const {
    return pokerShowing;
}

bool WindowStates::isPongShowing() const {
    return pongShowing;
}

bool WindowStates::isThgShowing() const {
    return THGShowing;
}

bool WindowStates::isDrawCardShowing() const {
    return drawCardShowing;
}

bool WindowStates::isGcShowing() const {
    return GCShowing;
}

bool WindowStates::isBouncingBallShowing() const {
    return bouncingBallShowing;
}

WindowStates::WindowStates() {
    menuShowing = true;
    snakeShowing = false;
    pokerShowing = false;
    pongShowing = false;
    THGShowing = false;
    drawCardShowing = false;
    GCShowing = false;
    bouncingBallShowing = false;
}
