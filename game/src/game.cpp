#include "game.hpp"

Game game = Game();

Game::Game() {

}

void Game::init() {
    #ifdef __EMSCRIPTEN__
    InitWindow(800, 600, "Card RPG");
    #else
    SetConfigFlags(FLAG_WINDOW_HIGHDPI);
    InitWindow(800, 600, "Card RPG");
    #ifndef __APPLE__
    Vector2 dpiScale  = GetWindowScaleDPI();
    width = (int)(800 * dpiScale.x);
    height = (int)(600 * dpiScale.y);
    SetWindowSize(width, height);
    #endif
    SetExitKey(KEY_NULL);
    #endif
    running = 1;
    camera.zoom = GetRenderWidth() / 800.0f;
}

void Game::loop() {
    camera.zoom = GetRenderWidth() / 800.0f;

    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
        #ifdef __EMSCRIPTEN__
        Vector2 pos = GetScreenToWorld2D(GetMousePosition(), camera);
        #else
        Vector2 pos = GetScreenToWorld2D(Vector2Scale(GetMousePosition(), GetWindowScaleDPI().x), camera);
        #endif
        printf("(%.0f, %.0f)\n", pos.x, pos.y);
    }

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
