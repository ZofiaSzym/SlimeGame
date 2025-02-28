#include <iostream>
#include "MC.h"
#include "SFML/Graphics/Texture.hpp"
#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Window/Keyboard.hpp"
#include "SFML/Graphics/RenderWindow.hpp"
#include "../enemies/Enemy.h"

//animacja
McAnimation::McAnimation() {}

//budowanie animacji
McAnimation::McAnimation(int x, int y, int width, int height) {
    MCtexture.loadFromFile("media/McAll.png");
    if ( y < 193) {
        for (int i = 0; i < nFrames; i++) {
            frames[i] = {x + (i * width), y, width, height};
        }
    } else {
        int i = 0;
        while ( i < 4 ){
            frames[i] = {x, y, width, height};
            i++;
            frames[i] = {x + width, y, width, height};
            i++;
        }
    }

}


void McAnimation::Apply(sf::Sprite &sprite) {
    sprite.setTexture(MCtexture);
    sprite.setTextureRect(frames[iFrame]);
}

//przejscie animacji
void McAnimation::Update(float dt) {
    time = time + dt;
    while (time >= holdTime) {
        time = time -holdTime;
        Advance();
    }
}

void McAnimation::Advance() {
    if ( ++iFrame >= nFrames) {
        iFrame = 0;
    }
}


//postac, animacja
MC::MC(const sf::Vector2f& pos)  : pos(pos) {
MCsprite.setTextureRect({0,0,64,64});
    MCsprite.scale(2,2);
    Ani[int(MCwalk::up)] = McAnimation(0,0,64,64);
    Ani[int(MCwalk::down)] = McAnimation(0,64,64,64);
    Ani[int(MCwalk::right)] = McAnimation(0,192,64,64);
    Ani[int(MCwalk::left)] = McAnimation(0,128,64,64);
    Ani[int(MCwalk::upA)] = McAnimation(0,256,64,64);
    Ani[int(MCwalk::downA)] = McAnimation(0,320,64,64);
    Ani[int(MCwalk::rightA)] = McAnimation(0,448,64,64);
    Ani[int(MCwalk::leftA)] = McAnimation(0,384,64,64);
}

void MC::Draw(sf::RenderWindow* window) const {
    window->draw(MCsprite);
}

//poruszanie sie
void MC::SetDirection(const sf::Vector2f& dir, bool att) {
vel = dir*speed;

if (dir.x >0 ) {
    current = MCwalk::right;
} else if ( dir.x < 0 ) {
    current = MCwalk::left;
}else if ( dir.y < 0 ) {
current = MCwalk::up;
} else if ( dir.y > 0 ) {
current = MCwalk::down;
}

if (att) {
    if (current == MCwalk::right || current == MCwalk::rightA) {
        current = MCwalk::rightA;
    }
    if (current == MCwalk::left || current == MCwalk::leftA) {
        current = MCwalk::leftA;
    }
    if (current == MCwalk::up || current == MCwalk::upA) {
        current = MCwalk::upA;
    }
    if (current == MCwalk::down || current == MCwalk::downA) {
        current = MCwalk::downA;
    }
}
}

void MC::Update(float dt, sf::Vector2f& dir) {
    if ((dir.x == 1.0f && Rightx > pos.x) || (dir.x == -1.0f && Leftx < pos.x ) || (dir.y == 1.0f && bottomY > pos.y) || (dir.y == -1.0f && topY < pos.y)) {
        pos = pos + (vel * dt);
        Ani[int(current)].Update(dt);
    }
    Ani[int(current)].Apply(MCsprite);

    MCsprite.setPosition(pos);
}


//gettery i gettero-podobne
const sf::Vector2f &MC::getPos() const {
    return pos;
}

int MC::getHealth() const {
    return health;
}

int MC::getAttack() const {
    return attack;
}

float MC::getSpeed() const {
    return speed;
}

bool MC::death() {
    return this->health <= 0;
}

//atakowanie i obrywanie
void MC::Attack(float dt, Enemy* enemy) {
    if(enemy!= nullptr){

    if ((current == MCwalk::right || current == MCwalk::rightA) &&
        (enemy->getPos().x <= pos.x + 74.f && enemy->getPos().x > pos.x
         && enemy->getPos().y < pos.y + 74.f && enemy->getPos().y > pos.y - 10.f)) {

        enemy->hurt(this->attack);
    }

    if ((current == MCwalk::left || current == MCwalk::leftA) &&
        (enemy->getPos().x > pos.x - 10.f && enemy->getPos().x <= pos.x
         && enemy->getPos().y < pos.y + 74.f && enemy->getPos().y > pos.y - 10.f)) {

        enemy->hurt(this->attack);

    }
    if ((current == MCwalk::up || current == MCwalk::upA) &&
        (enemy->getPos().x < pos.x + 74.f && enemy->getPos().x > pos.x - 10.f
         && enemy->getPos().y > pos.y - 10.f && enemy->getPos().y < pos.y)) {

        enemy->hurt(this->attack);

    }
    if ((current == MCwalk::down || current == MCwalk::downA) &&
        (enemy->getPos().x < pos.x + 74.f && enemy->getPos().x > pos.x - 10.f
         && enemy->getPos().y < pos.y + 74.f && enemy->getPos().y > pos.y)) {

        enemy->hurt(this->attack);

    }
}
}
void MC::Attacked(float dt, Enemy *enemy) {

    if (rand() % 101 > 99 ) {
        enemy->UpdateAttack(dt);
        this->health -= enemy->getDamage();
    }
}

//settery
void MC::setHealth(int health) {
    MC::health = health;
}

void MC::setAttack(int attack) {
    MC::attack = attack;
}

void MC::setSpeed(float speed) {
    MC::speed = speed;
}

void MC::setPos(float x, float y) {
    MC::pos.x = x;
    MC::pos.y = y;
}


