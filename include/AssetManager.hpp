#ifndef AssetManager_hpp
#define AssetManager_hpp

#include <map>
#include <string>

#include "TextureManager.hpp"
#include "Vector2D.hpp"
#include "ECS.hpp"

class AssetManager {

public:
    AssetManager(Manager* manager);
    ~AssetManager();

    void addTexture(std::string id, const char *path);
    SDL_Texture* getTexture(std::string id);

private:
    Manager *manager;

    std::map<std::string, SDL_Texture*> textures;

};

#endif