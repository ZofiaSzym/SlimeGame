#include <iostream>
#include "SlimeYellow.h"
#include "SFML/Graphics/Texture.hpp"
#include "SFML/Graphics/Sprite.hpp"
#include "SlimeYellow.h"

SlimeYAnimation::SlimeYAnimation(int x, int y, int width, int height) {
    texture.loadFromFile("media/SLIME/slime_gold_front.png");

    for (int i = 0; i < nFrames; i++) {
        frames[i] = {x + (i *width),y,width,height};
    }

}

SlimeYAnimation::SlimeYAnimation() {
    textureAttack.loadFromFile("media/SLIME/slime_hurt.png");
    for (int i = 0; i < nFrames; i++) {
        frames[i] = {0, 0 ,12,8};
    }
}

//konstruktor
SlimeYellow::SlimeYellow() {
    this->health = 30;
    this->damage = 10;
    this->speed = 2;
    Sprite.setTextureRect({0,0,12,14});
    Sprite.setScale(3,3);
    this->AniAttack = SlimeYAnimation();
    this->Ani = SlimeYAnimation(0,0,12,14);
    pos = { (float)(rand()%(1350-400)+400), 300};
    Sprite.setPosition(pos);
}

//update
auto SlimeYellow::Update(float dt,  sf::Vector2f MCpos) -> void{
    if (MCpos.x - pos.x > 0) {
        pos.x = pos.x+0.03f *speed;
    } else if (MCpos.x - pos.x < 0) {
        pos.x = pos.x-0.03f *speed;
    }

    if (MCpos.y - pos.y > 0) {
        pos.y = pos.y+0.03f*speed;
    } else if (MCpos.y - pos.y < 0) {
        pos.y = pos.y-0.03f *speed;
    }
    Ani.Update(dt);
    Ani.Apply(Sprite);
    Sprite.setPosition(pos);
}

void SlimeYellow::UpdateAttack(float dt) {
    AniAttack.Update(dt);
    AniAttack.ApplyAttack(Sprite);
    Sprite.setPosition(pos);
}

void SlimeYellow::Die() {
    delete this;
}

