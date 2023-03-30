#include "AssetManager.hpp"
#include "TextureManager.hpp"
#include "Components.hpp"
#include "Game.hpp"

AssetManager::AssetManager(Manager *manager) : manager(manager) {}

AssetManager::~AssetManager() {}

void AssetManager::createProjectile(Vector2D pos, Vector2D vel, int range, int speed, std::string texID) {
    auto& projectile(manager->addEntity());
    projectile.addComponent<TransformComponent>(pos.x, pos.y, 32, 32, 1);
    projectile.addComponent<SpriteComponent>(texID, false);
    projectile.addComponent<ProjectileComponent>(range, speed, vel);
    projectile.addComponent<ColliderComponent>("projectile");
    projectile.addGroup(Game::groupProjectiles);
}

void AssetManager::addTexture(std::string id, const char *path) {
    textures.emplace(id, TextureManager::LoadTexture(path));
}

SDL_Texture* AssetManager::getTexture(std::string id) {
    return textures[id];
}