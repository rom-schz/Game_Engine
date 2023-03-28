#include "Game.hpp"
#include "TextureManager.hpp"

SDL_Texture *playerTex = nullptr;

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

    playerTex = TextureManager::LoadTexture("assets/MiniWorldSprites/Characters/Workers/FarmerTemplate.png", renderer);

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

void Game::update() {}

void Game::render() {
    SDL_RenderClear(renderer);

    SDL_Rect* rect = new SDL_Rect;
    rect->x=0; rect->y=0; rect->h=16; rect->w=16;
    SDL_RenderCopy(renderer, playerTex, rect, nullptr);
    delete rect;

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