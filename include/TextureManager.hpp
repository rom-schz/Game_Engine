#ifndef TextureManager_h
#define TextureManager_h

#include "SDL.h"

class TextureManager {

public:
    static SDL_Texture* LoadTexture(const char* fileName, SDL_Renderer* renderer);
};

#endif