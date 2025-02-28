#pragma once
#include "SFML/Graphics.hpp"

class Menu
{
public:
    void Load(int width, int height);
    void draw(sf::RenderWindow* window);
    void MoveUp();
    void MoveDown();
    int GetPressedItem();

private:
    int selectedItemIndex;
    sf::Font font;
    sf::Text menu[3];

};