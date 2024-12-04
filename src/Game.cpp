#include "Game.hpp"

#include <iostream>

Game::Game(int width, int height, const char *title)
    : screenWidth(width), screenHeight(height), windowTitle(title) {
  InitWindow(screenWidth, screenHeight, title);
  SetTargetFPS(60);
}

Game::~Game() { CloseWindow(); }

void Game::run() {
  while (!WindowShouldClose()) {
    if (!states.empty()) {
      states.top()->handleInputs();
      states.top()->update(GetFrameTime());
      BeginDrawing();
      ClearBackground(BLACK);
      states.top()->render();
      EndDrawing();
    } else {
      // Caso a pilha esteja vazia, pode-se encerrar o jogo:
      std::cout << "A pilha esta vazia. Encerrando o jogo." << std::endl;
      break;
    }
  }
}

void Game::changeState(std::unique_ptr<State> newState) {
  if (!states.empty()) {
    states.pop();
  }
  states.push(std::move(newState));
}

void Game::pushState(std::unique_ptr<State> state) {
  states.push(std::move(state));
}

void Game::popState() {
  if (!states.empty()) {
    states.pop();
  } else {
    std::cerr << "A pilha de estados esta vazia, impossivel desempilhar."
              << std::endl;
  }
}

