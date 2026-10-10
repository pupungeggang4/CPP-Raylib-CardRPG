#include "game.hpp"

Game game = Game();

Game::Game() {

}

void Game::init() {
    InitWindow(800, 600, "Card RPG");
    running = 1;
}

void Game::loop() {
    BeginDrawing();
    ClearBackground(RAYWHITE);
    DrawText("Card RPG", 20, 20, 20, BLACK);
    EndDrawing();

    #ifdef __EMSCRIPTEN__
    if (running == 0) {
        emscripten_cancel_main_loop();
    }
    #else
    if (WindowShouldClose()) running = 0;
    #endif
}
