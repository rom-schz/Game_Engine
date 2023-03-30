#ifndef ColliderComponent_hpp
#define ColliderComponent_hpp

#include <string>
#include "SDL.h"
#include "ECS.hpp"
#include "Components.hpp"
#include "TextureManager.hpp"

class ColliderComponent : public Component {

public:
    SDL_Rect collider;
    std::string tag;

    SDL_Texture *tex;
    SDL_Rect srcRect, dstRect;

    TransformComponent *transform;

    ColliderComponent(std::string t) {
        tag = t;
    }

    ColliderComponent(std::string t, int xpos, int ypos, int size) {
        tag = t;
        collider.x = xpos;
        collider.y = ypos;
        collider.h = collider.w = size;
    }

    void init() override {
        if(!entity->hasComponent<TransformComponent>()) {
            entity->addComponent<TransformComponent>();
        }

        transform = &entity->getComponent<TransformComponent>();

        tex = TextureManager::LoadTexture("assets/collider.png");
        srcRect = { 0, 0, 32, 32};
        dstRect = { collider.x, collider.y, collider.w, collider.h };
    }

    void update() override {
        if(tag != "terrain") {
            collider.x = static_cast<int>(transform->position.x);
            collider.y = static_cast<int>(transform->position.y);
            collider.w = transform->width * transform->scale;
            collider.h = transform->height * transform->scale;
        }

        dstRect.x = collider.x - Game::camera.x;
        dstRect.y = collider.y - Game::camera.y;
    }

    void draw() override {
        TextureManager::Draw(tex, srcRect, dstRect);
    }


};

#endif