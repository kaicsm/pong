#pragma once

#include "../State.hpp"
#include "../Game.hpp"

#include "PongState.hpp"

#include <iostream>

class HomeState : public State {
public:
    HomeState(Game& game);

    void handleInputs() override;
    void update(float deltaTime) override;
    void render() override;
private:
    Game& game;
};