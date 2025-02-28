
#include <iostream>
#include "Weapon.h"
#include "SFML/Graphics/RenderWindow.hpp"

void Weapon::init() {
    int luck = rand() %3;

    switch (luck) {
        case 0:
            this->texture.loadFromFile(
                    "media/kosy/boring kosa.png");
            this->sprite.setTexture(this->texture);
            this->sprite.setPosition(900, 500);
            this->damage = 50;
            break;
        case 1:
            this->texture.loadFromFile(
                    "media/kosy/zlota kosa.png");
            this->sprite.setTexture(this->texture);
            this->sprite.setPosition(900, 500);
            this->damage = 100;
            break;

        default:
            this->texture.loadFromFile(
                    "media/kosy/diamentowa kosa.png");
            this->sprite.setTexture(this->texture);
            this->sprite.setPosition(900, 500);
            this->damage = 250;
            break;
    }


}


void Weapon::Draw(sf::RenderWindow* window) const {
    window->draw(this->sprite);
}
