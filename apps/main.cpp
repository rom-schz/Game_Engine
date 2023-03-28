#include <iostream>
#include "SDL.h"
#include "SDL_image.h"
#include "Game.hpp"

Game *game = nullptr;

int main(int argc, char** argv)
{
    const int FPS = 60;
    const int frameDelay = 1000 / FPS;

    uint64_t frameStart;
    int frameTime;   


    game = new Game();
    game->init("game",SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false);

    while(game->running()) {

        frameStart = SDL_GetTicks64();

        game->handleEvents();
        game->update();
        game->render();

        frameTime = SDL_GetTicks64() - frameStart;

        if(frameTime < frameDelay) SDL_Delay(frameDelay - frameTime);
    }

    game->clean();

    return EXIT_SUCCESS;
}