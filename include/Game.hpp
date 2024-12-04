#pragma once

#include "State.hpp"
#include <memory>
#include <stack>

class Game {
public:
  Game(int width, int height, const char *title);
  ~Game();

  void run();

  void changeState(std::unique_ptr<State> newState);
  void pushState(std::unique_ptr<State> state);
  void popState();

private:
  std::stack<std::unique_ptr<State>> states;
  int screenWidth, screenHeight;
  const char *windowTitle;
};
