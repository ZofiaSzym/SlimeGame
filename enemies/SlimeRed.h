#pragma once
#include "Enemy.h"

class SlimeRAnimation : public EnemyAnimation {
public:
    SlimeRAnimation(int x, int y, int width, int height);
    SlimeRAnimation();
};

class SlimeRed :public Enemy {

public:
    SlimeRed();

    //animacja
    SlimeRAnimation Ani;
    SlimeRAnimation AniAttack;

    void UpdateAttack(float dt) override;
    void Update(float dt,  sf::Vector2f MCpos) override;

    void Die() override;
};

