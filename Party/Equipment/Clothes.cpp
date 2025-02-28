#include <cstdlib>
#include <iostream>
#include "Clothes.h"

void Clothes::init() {
    int luck = (rand() %3);

    switch (luck) {
        case 0:
            this->texture.loadFromFile(
                    "media/clothes/ubranie zwykle.png");
            this->sprite.setTexture(this->texture);
            this->sprite.setPosition(960, 540);
            this->health = 200;
            break;
        case 1:
            this->texture.loadFromFile(
                    "media/clothes/ubranie zlote.png");
            this->sprite.setTexture(this->texture);
            this->sprite.setPosition(960, 540);
            this->health = 500;
            break;

        default:
            this->texture.loadFromFile(
                    "media/clothes/ubranie diamentowe.png");
            this->sprite.setTexture(this->texture);
            this-> sprite.setPosition(960, 540);
            this->health = 1000;
            break;
    }
}

void Clothes::Draw(sf::RenderWindow *window) const {
window->draw(this->sprite);
}
