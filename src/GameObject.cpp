#include "GameObject.hpp"
#include "TextureManager.hpp"

GameObject::GameObject(const char* textureSheet) {
    objTexture = TextureManager::LoadTexture(textureSheet);

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
    SDL_RenderCopy(Game::renderer, objTexture, &srcRect, &dstRect);
}
