#pragma once
#include "Enemy.h"

class SlimeBAnimation : public EnemyAnimation {
public:
    SlimeBAnimation(int x, int y, int width, int height);
    SlimeBAnimation();
};

class SlimeBlue :public Enemy {

public:
    SlimeBlue();

    //animacja
    SlimeBAnimation Ani;
    SlimeBAnimation AniAttack;

    void UpdateAttack(float dt) override;
    void Update(float dt,  sf::Vector2f MCpos) override;

    void Die() override;
};

