#pragma once

#include <string>
#include "SFML/Graphics/Texture.hpp"
#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Window/Keyboard.hpp"
#include "SFML/Graphics/RenderWindow.hpp"
#include "../enemies/Enemy.h"

//animacja
class McAnimation {
private:
    static constexpr int nFrames = 4;
    static constexpr float holdTime = 0.1f;
    sf::Texture MCtexture;
    sf::IntRect frames[nFrames];
    int iFrame =0;
    float time = 0.0f;

public :
    McAnimation();
    McAnimation(int x, int y, int width, int height);
    void Apply (sf::Sprite& s);
    void Update(float dt);
    void Advance();
};



class MC {
protected:
    int health = 100;
    int attack = 10;
    float speed = 100.0f;
    int x = 0;
    int y = 1;

    //do wywolywania kierunku
    enum MCwalk {
        right,
        left,
        up,
        down,
        rightA,
        leftA,
        upA,
        downA,
        def
    };

    //poczatek
    MCwalk current = MCwalk::down;
    McAnimation Ani[int(MCwalk::def)] ;

    //pozycja
    sf::Vector2f pos;
    sf::Vector2f vel = {0.0f, 0.0f};

    //pozycje koncowe planszy
    int Leftx = 400;
    int Rightx = 1350;
    int topY=250;
    int bottomY =730;


public:
    sf::Sprite MCsprite;
    //gettery
    int getAttack() const;
    int getHealth() const;
    float getSpeed() const;
    const sf::Vector2f &getPos() const;

    //konstruktor
    MC( const sf::Vector2f & pos );

    //poruszanie sie, animacja
    void Update(float dt, sf::Vector2f& dir);
     void Draw(sf::RenderWindow* window) const;
    void SetDirection ( const sf::Vector2f& dir, bool att);

    //walka
    void Attack(float dt, Enemy *enemy);
    void Attacked(float dt, Enemy *enemy);
    bool death();

    //settery
    void setHealth(int health);
    void setAttack(int attack);
    void setSpeed(float speed);
    void setPos(float x, float y);
};


