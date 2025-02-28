#pragma once

#include "SFML/Graphics.hpp"
class GameOver {
public:

    void Load(int width, int height);
    void draw(sf::RenderWindow* window);
    void close();

private:
    sf::Font font;
    sf::Text over[2];

};

