#pragma once

#include <raylib.h>

class Ball {
public:
    Ball(Vector2 startPosition, Vector2 startVelocity, float radius);

    void move(float deltatime);
    void collideWith(const Rectangle& other);
    void reset(Vector2 newPosition);

    Vector2 getPosition() const { return position; };
    Vector2 getVelocity() const { return velocity; };

    float getRadius() const { return radius; };

private:
    Vector2 position;
    Vector2 velocity;

    float radius;

};
