#include "states/PongState.hpp"

PongState::PongState(Game& game) : game(game), ball(Vector2{200, 200}, Vector2{200, 200}, 10.0f), paddle1(Rectangle{15.0f, static_cast<float>(GetScreenHeight()) / 2.0f - 70.0f / 2, 20.0f, 70.0f}, 0), paddle2(Rectangle{static_cast<float>(GetScreenWidth() - 20.0f - 15.0f), static_cast<float>(GetScreenHeight() / 2.0f - 70.0f / 2), 20, 70}, 0) {}

void PongState::handleInputs() {
    // Paddle 1
    if (IsKeyDown(KEY_W)) {
        paddle1.setSpeed(-200); // Movendo para cima
    } else if (IsKeyDown(KEY_S)) {
        paddle1.setSpeed(200);  // Movendo para baixo
    } else {
        paddle1.setSpeed(0);    // Parado
    }

    // Garantir que Paddle 1 não ultrapasse os limites da tela
    if (paddle1.bounds.y < 0) {
        paddle1.bounds.y = 0; // Corrige posição superior
        paddle1.setSpeed(0);
    }
    if (paddle1.bounds.y + paddle1.bounds.height > GetScreenHeight()) {
        paddle1.bounds.y = GetScreenHeight() - paddle1.bounds.height; // Corrige posição inferior
        paddle1.setSpeed(0);
    }

    // Paddle 2
    if (IsKeyDown(KEY_UP)) {
        paddle2.setSpeed(-200); // Movendo para cima
    } else if (IsKeyDown(KEY_DOWN)) {
        paddle2.setSpeed(200);  // Movendo para baixo
    } else {
        paddle2.setSpeed(0);    // Parado
    }

    // Garantir que Paddle 2 não ultrapasse os limites da tela
    if (paddle2.bounds.y < 0) {
        paddle2.bounds.y = 0; // Corrige posição superior
        paddle2.setSpeed(0);
    }
    if (paddle2.bounds.y + paddle2.bounds.height > GetScreenHeight()) {
        paddle2.bounds.y = GetScreenHeight() - paddle2.bounds.height; // Corrige posição inferior
        paddle2.setSpeed(0);
    }

    // Voltar para a tela Home quando pressionar Esc
    if (IsKeyPressed(KEY_ESCAPE)) {
        game.pushState(std::make_unique<HomeState>(game));
    }
}

void PongState::update(float deltaTime) {
    ball.move(deltaTime);
    paddle1.move(deltaTime);
    paddle2.move(deltaTime);

    Rectangle screenBoundsTop = { 0, 0, static_cast<float>(GetScreenWidth()), 1};
    Rectangle screenBoundsBottom = {0, static_cast<float>(GetScreenHeight()), static_cast<float>(GetScreenWidth()), 1};
    ball.collideWith(screenBoundsTop);
    ball.collideWith(screenBoundsBottom);

    // Checar se a bola saiu horizontalmente
    if (ball.getPosition().x <= 0 || ball.getPosition().x >= GetScreenWidth()) {
        ball.reset(Vector2{(GetScreenWidth() - ball.getRadius()) / 2.0f, (GetScreenHeight() - ball.getRadius()) / 2.0f});
    }

    ball.collideWith(paddle1.bounds);
    ball.collideWith(paddle2.bounds);
}

void PongState::render() {
    DrawCircleV(ball.getPosition(), ball.getRadius(), WHITE);
    DrawRectangleRec(paddle1.bounds, WHITE);
    DrawRectangleRec(paddle2.bounds, WHITE);
}