//
// Created by Paolo Octoman on 12/6/22.
//

#include "SnakeBody.h"

SnakeBody::SnakeBody(sf::VideoMode videoMode) {

    SingleCell first;
    snake.push_back(first);
    snake[0].setPosition(1020,660);



}

void SnakeBody::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    states.transform = getTransform();
    for (int i = 0; i < snake.size(); ++i) {
        window.draw(snake[i], states);
    }

}



void SnakeBody::grow() {
    SingleCell newCell;
    snake.push_back(newCell);



    if (GoingRight){
        snake[snake.size()-1].setPosition(snake[snake.size()-2].getPosition().x - 60, snake[snake.size()-2].getPosition().y);
    }
    if (GoingLeft){
        snake[snake.size()-1].setPosition(snake[snake.size()-2].getPosition().x + 60, snake[snake.size()-2].getPosition().y);
    }
    if (GoingUp){
        snake[snake.size()-1].setPosition(snake[snake.size()-2].getPosition().x, snake[snake.size()-2].getPosition().y + 60);
    }
    if (GoingDown){
        snake[snake.size()-1].setPosition(snake[snake.size()-2].getPosition().x, snake[snake.size()-2].getPosition().y - 60);
    }

}

bool SnakeBody::isGoingRight() const {
    return GoingRight;
}

bool SnakeBody::isGoingLeft() const {
    return GoingLeft;
}

bool SnakeBody::isGoingUp() const {
    return GoingUp;
}

bool SnakeBody::isGoingDown() const {
    return GoingDown;
}

int SnakeBody::getLength() {

    return snake.size();
}

void SnakeBody::move() {

    if(snake.size() ==1){
        if (GoingRight){
            snake[0].move(60, 0);
        }
        if (GoingLeft){
            snake[0].move(-60, 0);
        }
        if (GoingUp){
            snake[0].move(0, -60);
        }
        if (GoingDown){
            snake[0].move(0, 60);
        }
    }
    else
    {
        SingleCell temp = snake.back();
        snake.pop_back();
        if (GoingRight){
            snake.push_front(temp);
            snake[0].setPosition(snake[1].getPosition().x + 60, snake[1].getPosition().y);
        }
        if (GoingLeft){
            snake.push_front(temp);
            snake[0].setPosition(snake[1].getPosition().x - 60, snake[1].getPosition().y);
        }
        if (GoingUp){
            snake.push_front(temp);
            snake[0].setPosition(snake[1].getPosition().x, snake[1].getPosition().y - 60);
        }
        if (GoingDown){
            snake.push_front(temp);
            snake[0].setPosition(snake[1].getPosition().x, snake[1].getPosition().y + 60);
        }
    }


}

void SnakeBody::toggleDirection(char letter) {
    switch (letter){
        case 'L':
            GoingRight = false;
            GoingLeft = true;
            GoingUp = false;
            GoingDown = false;
            break;
        case 'U':
            GoingRight = false;
            GoingLeft = false;
            GoingUp = true;
            GoingDown = false;
            break;
        case 'D':
            GoingRight = false;
            GoingLeft = false;
            GoingUp = false;
            GoingDown = true;
            break;
        case 'R':
            GoingRight = true;
            GoingLeft = false;
            GoingUp = false;
            GoingDown = false;
            break;
        case '0':
            Dead = true;
            break;
        case '1':
            Dead = false;
            GoingRight = false;
            GoingLeft = false;
            GoingUp = false;
            GoingDown = false;
            break;

    }

}

sf::FloatRect SnakeBody::getLeadCellGB() {
    return snake[0].getGlobalBounds();
}

std::deque<SingleCell> SnakeBody::getSnake() {
    return snake;
}

SingleCell &SnakeBody::operator[](unsigned int index) {
    return snake[index];
}

bool SnakeBody::OutOfBounds(sf::VideoMode videoMode) {
    if (snake[0].getPosition().x >= videoMode.width - 60 && isGoingRight()){
        return true;
    }
    if (isGoingLeft() && snake[0].getPosition().x <= 0){
        return true;
    }
    if (snake[0].getPosition().y >= videoMode.height - 60 && isGoingDown()){
        return true;
    }
    if (isGoingUp() && snake[0].getPosition().y <= 60){
        return true;
    }

    return false;
}

bool SnakeBody::isSelfCollide() {
    for (int i = 1; i < getLength(); ++i) {
        if(snake[0].getGlobalBounds().intersects(snake[i].getGlobalBounds()))
        {
            return true;
        }
    }

    return false;
}

bool SnakeBody::isDead() {
    if (Dead){
        return true;
    }
    else
        return false;
}

void SnakeBody::restart(sf::VideoMode videoMode) {
    snake.clear();
    SingleCell first;
    snake.push_back(first);
    snake[0].setPosition(1020,660);

}








