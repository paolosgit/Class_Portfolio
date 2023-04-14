//
// Created by Paolo Octoman on 12/14/22.
//

//
// Created by Paolo Octoman on 12/6/22.
//

#include "Food.h"
#include <cstdlib>
#include <ctime>

Food::Food(sf::VideoMode videoMode) {
    int  x, y;
    srand(time(0));
    x = rand() % (videoMode.width - 200);
    y = rand() % (videoMode.height - 200);


    daveTexture.loadFromFile("Images/DaveFromIPhone.png");
    dave.setTexture(daveTexture);
    dave.setScale(0.3, 0.3);
    dave.setPosition(x, y+55);

}

void Food::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    states.transform = getTransform();
    window.draw(dave, states);
}

sf::FloatRect Food::getGlobalBounds() {
    return dave.getGlobalBounds();
}

void Food::relocate( sf::Vector2i pos) {


    dave.setPosition(pos.x, pos.y);

}

sf::Vector2i Food::generatePos(sf::VideoMode videoMode) {
    int  x, y;
    srand(time(0));
    x = rand() % (videoMode.width - 200);
    y = 55 + (rand() % (videoMode.height - 250));

    sf::Vector2i pos(x,y);
    return pos;
}
