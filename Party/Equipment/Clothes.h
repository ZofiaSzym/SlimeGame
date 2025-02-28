#include "SFML/Graphics/Texture.hpp"
#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/RenderWindow.hpp"

class Clothes {

public:
    //co nam daje
    int health;

    //wyglad
    sf::Texture texture;
    sf::Sprite sprite;

    //funckcje
    void init();
    void Draw(sf::RenderWindow *window) const;
};
