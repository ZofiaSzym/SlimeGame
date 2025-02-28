#pragma once
#include "Enemy.h"

class SlimePAnimation : public EnemyAnimation {
public:
    SlimePAnimation(int x, int y, int width, int height);
    SlimePAnimation();
};

class SlimePink : public Enemy {

public:
    SlimePink();

    //animacja
    SlimePAnimation Ani;
    SlimePAnimation AniAttack;

    void UpdateAttack(float dt) override;
    void Update(float dt,  sf::Vector2f MCpos) override;

    void Die() override;
};

