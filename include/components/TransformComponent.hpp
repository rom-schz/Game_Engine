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
        TransformComponent(0.0f, 0.0f, 16, 16, 2);
    }

    TransformComponent(int sc) {
        TransformComponent(0.0f, 0.0f, 16, 16, sc);
    }

    TransformComponent(float x, float y, int h=16, int w=16, int sc=2) {
        position.x = x;
        position.y = y;

        height = h;
        width = w;
        scale = sc;
    }

    void init() override {
        velocity.x = velocity.y = 0;
    }

    void update() override {
        position.x += velocity.x * speed;
        position.y += velocity.y * speed;
    }

private:


};

#endif