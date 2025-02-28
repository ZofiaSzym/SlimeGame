#pragma once

#include "SFML/System/Vector2.hpp"
#include "SFML/Graphics/Texture.hpp"
#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/RenderWindow.hpp"

class Map {
protected:
    sf::Texture tileTex;
    sf::Sprite sprite[9];
    sf::Sprite water;

public:
    void Load();
    void Draw(sf::RenderWindow* window);
};

