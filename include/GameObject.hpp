#ifndef GameObject_h
#define GameObject_h

#include "Game.hpp"

class GameObject {

public:
    GameObject(const char* textureSheet, SDL_Renderer* renderer);
    ~GameObject();

    void update();
    void render();

private:
    int xpos;
    int ypos;

    SDL_Texture* objTexture;
    SDL_Rect srcRect, dstRect;
    SDL_Renderer* renderer;

};

#endif