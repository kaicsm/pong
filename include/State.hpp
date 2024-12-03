#pragma once

#include <raylib.h>

class State {
public:
  virtual ~State() = default;

  virtual void handleInputs() = 0;
  virtual void update(float deltaTime) = 0;
  virtual void render() = 0;
};
