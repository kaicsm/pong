#pragma once

#include <raylib.h>

class Paddle {
public:
    Paddle(Rectangle bounds, float speed);

    void move(float deltaTime);

    Rectangle bounds;

    float getSpeed() const { return speed; };

    void setSpeed(float newSpeed) { this->speed = newSpeed; };
private:
    float speed;
};