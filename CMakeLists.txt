cmake_minimum_required(VERSION 3.15)

project(game_engine
        VERSION 1.0
        DESCRIPTION "A game engine made from a tutorial on youtube, just to learn."
        LANGUAGES CXX)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})


add_subdirectory(src)

#add_subdirectory(test)

add_subdirectory(apps)