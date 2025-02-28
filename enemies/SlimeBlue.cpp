#include <iostream>
#include "SFML/Graphics/Texture.hpp"
#include "SFML/Graphics/Sprite.hpp"
#include "SlimeBlue.h"

//animacja
SlimeBAnimation::SlimeBAnimation(int x, int y, int width, int height) {
    texture.loadFromFile("media/SLIME/slime_blue_front.png");

    for (int i = 0; i < nFrames; i++) {
        frames[i] = {x + (i *width),y,width,height};
    }

}

//animacja atak
SlimeBAnimation::SlimeBAnimation() {
    textureAttack.loadFromFile("media/SLIME/slime_hurt.png");
    for (int i = 0; i < nFrames; i++) {
        frames[i] = {0, 0 ,12,8};
    }
}

//konstruktor
SlimeBlue::SlimeBlue() {
    this->health = 200;
    this->damage = 50;
    this->speed = 1;
    Sprite.setTextureRect({0,0,12,14});
    Sprite.setScale(4,4);
    this->AniAttack = SlimeBAnimation();
    this->Ani = SlimeBAnimation(0,0,12,14);
    pos = { (float)(rand()%(1350-400)+400), 300};
    Sprite.setPosition(pos);
}

//update
auto SlimeBlue::Update(float dt,  sf::Vector2f MCpos) -> void{
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

auto SlimeBlue::UpdateAttack(float dt)->void {
    AniAttack.Update(dt);
    AniAttack.ApplyAttack(Sprite);
    Sprite.setPosition(pos);
}

auto SlimeBlue::Die()->void {
    delete this;

}




