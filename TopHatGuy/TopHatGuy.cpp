//
// Created by Paolo Octoman on 10/19/22.
//

#include "TopHatGuy.h"
void TopHatGuy::draw(sf::RenderTarget& window, sf::RenderStates states) const{
    states.transform = getTransform();
    window.draw(top, states);
    window.draw(brim, states);
    window.draw(face, states);
}

TopHatGuy::TopHatGuy() {
    top.setSize({50,70});
    brim.setSize({80,25});
    face.setRadius(30);

    top.setPosition({105,60});
    brim.setPosition({top.getGlobalBounds().left-15,top.getGlobalBounds().top+45});
    face.setPosition({top.getGlobalBounds().left-5,top.getGlobalBounds().top+40});

    top.setFillColor(sf::Color::Black);
    brim.setFillColor(sf::Color::Black);
    face.setFillColor(sf::Color::Black);
}

void TopHatGuy::setPosition(sf::Vector2f pos) {
    sf::Transformable::setPosition(pos);



}

void TopHatGuy::setPosition(float x, float y) {
    setPosition({x,y});
}
