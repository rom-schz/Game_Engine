#ifndef Game_hpp
#define Game_hpp

#include <vector>

#include "SDL.h"
#include "SDL_image.h"

class AssetManager;
class ColliderComponent;

class Game {

public:
    Game();
    ~Game();

    void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);

    void handleEvents();
    void update();
    void render();
    void clean();

    bool running();

    static SDL_Renderer *renderer;
    static SDL_Event event;
    static bool isRunning;
    static SDL_Rect camera;
    static AssetManager* assets;

    enum groupLabels : std::size_t {
        groupMap,
        groupPlayers,
        groupColliders
    };

private:
    SDL_Window *window;

};

#endif