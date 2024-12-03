#include "objects/Ball.hpp"

Ball::Ball(Vector2 startPosition, Vector2 startVelocity, float radius) 
    : position(startPosition), velocity(startVelocity), radius(radius) {}

void Ball::move(float deltaTime) {
    position.x += velocity.x * deltaTime;
    position.y += velocity.y * deltaTime;
}

void Ball::collideWith(const Rectangle& other) {
    if (CheckCollisionCircleRec(position, radius, other)) {
        // Determina o lado em que a colisão ocorreu
        if (position.x < other.x || position.x > other.x + other.width) {
            // Colisão no lado esquerdo ou direito
            velocity.x = -velocity.x;

            // Corrige posição para fora do retângulo no eixo X
            if (position.x < other.x) {
                position.x = other.x - radius;
            } else {
                position.x = other.x + other.width + radius;
            }
        }

        if (position.y < other.y || position.y > other.y + other.height) {
            // Colisão no topo ou na base
            velocity.y = -velocity.y;

            // Corrige posição para fora do retângulo no eixo Y
            if (position.y < other.y) {
                position.y = other.y - radius;
            } else {
                position.y = other.y + other.height + radius;
            }
        }
    }
}


void Ball::reset(Vector2 newPosition) {
    position = newPosition;
}