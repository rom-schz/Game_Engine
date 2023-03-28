#include "GameObject.hpp"
#include "TextureManager.hpp"

GameObject::GameObject(const char* textureSheet, SDL_Renderer* renderer) {
    this->renderer = renderer;
    objTexture = TextureManager::LoadTexture(textureSheet, renderer);

    xpos = ypos = 0;

    srcRect.x = srcRect.y = 0;
    srcRect.h = srcRect.w = 16;

    dstRect.x = dstRect.y = 0;
    dstRect.h = dstRect.w = 32;
}

GameObject::~GameObject() {}

void GameObject::update() {
    xpos += 1;
    dstRect.x = 2 * xpos; dstRect.y = 2*ypos;
}   

void GameObject::render() {
    SDL_RenderCopy(renderer, objTexture, &srcRect, &dstRect);
}