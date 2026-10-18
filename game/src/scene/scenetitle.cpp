#include "scene.hpp"

#include "game.hpp"

SceneTitle::SceneTitle() {
}

void SceneTitle::ready(Game& game) {
}

void SceneTitle::update(Game& game) {
}

void SceneTitle::render(Game& game) {
    DrawRectangle(40, 40, 40, 40, BLUE);
}
