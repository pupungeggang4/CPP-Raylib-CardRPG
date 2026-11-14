#include "game.hpp"
#include "scene.hpp"
#include "asset.hpp"
#include "field.hpp"

#include "battle/battle.hpp"

Game game = Game();

Game::Game() {

}

void Game::init() {
    #ifdef __EMSCRIPTEN__
    InitWindow(logicWidth, logicHeight, "Card RPG");
    #else
    float aspRatio = 0.75;
    SetConfigFlags(FLAG_VSYNC_HINT);
    int width = 800, height = 600;
    InitWindow(width, height, "Puzzle Game");
    #ifndef __APPLE__
    int mWidth = GetMonitorWidth(0); int mHeight = GetMonitorHeight(0);
    if (mWidth * aspRatio > height) {
        height = (int)(mHeight * 0.8); width = (int)(height / aspRatio);
    } else {
        width = (int)(mWidth * 0.8); height = (int)(width * aspRatio);
    }
    SetWindowSize(width, height);
    SetWindowPosition((mWidth - width) / 2, (mHeight - height) / 2);
    #endif
    SetExitKey(KEY_GRAVE);
    #endif
    running = 1;
    keyPressed = {false, false, false, false};

    Asset::assetLoad();
    FieldData::loadFieldData();

    field = make_shared<Field>();
    field->place = HOME_TOWN;
    field->loadField(HOME_TOWN);
    battle = make_shared<Battle>();

    scenes = {};
    scenes.emplace(TITLE, make_shared<SceneTitle>());
    scenes.emplace(FIELD, make_shared<SceneField>());
    scenes.emplace(BATTLE, make_shared<SceneBattle>());
    scene = scenes[TITLE];
    scene->ready(*this);
}

void Game::loop() {
    camera.zoom = (float)GetRenderWidth() / logicWidth;
    dt = GetFrameTime();

    handleInput();
    scene->update(*this);

    BeginDrawing();
    BeginMode2D(camera);
    ClearBackground(RAYWHITE);
    scene->render(*this);
    EndMode2D();
    EndDrawing();

    if (queueSceneChange != -1) {
        try {
            scene = scenes[queueSceneChange];
            scene->ready(*this);
            queueSceneChange = -1;
        } catch (...) {
            running = 0;
        }
    }

    #ifdef __EMSCRIPTEN__
    if (running == 0) {
        emscripten_cancel_main_loop();
    }
    #else
    if (WindowShouldClose()) running = 0;
    #endif
}

void Game::handleInput() {
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
        Vector2 pos = Vector2Scale(GetMousePosition(), 1 / camera.zoom);
        printf("(%.0f, %.0f)\n", pos.x, pos.y);
        scene->mouseUp(*this, pos);
    }

    if (IsKeyPressed(KEY_LEFT) || IsKeyPressed(KEY_A)) keyPressed[LEFT] = true;
    if (IsKeyPressed(KEY_RIGHT) || IsKeyPressed(KEY_D)) keyPressed[RIGHT] = true;
    if (IsKeyPressed(KEY_UP) || IsKeyPressed(KEY_W)) keyPressed[UP] = true;
    if (IsKeyPressed(KEY_DOWN) || IsKeyPressed(KEY_S)) keyPressed[DOWN] = true;
    if (IsKeyReleased(KEY_LEFT) || IsKeyReleased(KEY_A)) keyPressed[LEFT] = false;
    if (IsKeyReleased(KEY_RIGHT) || IsKeyReleased(KEY_D)) keyPressed[RIGHT] = false;
    if (IsKeyReleased(KEY_UP) || IsKeyReleased(KEY_W)) keyPressed[UP] = false;
    if (IsKeyReleased(KEY_DOWN) || IsKeyReleased(KEY_S)) keyPressed[DOWN] = false;

    scene->keyDown(*this);
}

void Game::changeSceneTo(int target) {
    queueSceneChange = target;
}
