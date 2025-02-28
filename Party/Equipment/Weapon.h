
#include "SFML/Graphics/Texture.hpp"
#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/RenderWindow.hpp"

class Weapon {

public :

    //funckje
    void init();
    void Draw(sf::RenderWindow *window) const;

    //co nam daje
    int damage;

    //wyglad
    sf::Texture texture;
    sf::Sprite sprite;

};
