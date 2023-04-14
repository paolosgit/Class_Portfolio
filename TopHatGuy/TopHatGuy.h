//
// Created by Paolo Octoman on 12/15/22.
//

#ifndef CS3APORTFOLIO_TOPHATGUY_H
#define CS3APORTFOLIO_TOPHATGUY_H

#include <SFML/Graphics.hpp>


class TopHatGuy : public sf::Drawable, public sf::Transformable
{
public:
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    TopHatGuy();
    void setPosition(sf::Vector2f pos);

    void setPosition(float x, float y);
private:
    sf::RectangleShape top, brim;
    sf::CircleShape face;

};


#endif //CS3APORTFOLIO_TOPHATGUY_H
