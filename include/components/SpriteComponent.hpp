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
        srcRect.x = srcRect.y = 0;
        srcRect.w = srcRect.h = 0;
    }
    SpriteComponent(const char* path, SDL_Rect srcRect) {
        setTex(path);
        this->srcRect = srcRect;
    }

    ~SpriteComponent() {
        SDL_DestroyTexture(texture);
    }

    void setTex(const char* path) {
        texture = TextureManager::LoadTexture(path);
    }

    void init() override {
        transform = &entity->getComponent<TransformComponent>();

        srcRect.w = transform->width;
        srcRect.h = transform->height;

        dstRect.x = dstRect.y = 0;
        dstRect.w = transform->width * transform->scale;
        dstRect.h = transform->height * transform->scale;

    }

    void update() override {
        dstRect.x = static_cast<int>(transform->position.x);
        dstRect.y = static_cast<int>(transform->position.y);
        dstRect.w = static_cast<int>(transform->width * transform->scale);
        dstRect.h = static_cast<int>(transform->height * transform->scale);
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