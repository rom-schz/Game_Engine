#ifndef Collision_hpp
#define Collision_hpp

#include "SDL.h"

class ColliderComponent;

class Collision {
public:
    // Collision with axis aligned bounding boxes
    static bool AABB(const SDL_Rect& rectA, const SDL_Rect& rectB);
    static bool AABB(const ColliderComponent& colA, const ColliderComponent& colB);

private:
};

#endif