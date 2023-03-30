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

    TileComponent() = default;

    TileComponent(int srcX, int srcY, int xpos, int ypos, const char *path) {
        texture = TextureManager::LoadTexture(path);

        srcRect.x = srcX; srcRect.y = srcY;
        srcRect.w = srcRect.h = 32;

        dstRect.x = xpos; dstRect.y = ypos;
        dstRect.w = dstRect.h = 64;
    }

    ~TileComponent() {
        SDL_DestroyTexture(texture);
    }

    void draw() override {
        TextureManager::Draw(texture, srcRect, dstRect);
    }
};

#endif