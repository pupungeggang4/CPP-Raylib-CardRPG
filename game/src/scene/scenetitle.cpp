#include "scene.hpp"

#include "ui.hpp"
#include "util.hpp"
#include "render.hpp"

#include "game.hpp"

SceneTitle::SceneTitle() {
}

void SceneTitle::ready(Game& game) {
}

void SceneTitle::update(Game& game) {
}

void SceneTitle::render(Game& game) {
    Render::drawText("PlanterGuy CardRPG", UI::UITitle["text_title"]);
    Render::drawText("Start Game", UI::UITitle["text_start"]);
    Render::drawText("Erase Data", UI::UITitle["text_erase"]);
    Render::drawText("Quit Game", UI::UITitle["text_quit"]);
}
