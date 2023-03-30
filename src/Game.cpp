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

std::vector<ColliderComponent*> Game::colliders;

Map* map;

Manager manager;
auto& player(manager.addEntity());
auto& wall(manager.addEntity());

enum groupLabels : std::size_t {
    groupMap,
    groupPlayers,
    groupEnemies,
    groupColliders
};




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

    Map::LoadMap("assets/Map/map1.map", 16, 16);

    player.addComponent<TransformComponent>();
    player.addComponent<SpriteComponent>("assets/MiniWorldSprites/Characters/Workers/FarmerTemplate.png", 5, 200);
    player.addComponent<KeyboardController>();
    player.addComponent<ColliderComponent>("player");
    player.addGroup(groupPlayers);

    wall.addComponent<TransformComponent>(300.0f, 300.0f, 300, 20, 1);
    wall.addComponent<SpriteComponent>("assets/MiniWorldSprites/Buildings/Wood/Tower.png");
    wall.addComponent<ColliderComponent>("wall");
    wall.addGroup(groupMap);
}

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
    manager.refresh();
    manager.update();

    for (auto cc : colliders) {
        Collision::AABB(player.getComponent<ColliderComponent>(), *cc);
    }
    
}

auto& tiles(manager.getGroup(groupMap));
auto& players(manager.getGroup(groupPlayers));
auto& enemies(manager.getGroup(groupEnemies));
auto& colliders(manager.getGroup(groupColliders));

void Game::render() {
    SDL_RenderClear(renderer);
    for (auto& t : tiles) t->draw();
    for (auto& p : players) p->draw();
    for (auto& e : enemies) e->draw();
    for (auto& c : colliders) c->draw();
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

void Game::addTile(int id, int x, int y) {
    auto& tile(manager.addEntity());
    tile.addComponent<TileComponent>(x, y, 16, 16, id);
    tile.addGroup(groupMap);
}