#ifndef Collision_hpp
#define Collision_hpp

#include "SDL.h"

class Collision {
public:
    // Collision with axis aligned bounding boxes
    static bool AABB(const SDL_Rect& rectA, const SDL_Rect& rectB);

private:
};

#endif