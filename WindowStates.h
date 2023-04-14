//
// Created by Paolo Octoman on 12/15/22.
//

#ifndef CS3APORTFOLIO_WINDOWSTATES_H
#define CS3APORTFOLIO_WINDOWSTATES_H
#include <iostream>

class WindowStates {
private:
    bool menuShowing = false; // 1
    bool snakeShowing = false;// 2
    bool pokerShowing = false;// 3
    bool pongShowing = false;// 4
    bool THGShowing = false;// 5
    bool drawCardShowing = false;// 6
    bool GCShowing = false;// 7
    bool bouncingBallShowing = false;// 8
public:
    WindowStates();

    bool isMenuShowing() const;

    bool isSnakeShowing() const;

    bool isPokerShowing() const;

    bool isPongShowing() const;

    bool isThgShowing() const;

    bool isDrawCardShowing() const;

    bool isGcShowing() const;

    bool isBouncingBallShowing() const;

    void toggleState(int state);


};


#endif //CS3APORTFOLIO_WINDOWSTATES_H
