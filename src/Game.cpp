#include "Game.hpp"
#include "TextureManager.hpp"
#include "GameObject.hpp"
#include "Map.hpp"

#include "ECS.hpp"
#include "Components.hpp"
#include "Vector2D.hpp"


SDL_Renderer* Game::renderer = nullptr;

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

    map = new Map();

    player.addComponent<TransformComponent>();
    player.addComponent<SpriteComponent>("assets/MiniWorldSprites/Characters/Workers/FarmerTemplate.png");
}

void Game::handleEvents() {
    SDL_Event event;
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

    player.getComponent<TransformComponent>().position.add(Vector2D(1, 0));

    if(player.getComponent<TransformComponent>().position.x > 100) {
        player.getComponent<SpriteComponent>().setTex("assets/MiniWorldSprites/Characters/Workers/RedWorker/FarmerRed.png");
    }
}

void Game::render() {
    SDL_RenderClear(renderer);
    map->render();
    manager.draw();
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