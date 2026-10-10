#include "game.hpp"

Game game;

Game::Game() {
    #ifdef __EMSCRIPTEN__
    InitWindow(800, 600, "Card RPG");
    #else
    #endif
}

void Game::loop() {
}
