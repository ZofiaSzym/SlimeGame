#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <chrono>
#include <fstream>
#include "Map.h"
#include "../Party/MC.h"
#include "../enemies/SlimePink.h"
#include "Menu.h"
#include "GameOver.h"
#include "../Party/Equipment/Clothes.h"
#include "../Party/Equipment/Weapon.h"
#include "../Party/Equipment/Shoes.h"

class Game {

protected:
    // obiekty
    Clothes clothes;
    Weapon weapon;
    Shoes shoes;
    GameOver gameOver;
    MC Mc = MC({500.f,500.f});
    std::vector<Enemy*> Enemies;

    // do itemow
    int choice;

    //okno i mapy
    sf::RenderWindow* window;
    sf::Event event;
    Map map;
    Menu menu;

    //pomoce
    bool NewLvl = true;
    int lvl = 1;
    std::chrono::steady_clock::time_point tp;

public:
    //kostruktory/ desturktory / budowy
    Game();
    virtual ~Game();

    void windowCreate();
    void windowCreateLevel();

    const bool Open() const;

    // gra
    void update();
    void draw();
    void end();

    //menu
    void updateMenu();
    void drawMenu();

    //game over
    void updateOver();
    void drawOver();

    // itemy
    void windowGetItem();
    void windowDrawItem();
    void windowUpdateItem();

    //wrogowie
    void SpawnEnemies();
    void DrawEnemies();
    void UpdateEnemies(float dt, bool att);

    //zapis
    std::fstream save;
    void saving();
    void reading();
};
