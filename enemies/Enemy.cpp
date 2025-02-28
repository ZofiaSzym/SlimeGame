
#include <iostream>
#include "Enemy.h"

//animacja
EnemyAnimation::EnemyAnimation() {
}

void EnemyAnimation::Apply(sf::Sprite &Sprite) {
    Sprite.setTexture(texture);
    Sprite.setTextureRect(frames[iFrame]);

}
void EnemyAnimation::ApplyAttack(sf::Sprite &s) {
    s.setTexture(textureAttack);
    s.setTextureRect(frames[iFrame]);
}



void EnemyAnimation::Update(float dt) {
    time = time + dt;
    while (time >= holdTime) {
        time = time -holdTime;
        Advance();
    }
}

void EnemyAnimation::Advance() {
    if ( ++iFrame >= nFrames) {
        iFrame = 0;
    }
}


//wrog
Enemy::Enemy() {}

void Enemy::Draw(sf::RenderWindow* window) const {
    window->draw(Sprite);

}

//wirtualne - sa w oddzielnych slime'ach
void Enemy::Update(float dt,  sf::Vector2f MCpos) {}
auto Enemy::Die() -> void {}
void Enemy::UpdateAttack(float dt) {}

//gettery
int Enemy::getHealth() const {
    return health;
}

const sf::Vector2f &Enemy::getPos() const {
    return pos;
}
int Enemy::getDamage() {
    return damage;
}


//settery
void Enemy::hurt(int i) {
    this->health = this->health - i;
}

void Enemy::setHealth(int health) {
    Enemy::health = health;
}


