#include "states/HomeState.hpp"

#include "states/PongState.hpp"

HomeState::HomeState(Game &game) : game(game) {}

void HomeState::handleInputs() {
  if (IsKeyPressed(KEY_ENTER)) {
    game.changeState(std::make_unique<PongState>(game));
  }
}

void HomeState::update(float deltaTime) {}

void HomeState::render() {
  // Texto "Pong"
  int textWidth1 = MeasureText("Pong", 30);
  int x1 = (GetScreenWidth() - textWidth1) / 2;
  int y1 = GetScreenHeight() / 2 - 15;
  DrawText("Pong", x1, y1, 30, WHITE);

  // Texto "Press enter to start"
  int textWidth2 = MeasureText("Press enter to start", 20);
  int x2 = (GetScreenWidth() - textWidth2) / 2;
  int y2 = y1 + 40;
  DrawText("Press enter to start", x2, y2, 20, WHITE);
}
