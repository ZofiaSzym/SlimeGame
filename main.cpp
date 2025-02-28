#include <iostream>
#include <SFML/Graphics.hpp>
#include "Party/MC.h"
#include "enemies/SlimePink.h"
#include "GameSpace/Map.h"
#include "GameSpace/Game.h"
#include <chrono>
#include <filesystem>

class MC;

auto main() -> int {
    std::cout << "Current working directory: " << std::filesystem::current_path() << std::endl;
    //window
  Game game;

//game loop
while (game.Open()) {
    game.updateMenu();
    game.drawMenu();
    }

}

/*
wykorzystywane media :
https://www.youtube.com/watch?v=BySDfVNljG8&list=PL6xSOsbVA1eb_QqMTTcql_3PdOiE928up - seria filmikow
https://www.youtube.com/watch?v=esGMreLmed0&list=PLs6oRBoE2-Q_fX_rzraQekRoL7Kr7s5xi - seria filmikow
 https://www.youtube.com/watch?v=eAqp1aJsKEQ&list=PLS9MbmO_ssyCSyqZC2NEfblIa9_xSrMqR - seria filmikow (podstawy sfml)
https://www.youtube.com/watch?v=bOG8667yePY&t=272s - menu
https://en.sfml-dev.org/forums/ - forum sfml*/
