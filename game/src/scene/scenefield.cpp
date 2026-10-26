#include "scene.hpp"

#include "ui.hpp"
#include "util.hpp"
#include "render.hpp"

#include "game.hpp"

SceneField::SceneField() {
}

void SceneField::ready(Game& game) {
}

void SceneField::update(Game& game) {
}

void SceneField::render(Game& game) {
    Render::drawRect(UI::UIField["button_menu"], BLUE);
}

void SceneField::mouseUp(Game& game, Vector2 pos) {
}

