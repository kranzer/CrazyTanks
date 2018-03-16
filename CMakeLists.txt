cmake_minimum_required(VERSION 3.8)
project(CrazyTanks)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp World.cpp World.h Entity.cpp Entity.h)
add_executable(CrazyTanks ${SOURCE_FILES})