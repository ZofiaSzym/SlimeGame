#include <iostream>
#include "Shoes.h"

void Shoes::init() {
    int luck = (rand() %3);

    switch (luck) {

        case 0:
            this->texture.loadFromFile(
                    "media/shoes/plain shoes.png");
            this->sprite.setTexture(this->texture);
            this->sprite.setPosition(900, 500);
            this->speed = 200;
            break;
        case 1:
            this->texture.loadFromFile(
                    "media/shoes/gold shoes.png");
            this->sprite.setTexture(this->texture);
            this-> sprite.setPosition(900, 500);
            this->speed = 300;
            break;

        default:
            this->texture.loadFromFile(
                    "media/shoes/diamond shoes.png");
            this->sprite.setTexture(this->texture);
            this->sprite.setPosition(900, 500);
            this->speed = 500;
            break;
    }
}

void Shoes::Draw(sf::RenderWindow *window) const {
    window->draw(this->sprite);
}
