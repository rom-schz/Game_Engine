#include <vector>

#include "Game.hpp"
#include "TextureManager.hpp"
#include "GameObject.hpp"
#include "Map.hpp"
#include "ECS.hpp"
#include "Components.hpp"
#include "Vector2D.hpp"
#include "Collision.hpp"


SDL_Renderer* Game::renderer = nullptr;
SDL_Event Game::event;
bool Game::isRunning = false;
SDL_Rect Game::camera = {0, 0, 800, 640}; 

Map* map;

Manager manager;
auto& player(manager.addEntity());


Game::Game() {}

Game::~Game() {}

void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen) {
    int flags = 0;
    if(fullscreen) flags = SDL_WINDOW_FULLSCREEN;

    if(SDL_Init(SDL_INIT_EVERYTHING) == 0) {
        window = SDL_CreateWindow(title, xpos, ypos, width, height, flags | SDL_WINDOW_SHOWN);

        if(window) {
            renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

            if(renderer)
                isRunning = true;
        }
    } else {
        isRunning = false;
    }

    map = new Map("assets/Map/terrain_ss.png", 2, 32);
    map->LoadMap("assets/Map/map.map", 25, 20);

    player.addComponent<TransformComponent>(4);
    player.addComponent<SpriteComponent>("assets/MiniWorldSprites/Characters/Workers/FarmerTemplate.png", true);
    player.addComponent<KeyboardController>();
    player.addComponent<ColliderComponent>("player");
    player.addGroup(groupPlayers);
}

auto& tiles(manager.getGroup(Game::groupMap));
auto& players(manager.getGroup(Game::groupPlayers));
auto& colliders(manager.getGroup(Game::groupColliders));

void Game::handleEvents() {
    SDL_PollEvent(&event);

    switch(event.type) {
        case SDL_QUIT:
            isRunning = false;
            break;
        default:
            break;
    }
}

void Game::update() {
    SDL_Rect playerCollider = player.getComponent<ColliderComponent>().collider;
    Vector2D playerPosition = player.getComponent<TransformComponent>().position;

    manager.refresh();
    manager.update();

    for (auto& c : colliders) {
        SDL_Rect cCollider = c->getComponent<ColliderComponent>().collider;
        if(Collision::AABB(cCollider, playerCollider)) {
            player.getComponent<TransformComponent>().position = playerPosition;
        }
    }

    camera.x = player.getComponent<TransformComponent>().position.x - 400;
    camera.y = player.getComponent<TransformComponent>().position.y - 320;

    if(camera.x < 0)
        camera.x = 0;
    if(camera.x > camera.w)
        camera.x = camera.w;
    if(camera.y < 0)
        camera.y = 0;
    if(camera.y > camera.h)
        camera.y = camera.h;
}

void Game::render() {
    SDL_RenderClear(renderer);
    for (auto& t : tiles) t->draw();
    for (auto& c : colliders) c->draw();
    for (auto& p : players) p->draw();
    SDL_RenderPresent(renderer);
}

bool Game::running() {
    return isRunning;
}

void Game::clean() {
    if(renderer) SDL_DestroyRenderer(renderer);
    if(window) SDL_DestroyWindow(window);
    SDL_Quit();
}
