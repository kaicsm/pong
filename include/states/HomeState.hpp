#pragma once

#include "../Game.hpp"
#include "../State.hpp"

class HomeState : public State {
public:
  HomeState(Game &game);

  void handleInputs() override;
  void update(float deltaTime) override;
  void render() override;

private:
  Game &game;
};
