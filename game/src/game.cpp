#include "game.hpp"
#include "scene.hpp"

Game game = Game();

Game::Game() {

}

void Game::init() {
    #ifdef __EMSCRIPTEN__
    InitWindow(logicWidth, logicHeight, "Card RPG");
    #else
    SetConfigFlags(FLAG_WINDOW_HIGHDPI);
    SetConfigFlags(FLAG_VSYNC_HINT);
    InitWindow(logicWidth, logicHeight, "Card RPG");
    #ifndef __APPLE__
    Vector2 dpiScale  = GetWindowScaleDPI();
    width = (int)(logicWidth * dpiScale.x);
    height = (int)(logicHeight * dpiScale.y);
    SetWindowSize(width, height);
    #endif
    SetExitKey(KEY_NULL);
    #endif
    running = 1;
    scale = (float)GetRenderWidth() / logicWidth;

    scenes = {};
    scenes.emplace(TITLE, make_shared<SceneTitle>());
    scene = scenes[TITLE];
    scene->ready(*this);
}

void Game::loop() {
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
        Vector2 pos = GetMousePosition();
        printf("(%.0f, %.0f)\n", pos.x, pos.y);
    }

    scene->update(*this);

    BeginDrawing();
    ClearBackground(RAYWHITE);
    scene->render(*this);
    EndDrawing();

    #ifdef __EMSCRIPTEN__
    if (running == 0) {
        emscripten_cancel_main_loop();
    }
    #else
    if (WindowShouldClose()) running = 0;
    #endif
}
