#ifndef TransformComponent_hpp
#define TransformComponent_hpp

#include "Components.hpp"
#include "Vector2D.hpp"

class TransformComponent : public Component {
public:

    Vector2D position;
    Vector2D velocity;

    float speed = 3;

    TransformComponent() {
        TransformComponent(0.0f, 0.0f);
    }

    TransformComponent(float x, float y) {
        position.x = x;
        position.y = y;
    }

    void init() override {
        velocity.x = velocity.y = 0;
    }

    void update() override {
        position.x += velocity.x * speed;
        position.y += velocity.y * speed;
    }

};

#endif