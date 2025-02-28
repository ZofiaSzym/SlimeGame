cmake_minimum_required(VERSION 3.27)
project(ProjectGame)

set(CMAKE_CXX_STANDARD 20)
set(BUILD_SHARED_LIBS FALSE)

include(FetchContent)

FetchContent_Declare(
        fmt
        GIT_REPOSITORY  https://github.com/fmtlib/fmt
        GIT_TAG         10.2.1
)

FetchContent_Declare(
        SFML
        GIT_REPOSITORY  https://github.com/SFML/SFML
        GIT_TAG         2.6.1
)

FetchContent_MakeAvailable(fmt)
FetchContent_MakeAvailable(SFML)

add_executable(Main main.cpp
        enemies/SlimePink.cpp
        enemies/SlimePink.h
        enemies/Enemy.cpp
        enemies/Enemy.h
        enemies/SlimeGreen.cpp
        enemies/SlimeGreen.h
        enemies/SlimeBlue.cpp
        enemies/SlimeBlue.h
        enemies/SlimeRed.cpp
        enemies/SlimeRed.h
        enemies/SlimeYellow.cpp
        enemies/SlimeYellow.h
        Party/MC.cpp
        Party/MC.h
        Party/Equipment/Shoes.cpp
        Party/Equipment/Shoes.h
        Party/Equipment/Weapon.cpp
        Party/Equipment/Weapon.h
        Party/Equipment/Clothes.cpp
        Party/Equipment/Clothes.h
        GameSpace/Map.cpp
        GameSpace/Map.h
        GameSpace/Game.cpp
        GameSpace/Game.h
        GameSpace/Menu.cpp
        GameSpace/Menu.h
        GameSpace/Menu.h
        GameSpace/GameOver.cpp
        GameSpace/GameOver.h
)
target_link_libraries(Main fmt)
target_link_libraries(Main sfml-system sfml-window sfml-graphics sfml-audio)
