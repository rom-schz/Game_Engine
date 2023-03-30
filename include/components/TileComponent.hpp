#ifndef TileComponent_hpp
#define TileComponent_hpp

#include "ECS.hpp"
#include "TransformComponent.hpp"
#include "SpriteComponent.hpp"
#include "SDL.h"

class TileComponent : public Component {
public:

    SDL_Texture *texture;
    SDL_Rect srcRect, dstRect;
    Vector2D position;

    TileComponent() = default;

    TileComponent(int srcX, int srcY, int xpos, int ypos, int tsize, int tscale, const char *path) {
        texture = TextureManager::LoadTexture(path);

        position.x = xpos;
        position.y = ypos;

        srcRect.x = srcX; srcRect.y = srcY;
        srcRect.w = srcRect.h = tsize;

        dstRect.x = xpos; dstRect.y = ypos;
        dstRect.w = dstRect.h = tsize * tscale;
    }

    ~TileComponent() {
        SDL_DestroyTexture(texture);
    }

    void update() override {
        dstRect.x = position.x - Game::camera.x;
        dstRect.y = position.y - Game::camera.y;
    }

    void draw() override {
        TextureManager::Draw(texture, srcRect, dstRect);
    }
};

#endif