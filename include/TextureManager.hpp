#ifndef TextureManager_h
#define TextureManager_h

#include "SDL.h"

class TextureManager {

public:
    static SDL_Texture* LoadTexture(const char* fileName);
    static void Draw(SDL_Texture* tex, SDL_Rect src, SDL_Rect dst);
};

#endif