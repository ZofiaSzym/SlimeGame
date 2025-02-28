#pragma once
#include "Enemy.h"

class SlimeGAnimation : public EnemyAnimation {
public:
    SlimeGAnimation(int x, int y, int width, int height);
    SlimeGAnimation();
};

class SlimeGreen :public Enemy {

public:
    SlimeGreen();

    //animacja
    SlimeGAnimation Ani;
    SlimeGAnimation AniAttack;

    void Update(float dt,  sf::Vector2f MCpos) override;
    void UpdateAttack(float dt) override;

    void Die() override;
};

