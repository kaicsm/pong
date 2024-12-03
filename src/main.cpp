#include "Game.hpp"

#include "states/HomeState.hpp"

int main() {
  Game game(640, 480, "Pong");

  game.changeState(std::make_unique<HomeState>(game));
  game.run();

  return 0;
}
