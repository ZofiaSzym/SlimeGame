#include "GameOver.h"



void GameOver::Load(int width, int height) {
    font.loadFromFile("media/AmaticSC-Regular.ttf");

    over[0].setFont(font);
    over[0].setColor(sf::Color::White);
    over[0].setString("GAMEOVER");
    over[0].setCharacterSize(200);
    over[0].setPosition(sf::Vector2f(width / 4, height / 5));

    over[1].setFont(font);
    over[1].setColor(sf::Color::White);
    over[1].setString("take a break & try again later");
    over[1].setCharacterSize(50);
    over[1].setPosition(sf::Vector2f(width / 4, 3* height / 5));
}

void GameOver::draw(sf::RenderWindow* window)
{
    for (int i = 0; i < 2; i++)
    {
        window->draw(over[i]);
    }
}

void GameOver::close() {
    this->close();
}
