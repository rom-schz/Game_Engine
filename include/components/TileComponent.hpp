#ifndef TileComponent_hpp
#define TileComponent_hpp

#include "ECS.hpp"
#include "TransformComponent.hpp"
#include "SpriteComponent.hpp"
#include "SDL.h"

class TileComponent : public Component {
public:
    TransformComponent *transform;
    SpriteComponent *sprite;

    SDL_Rect tileRect, texRect;
    int tileId;
    const char* path;

    TileComponent() = default;

    TileComponent(int x, int y, int w, int h, int id) {
        tileRect.x = x;
        tileRect.y = y;
        tileRect.w = w;
        tileRect.h = h;

        texRect.x = 0; texRect.y = 0;
        texRect.w = 16; texRect.h = 16;

        tileId = id;

        switch (tileId) {
            case 0:
                path = "assets/MiniWorldSprites/Ground/Shore.png";
                texRect.x = 48;
                break;
            case 1:
                path = "assets/MiniWorldSprites/Ground/Shore.png";
                break;
            case 2:
                path = "assets/MiniWorldSprites/Ground/TexturedGrass.png";
                break;
            default:
                break;
        }
    }

    void init() override {
        entity->addComponent<TransformComponent>(tileRect.x, tileRect.y, tileRect.w, tileRect.h, 1);
        transform = &entity->getComponent<TransformComponent>();
        entity->addComponent<SpriteComponent>(path, texRect);
        sprite = &entity->getComponent<SpriteComponent>();
    }
};

#endif