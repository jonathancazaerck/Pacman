cmake_minimum_required(VERSION 3.9)
project(Pacman)

set(CMAKE_CXX_STANDARD 11)

add_executable(Pacman main.cpp Game.cpp Game.h Entity.cpp Entity.h Pacman.cpp Pacman.h Wall.cpp Wall.h Ghost.cpp Ghost.h Player.cpp Player.h AbstractFactory.cpp AbstractFactory.h SDLFactory.cpp SDLFactory.h Bullet.cpp Bullet.h Constants.h Bonus.cpp Bonus.h)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${Pacman_SOURCE_DIR}/cmake")
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIR})
target_link_libraries(Pacman ${SDL2_LIBRARY})