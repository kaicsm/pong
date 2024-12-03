#include "objects/Paddle.hpp"

Paddle::Paddle(Rectangle bounds, float speed) : bounds(bounds), speed(speed) {}

void Paddle::move(float deltaTime) {
    bounds.y += speed * deltaTime;
}