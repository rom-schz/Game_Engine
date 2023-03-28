#ifndef Map_h
#define Map_h

#include "SDL.h"
#include "Game.hpp"

class Map {

public:
    Map();
    ~Map();

    void LoadMap(int arr[20][25]);
    void render();

private:
    SDL_Rect srcRect, dstRect;
    SDL_Texture *sand, *grass, *water;

    int map[20][25];

};

#endif