#include <iostream>
#include "SlimeGreen.h"
#include "SFML/Graphics/Texture.hpp"
#include "SFML/Graphics/Sprite.hpp"

//animacja
SlimeGAnimation::SlimeGAnimation(int x, int y, int width, int height) {
    texture.loadFromFile("media/SLIME/slime_green_front.png");

    for (int i = 0; i < nFrames; i++) {
        frames[i] = {x + (i *width),y,width,height};
    }
}

//animacja atak
SlimeGAnimation::SlimeGAnimation() {
    textureAttack.loadFromFile("media/SLIME/slime_hurt.png");
    for (int i = 0; i < nFrames; i++) {
        frames[i] = {0, 0 ,12,8};
    }
}

//konstruktor
SlimeGreen::SlimeGreen() {
    this->health = 60;
    this->damage = 20;
    this->speed = 4;
    Sprite.setTextureRect({0,0,12,14});
    Sprite.setScale(4,4);
    this->AniAttack = SlimeGAnimation();
    this->Ani = SlimeGAnimation(0,0,12,14);
    pos = { (float)(rand()%(1350-400)+400), 300};
    Sprite.setPosition(pos);
}

//update
auto SlimeGreen::Update(float dt,  sf::Vector2f MCpos) -> void{
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

void SlimeGreen::UpdateAttack(float dt) {
    AniAttack.Update(dt);
    AniAttack.ApplyAttack(Sprite);
    Sprite.setPosition(pos);
}


void SlimeGreen::Die() {
    delete this;

}


