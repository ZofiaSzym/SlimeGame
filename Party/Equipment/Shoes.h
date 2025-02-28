#include "SFML/Graphics/Texture.hpp"
#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/RenderWindow.hpp"

class Shoes {


public:
    //funkcje
    void init();
    void Draw(sf::RenderWindow* window) const;

    //co nam daje
    int speed;

    //wyglad
    sf::Texture texture;
    sf::Sprite sprite;

};
