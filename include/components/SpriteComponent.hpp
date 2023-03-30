#ifndef SpriteComponent_hpp
#define SpriteComponent_hpp

#include <map>

#include "Components.hpp"
#include "TextureManager.hpp"
#include "SDL.h"
#include "Animation.hpp"

class SpriteComponent : public Component {

public:

    int animIndex = 0;

    std::map<const char*, Animation> animations;

    SpriteComponent() = default;

    SpriteComponent(const char* path) {
        setTex(path);
        srcRect.x = srcRect.y = 0;
        srcRect.w = srcRect.h = 0;
    }

    SpriteComponent(const char* path, bool isAnimated) {
        setTex(path);
        animated = isAnimated;

        if(animated) {
            Animation idle = Animation(0, 2, 200);
            Animation walkDown = Animation(0, 5, 200);
            Animation walkUp = Animation(1, 5, 200);
            Animation walkRight = Animation(2, 5, 200);
            Animation walkLeft = Animation(3, 5, 200);

            animations.emplace("Idle", idle);
            animations.emplace("Walk down", walkDown);
            animations.emplace("Walk up", walkUp);
            animations.emplace("Walk right", walkRight);
            animations.emplace("Walk left", walkLeft);

            play("Idle");
        }
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
    }

    void update() override {
        if(animated) {
            srcRect.x = srcRect.w * static_cast<int>((SDL_GetTicks() / speed) % frames);
        }

        srcRect.y = animIndex * transform->height;

        dstRect.x = static_cast<int>(transform->position.x);
        dstRect.y = static_cast<int>(transform->position.y);
        dstRect.w = static_cast<int>(transform->width * transform->scale);
        dstRect.h = static_cast<int>(transform->height * transform->scale);
    }

    void draw() override {
        TextureManager::Draw(texture, srcRect, dstRect);
    }

    void play(const char *animName) {
        frames = animations[animName].frames;
        animIndex = animations[animName].index;
        speed = animations[animName].speed;
    }

private:
    TransformComponent *transform;
    SDL_Texture *texture;

    SDL_Rect srcRect, dstRect;

    bool animated = false;
    int frames = 0;
    int speed = 100;

};

#endif