#include "Menu.h"

//https://www.youtube.com/watch?v=bOG8667yePY&t=272s - menu

//budowa menu
void Menu::Load(int width, int height) {
    font.loadFromFile("media/AmaticSC-Regular.ttf");

    menu[0].setFont(font);
    menu[0].setColor(sf::Color::Green);
    menu[0].setString("Start");
    menu[0].setCharacterSize(50);
    menu[0].setPosition(sf::Vector2f(width / 2, height / 5));

    menu[1].setFont(font);
    menu[1].setColor(sf::Color::White);
    menu[1].setString("Load");
    menu[1].setCharacterSize(50);
    menu[1].setPosition(sf::Vector2f(width / 2, height / 5 * 2));

    menu[2].setFont(font);
    menu[2].setColor(sf::Color::White);
    menu[2].setString("Exit");
    menu[2].setCharacterSize(50);
    menu[2].setPosition(sf::Vector2f(width / 2, height / 5 * 3));

    selectedItemIndex = 0;
}

void Menu::draw(sf::RenderWindow* window)
{
    for (int i = 0; i < 3; i++)
    {
        window->draw(menu[i]);
    }
}

//wybieranie
void Menu::MoveUp()
{
    if (selectedItemIndex - 1 >= 0)
    {
        menu[selectedItemIndex].setColor(sf::Color::White);
        selectedItemIndex--;
        menu[selectedItemIndex].setColor(sf::Color::Red);
    }
}

void Menu::MoveDown()
{
    if (selectedItemIndex + 1 < 4)
    {
        menu[selectedItemIndex].setColor(sf::Color::White);
        selectedItemIndex++;
        menu[selectedItemIndex].setColor(sf::Color::Red);
    }
}

//decyzja
int Menu::GetPressedItem() {
    return selectedItemIndex;
}
