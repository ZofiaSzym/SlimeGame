#pragma once
#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/Texture.hpp"
#include "SFML/Graphics/RenderWindow.hpp"

//animacja
class EnemyAnimation {
private:
    static constexpr float holdTime = 0.1f;
    int iFrame =0;
    float time = 0.0f;


protected:
    //tekstury
    sf::Texture texture;
    sf::Texture textureAttack;
    //animacja
    static constexpr int nFrames = 15;
    sf::IntRect frames[16];


public :
    EnemyAnimation();
    void Apply (sf::Sprite& s);
    void ApplyAttack (sf::Sprite& s);
    void Advance();
    void Update(float dt);

};

//wrog
class Enemy {


 protected:
     int health;
     int damage;
     int speed;
    sf::Vector2f pos;


public:
    sf::Sprite Sprite;

    //konstruktor i kinda destruktor (die)
     Enemy();
    virtual void Die();

    virtual void Update(float dt, sf::Vector2f MCpos);
    virtual void UpdateAttack(float dt);

    virtual void Draw(sf::RenderWindow* window) const;

    //gettery
    const sf::Vector2f &getPos() const;
    int getHealth() const;
    int getDamage();

    //settery
    void hurt(int i);
    virtual void setHealth(int health);





};

