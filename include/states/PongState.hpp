#pragma once

#include "../State.hpp"
#include "../Game.hpp"

#include "HomeState.hpp"

#include "../objects/Ball.hpp"
#include "../objects/Paddle.hpp"

class PongState : public State {
public:
    PongState(Game& game);

    void handleInputs() override;
    void update(float deltaTime) override;
    void render() override;

private:
    Game& game;
    Ball ball;
    Paddle paddle1;
    Paddle paddle2;
};