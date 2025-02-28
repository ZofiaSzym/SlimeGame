#include "Map.h"


void Map::Load() {
    tileTex.loadFromFile("media/Map/tiles.png");
    for (int i = 0; i < 9; i++) {
    sprite[i].setTexture(tileTex);
    sprite[i].setScale(2,2);
}
    sprite[0].setTextureRect({0,0,50,50});
    sprite[1].setTextureRect({23,0,50,50});
    sprite[2].setTextureRect({50,0,50,50});

    sprite[3].setTextureRect({0,19,50,50});
    sprite[4].setTextureRect({23,19,50,50});
    sprite[5].setTextureRect({50,19,50,50});

    sprite[6].setTextureRect({0,40,50,50});
    sprite[7].setTextureRect({23,40,50,50});
    sprite[8].setTextureRect({50,40,50,50});



   water.setTexture(tileTex);
    water.setTextureRect({0,0,10,10});
    water.setScale(2000,2000);
}

void Map::Draw(sf::RenderWindow* window) {
    window->draw(water);

    int x = 400;
    int y = 300;

    for (int i = 0 ; i < 20; i ++) {
        for (int j = 0; j < 10; j++) {
            if ( i == 0 && j ==0 ) {
                sprite[0].setPosition(x, y);
                window->draw(sprite[0]);
            }else if ( i != 0 && j == 0 && i != 19) {
                sprite[1].setPosition(x+(i*50), y);
                window->draw(sprite[1]);
            } else if ( j == 0 && i == 19) {
                sprite[2].setPosition(x+(i*50), y);
                window->draw(sprite[2]);
            } else if ( i == 0 && j != 0 && j !=9 ) {
                sprite[3].setPosition(x, y+(j*50));
                window->draw(sprite[3]);
            } else if ( i != 0 && i != 19 && j != 0 && j !=9 ) {
                sprite[4].setPosition(x+(i*50), y+(j*50));
                window->draw(sprite[4]);
            }
            else if ( i == 19 && j != 0 && j !=9 ) {
                sprite[5].setPosition(x+(i*50), y+(j*50));
                window->draw(sprite[5]);
            }
            else if ( i == 0 && j ==9 ) {
                sprite[6].setPosition(x, y+(j*50));
                window->draw(sprite[6]);
            }
            else if  ( i != 0 && j == 9 && i != 19) {
                sprite[7].setPosition(x+(i*50), y+(j*50));
                window->draw(sprite[7]);
            }  else  {
                sprite[8].setPosition(x+(i*50), y+(j*50));
                window->draw(sprite[8]);
            }
        }
    }

        }

