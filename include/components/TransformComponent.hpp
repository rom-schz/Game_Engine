#ifndef TransformComponent_hpp
#define TransformComponent_hpp

#include "Components.hpp"
#include "Vector2D.hpp"

class TransformComponent : public Component {
public:

    Vector2D position;

    TransformComponent() {
        TransformComponent(0.0f, 0.0f);
    }

    TransformComponent(float x, float y) {
        position.x = x;
        position.y = y;
    }

    void init() override {
        position.x = 0;
        position.y = 0;
    }

    void update() override {
    }

    void setPos(int x, int y) {
        position.x = x;
        position.y = y;
    }

};

#endif