//
// Created by Paolo Octoman on 12/14/22.
//

#ifndef CS3APORTFOLIO_FOOD_H
#define CS3APORTFOLIO_FOOD_H

#include <SFML/Graphics.hpp>



class Food : public sf::Transformable, public sf::Drawable{
private:
    sf::Texture daveTexture;
    sf::Sprite dave;
    sf::Texture daveTexture2;
    sf::Sprite dave2;


public:
    Food(sf::VideoMode videoMode);
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    sf::FloatRect getGlobalBounds();
    void relocate( sf::Vector2i pos);
    sf::Vector2i generatePos(sf::VideoMode videoMode);


};


#endif