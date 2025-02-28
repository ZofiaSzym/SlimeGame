#include "Game.h"
#include "Map.h"
#include "../Party/MC.h"
#include "Menu.h"
#include "GameOver.h"
#include "../enemies/SlimeYellow.h"
#include "../enemies/SlimeBlue.h"
#include "../enemies/SlimeGreen.h"
#include "../enemies/SlimeRed.h"

//konstruktor, destruktor, budowa + open
Game::Game() {
    this->tp = std::chrono::steady_clock::now();
    windowCreate();

}

Game::~Game() {
delete this->window;
}

void Game::windowCreate() {

    this-> window = new sf::RenderWindow(sf::VideoMode(1920, 1080), "Slime Mania", sf::Style::Default);
    sf::Image icon;
    icon.loadFromFile("media/icon.png");
    this->window->setIcon(100,100, icon.getPixelsPtr());
    this->menu.Load(1920,1080);


}

void Game::windowCreateLevel() {

    this-> NewLvl = true;
    this-> window = new sf::RenderWindow(sf::VideoMode(1920, 1080), "Slime Mania", sf::Style::Default);
    sf::Image icon;
    icon.loadFromFile("media/icon.png");
    this->window->setIcon(100,100, icon.getPixelsPtr());

    Map map;
    this->map.Load();
    this->SpawnEnemies();
    this->save.open("media/save", std::ios::trunc | std::ios::out);
    this->saving();
    this->save.close();
    this->windowGetItem();
    this->update();
    this->draw();

}

const bool Game::Open() const {
    return this->window->isOpen();
}

//faktyczna gra
void Game::update() {
    //event loop
    while (this->window->pollEvent(event)) {
        if (this->event.type == sf::Event::Closed || this->event.key.code == sf::Keyboard::Escape) {
            this->window->close();
        }

    }
    //time checker
    float dt;
    auto nowtp = std::chrono::steady_clock::now();
    dt = std::chrono::duration<float>(nowtp - this->tp).count();
    this->tp = nowtp;

    bool att = false;

    sf::Vector2f dir = {0.0f,0.0f};

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        dir.x += 1.0f;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        dir.x -= 1.0f;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        dir.y -= 1.0f;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        dir.y += 1.0f;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
       att = true;

    }
  if ( Enemies.empty()  ) {
       windowUpdateItem();
   }

   if ( Enemies.empty() && (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) || sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace))) {
       lvl++;
       this->windowCreateLevel();
   }

    this->Mc.SetDirection(dir, att);
    this->Mc.Update( dt, dir );
    this->UpdateEnemies(dt, att);


}

void Game::draw() {

    if (Mc.death()) {
        this->gameOver.Load(1920, 1080);
        this->updateOver();
        this->drawOver();
    } else {
        this->window->clear(sf::Color::Magenta);
        this->map.Draw(window);
        this->Mc.Draw(window);

        if (Enemies.empty() && lvl >= 10) {
            this->end();
        } else if ( Enemies.empty()  ) {
            windowDrawItem();
        }
        this->DrawEnemies();

        this->window->display();
    }
}

void Game::end() {
    sf::Font font;
    font.loadFromFile("media/AmaticSC-Regular.ttf");
    sf::Text textcheese;
    textcheese.setString("Enjoy winner's cheese");
    textcheese.setColor(sf::Color::Yellow);
    textcheese.setFont(font);
    textcheese.setCharacterSize(100);
    textcheese.setPosition(sf::Vector2f( 500, 40));
    this->window->draw(textcheese);
    sf::Text text;
    text.setString("You won! Yuppie!");
    text.setColor(sf::Color::Green);
    text.setFont(font);
    text.setCharacterSize(200);
    text.setPosition(sf::Vector2f( 500, 100));
    this->window->draw(text);
    sf::Sprite cheeseS;
    sf::Texture cheeseT;
    cheeseT.loadFromFile("media/winnerCheese.png");
    cheeseS.setTexture(cheeseT);
    cheeseS.setPosition(900, 500);
    cheeseS.setScale(0.1,0.1);
    this->window->draw(cheeseS);
}

//menu
void Game::updateMenu() {

    //event loop
    while (this->window->pollEvent(event)) {
        if (this->event.type == sf::Event::Closed || this->event.key.code == sf::Keyboard::Escape) {
            this->window->close();
        }
        if(this->event.type == sf::Event::KeyReleased) {
            if(event.key.code == sf::Keyboard::Up) {
                menu.MoveUp();
            } else if (event.key.code == sf::Keyboard::Down) {
                menu.MoveDown();
            } else if(event.key.code == sf::Keyboard::Return) {

                int x = menu.GetPressedItem();
                if ( x == 0) {
                    Game game;
                    game.windowCreateLevel();
                    while (game.Open()) {
                        game.update();
                        game.draw();
                    }
                    window->close();
                } else if ( x == 1) {
                    Game game;
                    game.save.open("media/save", std::ios::in);
                    game.reading();
                    game.windowCreateLevel();
                    while (game.Open()) {
                        game.update();
                        game.draw();
                    }
                    window->close();
                 }else if ( x == 2 ) {
                window-> close();
                }
            }
        }
    }
}

void Game::drawMenu() {

    this-> window->clear(sf::Color::Magenta);
    this->menu.draw(window);
    this->window->display();
}

//game over okno
void Game::updateOver() {

    //event loop
    while (this->window->pollEvent(event)) {
        if (this->event.type == sf::Event::Closed || this->event.key.code == sf::Keyboard::Escape) {
            this->window->close();
        }
    }
}

void Game::drawOver() {

    this-> window->clear(sf::Color::Black);
    this->gameOver.draw(window);
    this->window->display();
}

//itemy
void Game::windowGetItem() {
        this->choice = (rand() % 3);

        switch (choice) {
            case 0: {
                this->clothes.init();
                break;
            }
            case 1: {
                this->weapon.init();
                break;
            }
            case 2: {
                this->shoes.init();
                break;
            }
        }
}

void Game::windowDrawItem() {


    switch (choice) {
        case 0: {
            clothes.Draw(this->window);
            break;
        }
        case 1: {
            weapon.Draw(this->window);

            break;
        }
        case 2: {
            shoes.Draw(this->window);
            break;
        }
    }
}

void Game::windowUpdateItem() {

    switch (choice) {
        case 0: {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
                Mc.setHealth(clothes.health);
            }
            break;
        }
        case 1: {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
                Mc.setAttack(weapon.damage);
            }

            break;
        }
        case 2: {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
                Mc.setSpeed(shoes.speed);
            }
            break;
        }
    }
}

//wrogowie
void Game::SpawnEnemies() {
    if (lvl == 1) {
        for ( int i = 0; i < 3; i++) {
            this->Enemies.push_back(new SlimePink());
        }
    }

    if (lvl == 2) {
        for ( int i = 0; i < 5; i++) {
            this->Enemies.push_back(new SlimePink());
        }
    }

    if (lvl == 3) {
        int pink = (int)( rand() %5)+1;
        int yellow = (int) (rand() %2) +1;
        for ( int i = 0; i < pink; i++) {
            this->Enemies.push_back(new SlimePink());
        }
        for ( int i = 0; i < yellow; i++) {
            this->Enemies.push_back(new SlimeYellow());
        }
    }

    if (lvl == 4) {
        int pink = (int)( rand() %8)+1;
        int yellow = (int) (rand() %4)+1;
        this->Enemies.push_back(new SlimeBlue());
        for ( int i = 0; i < pink; i++) {
            this->Enemies.push_back(new SlimePink());
        }
        for ( int i = 0; i < yellow; i++) {
            this->Enemies.push_back(new SlimeYellow());
        }
    }

    if (lvl == 5) {
        int pink = (int)( rand() %5)+1;
        int yellow = (int) (rand() %2)+1;
        this->Enemies.push_back(new SlimeBlue());
        for ( int i = 0; i < pink; i++) {
            this->Enemies.push_back(new SlimePink());
        }
        for ( int i = 0; i < yellow; i++) {
            this->Enemies.push_back(new SlimeYellow());
        }
    }

    if (lvl == 6) {
        int blue = (int)( rand() %5)+1;
        for ( int i = 0; i < blue; i++) {
            this->Enemies.push_back(new SlimeBlue());
        }
    }

    if (lvl == 7) {
        int pink = (int) (rand() %4)+1;
        int blue = (int) (rand() %2)+1;

        this->Enemies.push_back(new SlimeGreen());

        for ( int i = 0; i < pink; i++) {
            this->Enemies.push_back(new SlimePink());
        }
        for ( int i = 0; i < blue; i++) {
            this->Enemies.push_back(new SlimeBlue());
        }
    }

    if (lvl == 8) {
        int pink = (int) (rand() %2)+1;
        int yellow = (int) (rand() %2)+1;

        this->Enemies.push_back(new SlimeGreen());
        this->Enemies.push_back(new SlimeBlue());

        for ( int i = 0; i < pink; i++) {
            this->Enemies.push_back(new SlimePink());
        }
        for ( int i = 0; i < yellow; i++) {
            this->Enemies.push_back(new SlimeYellow());
        }
    }

    if (lvl == 9 ) {
        this->Enemies.push_back(new SlimeRed());
    }

    if (lvl == 10) {
        this->Enemies.push_back(new SlimePink());
        this->Enemies.push_back(new SlimeYellow());
        this->Enemies.push_back(new SlimeBlue());
        this->Enemies.push_back(new SlimeGreen());
        this->Enemies.push_back(new SlimeRed());
    }




}

void Game::UpdateEnemies(float dt, bool att) {

    std::ranges::sort(Enemies,
                      [](auto l, auto r) { return l->getHealth() > r->getHealth(); });

    for (auto const ptr: Enemies) {
        if (ptr->getHealth() <= 0) {

            ptr->Die();
            Enemies.pop_back();

            Mc.setHealth(Mc.getHealth()+10);
            Mc.setAttack(Mc.getAttack()+10);
            Mc.setSpeed(Mc.getSpeed()+10);
        }
    }
    for (auto const ptr: Enemies) {
        if (att&&ptr!= nullptr) {
            Mc.Attack(dt, ptr);
        }


        auto x = Mc.getPos().x + 32;
        auto y = Mc.getPos().y + 32;

        if ((ptr->getPos().x <= x + 50.f && ptr->getPos().x > x
             && ptr->getPos().y < y + 50.f && ptr->getPos().y > y - 50.f
             && !sf::Keyboard::isKeyPressed(sf::Keyboard::RAlt))
            ||
            (ptr->getPos().x > x - 50.f && ptr->getPos().x <= x
             && ptr->getPos().y < y + 50.f && ptr->getPos().y > y - 50.f
             && !sf::Keyboard::isKeyPressed(sf::Keyboard::RAlt))
            ||
            (ptr->getPos().x < x + 50.f && ptr->getPos().x >x - 50.f
             && ptr->getPos().y > y - 50.f && ptr->getPos().y < y
             && !sf::Keyboard::isKeyPressed(sf::Keyboard::RAlt))
            ||
            (ptr->getPos().x < x + 50.f && ptr->getPos().x > x - 50.f
             && ptr->getPos().y < y + 50.f && ptr->getPos().y > y)
            && !sf::Keyboard::isKeyPressed(sf::Keyboard::RAlt)) {
            Mc.Attacked(dt, ptr);
        } else {
            ptr->Update(dt, Mc.getPos());
        }



    }
}

void Game::DrawEnemies() {
    for ( auto const ptr : Enemies) {
        ptr->Draw(window);

    }
}

//zapis
void Game::saving() {
    this->save << this->lvl << ' ';
    this->save << this->Mc.getHealth() << ' ';
    this->save << this->Mc.getAttack() << ' ';
    this->save << this->Mc.getSpeed() << ' ';
    this->save << this->Mc.getPos().x << ' ';
    this->save << this->Mc.getPos().y;
}

void Game::reading() {
    this->save >> this->lvl;
    auto x=0;
    auto y = 0.f;
    auto z = 0.f;
    this->save >> x;
    this->Mc.setHealth(x);
    this->save >> x;
    this->Mc.setAttack(x);
    this->save >> y;
    this->Mc.setSpeed(y);
    this->save>> y;
    this->save >> z;
    this->Mc.setPos(y, z);
}


