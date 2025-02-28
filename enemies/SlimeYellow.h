#pragma once
#include "Enemy.h"

class SlimeYAnimation : public EnemyAnimation {
public:
    SlimeYAnimation(int x, int y, int width, int height);
    SlimeYAnimation();
};

class SlimeYellow :public Enemy {

public:
    SlimeYellow();

    //animacja
    SlimeYAnimation Ani;
    SlimeYAnimation AniAttack;

    void UpdateAttack(float dt) override;
    void Update(float dt,  sf::Vector2f MCpos) override;


    void Die() override;
};

