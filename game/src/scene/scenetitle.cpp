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
    Render::drawRect(UI::UITitle["button_start"], YELLOW);
    Render::drawText("Start Game", UI::UITitle["text_start"]);
    Render::drawRect(UI::UITitle["button_erase"], PINK);
    Render::drawText("Erase Data", UI::UITitle["text_erase"]);
    Render::drawRect(UI::UITitle["button_quit"], YELLOW);
    Render::drawText("Quit Game", UI::UITitle["text_quit"]);
}

void SceneTitle::mouseUp(Game& game, Vector2 pos) {
    if (Util::pointInsideRectUI(pos, UI::UITitle["button_quit"])) game.running = false;
}

