cmake_minimum_required(VERSION 3.8)
project(CrazyTanks)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp World.cpp World.h Entity.cpp Entity.h Wall.cpp Wall.h tank.cpp tank.h Tank.cpp Tank.h Player.cpp Player.h Enemy.cpp Enemy.h Game.cpp Game.h Bullet.cpp Bullet.h)
add_executable(CrazyTanks ${SOURCE_FILES})