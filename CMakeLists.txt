cmake_minimum_required(VERSION 3.9)
project(Pacman)

set(CMAKE_CXX_STANDARD 11)

add_executable(Pacman main.cpp Game.cpp Game.h Entity.cpp Entity.h Pacman.cpp Pacman.h Wall.cpp Wall.h Ghost.cpp Ghost.h Player.cpp Player.h AbstractFactory.cpp AbstractFactory.h SDLFactory.cpp SDLFactory.h Bullet.cpp Bullet.h Constants.h Bonus.cpp Bonus.h JsonReader.cpp JsonReader.h Coordinate.cpp Coordinate.h SDLTextureManager.cpp SDLTextureManager.h SDLPacman.cpp SDLPacman.h SDLWall.cpp SDLWall.h SDLGhost.cpp SDLGhost.h SDLBullet.cpp SDLBullet.h SDLBonus.cpp SDLBonus.h SDLKeyboardController.cpp SDLKeyboardController.h Score.cpp Score.h SDLScore.cpp SDLScore.h)



set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${Pacman_SOURCE_DIR}/cmake")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")
find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
include_directories(${SDL2_INCLUDE_DIR} nlohmann ${SDL2_IMAGE_INCLUDE_DIRS})
target_link_libraries(Pacman ${SDL2_LIBRARY} ${SDL2_IMAGE_LIBRARIES})
