#ifndef TransformComponent_hpp
#define TransformComponent_hpp

#include "Components.hpp"
#include "Vector2D.hpp"

class TransformComponent : public Component {
public:
    int height = 16;
    int width = 16;
    int scale = 1;

    Vector2D position;
    Vector2D velocity;

    float speed = 4;

    TransformComponent() {
        position.zero();
    }

    TransformComponent(int sc) {
        position.x = 400;
        position.y = 320;
        scale = sc;
    }

    TransformComponent(float x, float y, int h=32, int w=32, int sc=1) {
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
        position.x += static_cast<int>(velocity.x * speed);
        position.y += static_cast<int>(velocity.y * speed);
    }

private:


};

#endif