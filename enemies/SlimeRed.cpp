#include <iostream>
#include "SlimeRed.h"
#include "SFML/Graphics/Texture.hpp"
#include "SFML/Graphics/Sprite.hpp"

//animacja
SlimeRAnimation::SlimeRAnimation(int x, int y, int width, int height) {
    texture.loadFromFile("media/SLIME/slime_red_front.png");

    for (int i = 0; i < nFrames; i++) {
        frames[i] = {x + (i *width),y,width,height};
    }

}

//animacja atak
SlimeRAnimation::SlimeRAnimation() {
    textureAttack.loadFromFile("media/SLIME/slime_hurt.png");
    for (int i = 0; i < nFrames; i++) {
        frames[i] = {0, 0 ,12,8};
    }
}

//konstruktor
SlimeRed::SlimeRed() {
    this->health = 1000;
    this->damage = 100;
    this->speed = 5;
    Sprite.setTextureRect({0,0,12,14});
    Sprite.setScale(5,5);
    this->AniAttack = SlimeRAnimation();
    this->Ani = SlimeRAnimation(0,0,12,14);
    pos = { (float)(rand()%(1350-400)+400), 300};
    Sprite.setPosition(pos);
}


//update
auto SlimeRed::Update(float dt,  sf::Vector2f MCpos) -> void{
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

void SlimeRed::UpdateAttack(float dt) {
    AniAttack.Update(dt);
    AniAttack.ApplyAttack(Sprite);
    Sprite.setPosition(pos);
}

void SlimeRed::Die() {
    delete this;
}
