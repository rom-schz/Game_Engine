#ifndef TransformComponent_hpp
#define TransformComponent_hpp

#include "Components.hpp"
#include "Vector2D.hpp"

class TransformComponent : public Component {
public:
    int height = 16;
    int width = 16;
    int scale = 2;

    Vector2D position;
    Vector2D velocity;

    float speed = 3;

    TransformComponent() {
        position.zero();
    }

    TransformComponent(int sc) {
        position.zero();
        scale = sc;
    }

    TransformComponent(float x, float y, int h=16, int w=16, int sc=2) {
        position.x = x;
        position.y = y;

        height = h;
        width = w;
        scale = sc;
    }

    void init() override {
        velocity.zero();
    }

    void update() override {
        position.x += velocity.x * speed;
        position.y += velocity.y * speed;
    }

private:


};

#endif