#ifndef SpriteComponent_hpp
#define SpriteComponent_hpp

#include "Components.hpp"
#include "TextureManager.hpp"
#include "SDL.h"

class SpriteComponent : public Component {

public:
    SpriteComponent() = default;
    SpriteComponent(const char* path) {
        setTex(path);
    }

    void setTex(const char* path) {
        texture = TextureManager::LoadTexture(path);
    }

    void init() override {
        transform = &entity->getComponent<TransformComponent>();

        srcRect.x = srcRect.y = 0;
        srcRect.w = srcRect.h = 16;

        dstRect.x = dstRect.y = 0;
        dstRect.w = dstRect.h = 32;

    }

    void update() override {
        dstRect.x = (int)transform->position.x;
        dstRect.y = (int)transform->position.y;
    }

    void draw() override {
        TextureManager::Draw(texture, srcRect, dstRect);
    }

private:
    TransformComponent *transform;
    SDL_Texture *texture;

    SDL_Rect srcRect, dstRect;

};

#endif