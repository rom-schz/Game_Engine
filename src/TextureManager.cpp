#include "SDL.h"
#include "SDL_image.h"
#include "Game.hpp"
#include "TextureManager.hpp"

SDL_Texture* TextureManager::LoadTexture(const char* fileName, SDL_Renderer* renderer) {
    SDL_Surface* tempSurface = IMG_Load(fileName);
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, tempSurface);
    SDL_FreeSurface(tempSurface);

    return texture;
}