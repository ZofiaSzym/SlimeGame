#include <iostream>
#include "SlimePink.h"
#include "SFML/Graphics/Texture.hpp"
#include "SFML/Graphics/Sprite.hpp"

//animacja
SlimePAnimation::SlimePAnimation(int x, int y, int width, int height) {
    texture.loadFromFile("media/SLIME/slime_pink_front.png");

    for (int i = 0; i < nFrames; i++) {
        frames[i] = {x + (i *width),y,width,height};
    }

}
//animacja atak
SlimePAnimation::SlimePAnimation() {
    textureAttack.loadFromFile("media/SLIME/slime_hurt.png");
    for (int i = 0; i < nFrames; i++) {
        frames[i] = {0, 0 ,12,8};
    }
}

//konstruktor
SlimePink::SlimePink() {
    this->health = 15;
    this->damage = 3;
    this->speed = 1;
    Sprite.setTextureRect({0,0,12,14});
    Sprite.setScale(2,2);
    this->AniAttack = SlimePAnimation();
    this->Ani = SlimePAnimation(0,0,12,14);
    pos = { (float)(rand()%(1350-400)+400), 300};
    Sprite.setPosition(pos);
}

//update
 auto SlimePink::Update(float dt, sf::Vector2f MCpos) -> void{
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
void SlimePink::UpdateAttack(float dt) {
    AniAttack.Update(dt);
    AniAttack.ApplyAttack(Sprite);
    Sprite.setPosition(pos);
}

void SlimePink::Die() {
    delete this;
}
