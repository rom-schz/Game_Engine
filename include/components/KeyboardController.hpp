#ifndef KeyboardController_hpp
#define KeyboardController_hpp

#include "Game.hpp"
#include "Components.hpp"
#include "ECS.hpp"

class KeyboardController : public Component {
public:
    TransformComponent *transform;
    SpriteComponent *sprite;

    void init() override {
        transform = &entity->getComponent<TransformComponent>();
        sprite = &entity->getComponent<SpriteComponent>();
    }

    void update() override {
        if(Game::event.type == SDL_KEYDOWN) {
            switch(Game::event.key.keysym.sym) {
                case SDLK_z:
                    transform->velocity.y = -1;
                    sprite->play("Walk up");
                    break;
                case SDLK_q:
                    transform->velocity.x = -1;
                    sprite->play("Walk left");
                    break;
                case SDLK_s:
                    transform->velocity.y = 1;
                    sprite->play("Walk down");
                    break;
                case SDLK_d:
                    transform->velocity.x = 1;
                    sprite->play("Walk right");
                    break;
                default:
                    sprite->play("Idle");
                    break;
            }
        }

        if(Game::event.type == SDL_KEYUP) {
            switch(Game::event.key.keysym.sym) {
                case SDLK_z:
                    transform->velocity.y = 0;
                    break;
                case SDLK_q:
                    transform->velocity.x = 0;
                    break;
                case SDLK_s:
                    transform->velocity.y = 0;
                    break;
                case SDLK_d:
                    transform->velocity.x = 0;
                    break;
                default:
                    break;
            }
        }
    }

private:

};

#endif
