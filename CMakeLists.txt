cmake_minimum_required(VERSION 3.15)

project(game_engine
        VERSION 1.0
        DESCRIPTION "A game engine made from a tutorial on youtube, just to learn."
        LANGUAGES CXX)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")


find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS} ${SDL_IMAGE_INCLUDE_DIRS})


add_subdirectory(src)

#add_subdirectory(test)

add_subdirectory(apps)